#include "CommonInclude.hlsli"
#include "Skinning.hlsli"
#include "MultiLight.hlsli"

//
// Use code full.fx, AutoLuminous.fx
//

#define AUTOLUMINOUS 0

cbuffer Constants: register(b0)
{
	matrix view;
	matrix projection;
    matrix viewToShadow;
    float3 cameraPosition;
};

cbuffer Model : register(b2)
{
	matrix model;
};

struct Material
{
	float3 diffuse;
	float alpha;
	float3 specular;
	float specularPower;
	float3 ambient;
    int sphereOperation;
    int bUseTexture;
    int bUseToon;
    float EdgeSize;
    float4 EdgeColor;
    float4 MaterialToon;
};

cbuffer MaterialConstants : register(b4)
{
    Material Mat;
};

cbuffer LightConstants : register(b5)
{
    float3 SunDirectionWS;
    float3 SunColor;
    float4 ShadowTexelSize;
}
static float3 LightDirection = normalize(SunDirectionWS);

// Per-vertex data used as input to the vertex shader.
struct VertexShaderInput
{
	float3 normal : NORMAL;
	float2 texcoord : TEXTURE;
	uint4 boneID : BONE_ID;
	float4 boneWeight : BONE_WEIGHT;
	float edgeScale : EDGE_SCALE;
    float3 position : POSITION;
};

struct PixelShaderInput
{
    float4 positionHS : SV_POSITION;
    float3 positionWS : POSITION0;
    float3 eyeWS : POSITION1;
    float4 shadowPositionCS : POSITION2;
    float2 texCoord : TEXCOORD0;
    float2 spTex : TEXCOORD1;
    float3 normalWS : NORMAL;
    float4 color : COLOR0;
    float4 emissive : COLOR2;
};

static const int kSphereNone = 0;
static const int kSphereMul = 1;
static const int kSphereAdd = 2;

static float4 MaterialDiffuse = float4(Mat.diffuse, Mat.alpha);
static float3 MaterialAmbient = Mat.diffuse;
static float3 MaterialEmissive = Mat.ambient;
static float3 MaterialSpecular = Mat.specular;
static const float4 MaterialToon = Mat.MaterialToon;
static float3 LightDiffuse = float3(0,0,0);
static float3 LightAmbient = SunColor;
static float3 LightSpecular = SunColor;
#if !AUTOLUMINOUS
static float3 AutoLuminousColor = float3(0, 0, 0);
#else
static bool IsEmission = (100 < Mat.specularPower) && (length(MaterialSpecular) < 0.05);
static float3 AutoLuminousColor = (IsEmission ? MaterialDiffuse.rgb : float3(0, 0, 0));
#endif
static float4 DiffuseColor = MaterialDiffuse * float4(LightDiffuse, 1.0);
static float3 AmbientColor = saturate(MaterialAmbient * LightAmbient + MaterialEmissive + AutoLuminousColor);
static float3 SpecularColor = MaterialSpecular * LightSpecular;

// Simple shader to do vertex processing on the GPU.
PixelShaderInput main(VertexShaderInput input)
{
	PixelShaderInput output = (PixelShaderInput)0;
    Material mat = Mat;

    float3 position = input.position; // BoneSkinning( input.position, input.boneWeight, input.boneID );
    float3 normal = input.normal; // BoneSkinningNormal( input.normal, input.boneWeight, input.boneID );

    // Transform the vertex position into projected space.
    matrix worldViewProjMatrix = mul( projection, mul( view, model ) );
    output.positionWS = mul( (float3x3)model, position );
    output.positionHS = mul( worldViewProjMatrix, float4(position, 1) );
    output.shadowPositionCS = mul( viewToShadow, float4(output.positionWS, 1) );
    output.eyeWS = cameraPosition - mul( (float3x3)model, position );
    output.normalWS = normalize(mul( (float3x3)model, normal ));

    output.color.rgb = max(0, dot(output.normalWS, -LightDirection) * MainHLamb + (1 - MainHLamb))*AmbientColor*MainLightParam;
    float3 subsum = 0;
    for (int i = 0; i < 16; i++) {
        float3 p = float3(LightPos[i].xy, -LightPos[i].z);
        subsum += max(0, dot(output.normalWS, normalize(p)) * SubHLamb + (1 - SubHLamb))*AmbientColor*SubLightParam;
    }
    
    output.color.rgb += (subsum / (16 * LightScale))*1.0;
    output.color.a = smoothstep( 0, 0.9, DiffuseColor.a );
	output.texCoord = input.texcoord;
    if ( mat.sphereOperation != kSphereNone ) {
        float2 normalVS = mul( (float3x3)view, output.normalWS ).xy;
        output.spTex.x = normalVS.x * 0.5 + 0.5;
        output.spTex.y = normalVS.y * -0.5 + 0.5;
    }
    output.emissive = float4(0, 0, 0, MaterialDiffuse.a);
#if AUTOLUMINOUS
    if (IsEmission)
    {
        output.emissive = MaterialDiffuse;
        // from Autoluminous 'EmittionPower0'
        float factor = max( 1, (mat.specularPower - 100) / 7 );
        output.emissive.rgb *= factor*10;
        output.color.rgb += lerp(float3(1, 1, 1), output.color.rgb, 0.0) * factor;
    }
#endif
	return output;
}