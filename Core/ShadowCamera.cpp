//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Developed by Minigraph
//
// Author:  James Stanard 
//

#include "pch.h"
#include "ShadowCamera.h"

using namespace Math;
using namespace GameCore;

BoolVar RecenterCamera( "Graphics/Camera/Recenter", true );

void ShadowCamera::UpdateMatrix(
    Vector3 LightDirection, Vector3 ShadowCenter, Vector3 ShadowBounds,
    uint32_t BufferWidth, uint32_t BufferHeight, uint32_t BufferPrecision )
{
#if 0
    SetLookDirection( LightDirection, Vector3(kYUnitVector) );

    // Converts world units to texel units so we can quantize the camera position to whole texel units
    Vector3 RcpDimensions = Recip(ShadowBounds);
    Vector3 QuantizeScale = Vector3((float)BufferWidth, (float)BufferHeight, (float)((1 << BufferPrecision) - 1)) * RcpDimensions;

    //
    // Recenter the camera at the quantized position
    //
    if (RecenterCamera)
    {
        // Transform to view space
        ShadowCenter = ~GetRotation() * ShadowCenter;
        // Scale to texel units, truncate fractional part, and scale back to world units
        ShadowCenter = Floor( ShadowCenter * QuantizeScale ) / QuantizeScale;
        // Transform back into world space
        ShadowCenter = GetRotation() * ShadowCenter;
    }
    SetPosition( ShadowCenter );

    SetProjMatrix( Matrix4::MakeScale(Vector3(2.0f, 2.0f, -1.0f) * RcpDimensions) );
#elif 0
    SetLookDirection( LightDirection, Vector3(kYUnitVector) );
    SetPosition( ShadowCenter );
    Matrix4 Proj = Matrix4(DirectX::XMMatrixOrthographicRH( ShadowBounds.GetX(), ShadowBounds.GetY(), -ShadowBounds.GetZ(), ShadowBounds.GetZ()));
    SetProjMatrix( Matrix4( Proj ) );
#elif 0
    Vector3 Direction = Normalize(m_SunDirection);
    Vector3 Position = -100 * Direction;
    Matrix4 View = Matrix4(DirectX::XMMatrixLookAtRH(Position, Position + Direction, Vector3(kYUnitVector)));
    Vector4 Center = View * Vector4(0, 0, 0, 1);
    Vector4 min = Center - Vector4(m_ShadowDimX, m_ShadowDimY, m_ShadowDimZ, 1.0);
    Vector4 max = Center + Vector4(m_ShadowDimX, m_ShadowDimY, m_ShadowDimZ, 1.0);
    Matrix4 Proj = Matrix4( DirectX::XMMatrixOrthographicOffCenterRH( min.GetX(), max.GetX(), min.GetY(), max.GetY(), min.GetZ(), max.GetZ() ) );
    Matrix4 ViewProj = Proj * View;
#elif 0
    Vector3 Direction = Normalize(m_SunDirection);
    Vector3 Position = -100 * Direction;
    Matrix4 View = Matrix4(DirectX::XMMatrixLookAtRH(Position, Vector3(kZero), Vector3(kYUnitVector)));
    Vector4 Center = Vector4(DirectX::XMVector3TransformCoord(Vector3(0,0,0), View));
    Vector4 min = Center - Vector4(m_ShadowDimX, m_ShadowDimY, m_ShadowDimZ, 1.0);
    Vector4 max = Center + Vector4(m_ShadowDimX, m_ShadowDimY, m_ShadowDimZ, 1.0);
    Matrix4 Proj = Matrix4( DirectX::XMMatrixOrthographicOffCenterRH( min.GetX(), max.GetX(), min.GetY(), max.GetY(), -m_ShadowDimZ, m_ShadowDimZ ) );
    Matrix4 ViewProj = Proj * View;
#elif 0
    SetLookDirection( LightDirection, Vector3(kYUnitVector) );
    SetPosition( ShadowCenter );

    Update();
	// Transform bounding sphere to light space.
	XMFLOAT3 sphereCenterLS;
	DirectX::XMStoreFloat3(&sphereCenterLS, XMVector3TransformCoord(ShadowCenter, m_ViewMatrix));

	// Ortho frustum in light space encloses scene.
	float l = sphereCenterLS.x - ShadowBounds.GetX();
	float b = sphereCenterLS.y - ShadowBounds.GetY();
	float n = sphereCenterLS.z - ShadowBounds.GetZ();
	float r = sphereCenterLS.x + ShadowBounds.GetX();
	float t = sphereCenterLS.y + ShadowBounds.GetY();
	float f = sphereCenterLS.z + ShadowBounds.GetZ();;
	XMMATRIX P = XMMatrixOrthographicOffCenterRH(l, r, b, t, n, f);
    SetProjMatrix( Matrix4( P ) );
#elif 0
    SetLookDirection( LightDirection, Vector3(kYUnitVector) );
    SetPosition( ShadowCenter );
    SetProjMatrix( PerspectiveMatrix(XM_PI / 4, 1.0f, 0.1f, 10000, m_ReverseZ ) );
#else
    SetLookDirection( LightDirection, Vector3(kYUnitVector) );
    SetPosition( ShadowCenter );
    SetProjMatrix( OrthogonalMatrix(ShadowBounds.GetX(), ShadowBounds.GetY(), -ShadowBounds.GetZ(), ShadowBounds.GetZ(), m_ReverseZ) );
#endif

    Update();

    // Transform from clip space to texture space
    m_ShadowMatrix = Matrix4( AffineTransform( Matrix3::MakeScale( 0.5f, -0.5f, 1.0f ), Vector3(0.5f, 0.5f, 0.0f) ) ) * m_ViewProjMatrix;
}

