#include "stdafx.h"
#include "LinearColor.h"

// Need to also change 'ShaderUtility.hlsli' COLOR_FORMAT_PC_DEFAULT
#define LinearColor 0

namespace Gamma
{
#if !LinearColor
    bool bSRGB = false;
    XMFLOAT3 Convert( XMFLOAT3 t ) {
        return t;
    }
    XMFLOAT4 Convert( XMFLOAT4 t ) {
        return t;
    }
#else
    bool bSRGB = true;
    XMFLOAT3 Convert( XMFLOAT3 t ) {
        return FromSRGB( t );
    }
    XMFLOAT4 Convert( XMFLOAT4 t ) {
        return FromSRGB( t );
    }
#endif
}