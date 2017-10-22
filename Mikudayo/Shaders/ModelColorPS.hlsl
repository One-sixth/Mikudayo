#include "CommonInclude.hlsli"

struct Material
{
    float3  diffuse;
    //-------------------------- ( 16 bytes )
    float3  specular;
    //-------------------------- ( 16 bytes )
    float3  ambient;
    //-------------------------- ( 16 bytes )
    float3  emissive;
    //-------------------------- ( 16 bytes )
    float3  transparent;
    float   padding0;
    //-------------------------- ( 16 bytes )
    float   opacity;
    float   shininess;
    float   specularStrength;
    bool    bDiffuseTexture;
    //-------------------------- ( 16 bytes )
    bool    bSpecularTexture;
    bool    bEmissiveTexture;
    bool    bNormalTexture;
    bool    bLightmapTexture;
    //-------------------------- ( 16 bytes )
    bool    bReflectionTexture;
    // float3  padding1;
    //--------------------------- ( 16 bytes )
};

cbuffer Material : register(b4)
{
    Material Mat;
};

Texture2D<float4> texDiffuse		: register(t1);
Texture2D<float3> texSpecular		: register(t2);
Texture2D<float4> texEmissive		: register(t3);
Texture2D<float3> texNormal			: register(t4);
Texture2D<float4> texLightmap		: register(t5);
Texture2D<float4> texReflection	    : register(t6);

Texture2D<float> texSSAO			: register(t64);
Texture2D<float> texShadow			: register(t65);

SamplerState sampler0 : register(s0);
SamplerComparisonState shadowSampler : register(s1);

struct PixelShaderInput
{
    float4 positionHS : SV_POSITION;
    float3 eyeWS : POSITION0;
    float2 texCoord : TEXCOORD0;
    float3 normalWS : NORMAL;
    float4 color : COLOR0;
    float3 specular : COLOR1;
};

float4 main(PixelShaderInput input) : SV_TARGET
{ 
    Material mat = Mat;

    float4 color = input.color;
    if (mat.bDiffuseTexture) {
        color *= texDiffuse.Sample( sampler0, input.texCoord );
    }
    color.rgb += input.specular;
    return color;
}