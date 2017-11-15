float4 MultiplyQuaternion( float4 q1, float4 q2 )
{
	float4 res;
    res.w = q1.w * q2.w - dot( q1.xyz, q2.xyz );
    res.xyz = q1.w * q2.xyz + q2.w * q1.xyz + cross( q1.xyz, q2.xyz );
	return res;
}

float3 RotateQuaternionVector3( in float4 q, in float3 v )
{
	float3 t = 2.0 * cross( q.xyz, v );
	return v + q.w * t + cross( q.xyz, t );
}

float3 TransformPosition( float4 quat, float4 translate, float3 position )
{
    return RotateQuaternionVector3( quat, position ) + translate.xyz;
}

float3 TransformNormal( float4 quat, float4 translate, float3 normal )
{
    return RotateQuaternionVector3( quat, normal );
}

float3 Slerp( float3 n0, float3 n1, float t )
{
    float3 N0 = normalize( n0 );
    float3 N1 = normalize( n1 );
    float phi = acos( dot( N0, N1 ) );
    float sinPhi = sin( phi );
    float3 ret = (sin( (1.0f - t)*phi ) / sinPhi)*N0 + (sin( t*phi ) / sinPhi)*N1;
    return phi;
}

float3 TransformPositionDualQuat( float3 position, float4 realDQ, float4 dualDQ )
{
    return position +
        2 * cross( realDQ.xyz, cross(realDQ.xyz, position) + realDQ.w*position ) +
        2 * (realDQ.w * dualDQ.xyz - dualDQ.w * realDQ.xyz + 
            cross( realDQ.xyz, dualDQ.xyz));
}
 
float3 TransformNormalDualQuat( float3 normal, float4 realDQ, float4 dualDQ )
{
    return normal + 2.0 * cross( realDQ.xyz, cross( realDQ.xyz, normal ) + 
                          realDQ.w * normal );
}

float2x4 DualQuaternion( float4 quaternion, float4 translate )
{
	return float2x4(
        quaternion,
        MultiplyQuaternion( translate * 0.5, quaternion )
	);
}

float2x4 BlendDualQuaternion2( float2x4 dq0, float2x4 dq1, float weight )
{
    float2x4 blendedDQ = lerp(dq0, dq1, weight);
    // normalize
    float normDQ = length(blendedDQ[0]);
    return blendedDQ / normDQ;
}

// Seek shortest rotation
float2x4 BlendDualQuaternionShortest2( float2x4 dq0, float2x4 dq1, float weight )
{
    float2x4 blendedDQ = dq0 * weight;
    float weight1 = 1 - weight;
    if (dot( dq0[0], dq1[0] ) < 0)
        weight1 = -weight1;
    blendedDQ += dq1 * weight1;
    // normalize
    float normDQ = length(blendedDQ[0]);
    return blendedDQ / normDQ;
}

float2x4 BlendDualQuaternionShortest4( float2x4 dq[4], float4 weight )
{
    float2x4 blendedDQ = 0;
    float4 rot = dq[0][0];
    for (int i = 0; i < 4; i++)
    {
        float w = weight[i];
        if (dot( rot, dq[i][0] ) < 0)
            w *= -1;
        blendedDQ += dq[i] * w;
    }
    // normalize
    float normDQ = length(blendedDQ[0]);
    return blendedDQ / normDQ;
}
