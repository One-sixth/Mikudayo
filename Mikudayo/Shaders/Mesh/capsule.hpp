// meshdata capsule
D3D11_INPUT_ELEMENT_DESC mesh_layout[3] = {
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

UINT layout_num = 3;
UINT vertex_stride = 32;
UINT vertex_num = 97;
UINT index_num = 420;
FLOAT diffuse[4] = {1.0f, 1.0f, 1.0f, 1.0f};

FLOAT mesh_vertex[776] = {	
	-0.415627f, -0.707107f, -0.572061f, -0.427161f, -0.686923f, -0.587937f, 0.9f, 0.75f, 
	-0.543043f, -0.382683f, -0.747434f, -0.546418f, -0.368514f, -0.75208f, 0.9f, 0.625f, 
	-0.672499f, -0.707107f, -0.218508f, -0.691162f, -0.686923f, -0.224572f, 0.8f, 0.75f, 
	-0.878662f, -0.382683f, -0.285494f, -0.884123f, -0.368515f, -0.287269f, 0.8f, 0.625f, 
	-0.224936f, -0.92388f, -0.309597f, -0.244598f, -0.909303f, -0.33666f, 0.9f, 0.875f, 
	0.0f, -0.707107f, -0.707107f, 0.0f, -0.686923f, -0.726731f, 1.0f, 0.75f, 
	0.0f, -0.707107f, -0.707107f, 0.0f, -0.686923f, -0.726731f, 0.0f, 0.75f, 
	-0.363954f, -0.92388f, -0.118256f, -0.395768f, -0.909303f, -0.128593f, 0.8f, 0.875f, 
	-0.587785f, 0.0f, -0.809017f, -0.587785f, 0.0f, -0.809017f, 0.9f, 0.5f, 
	0.0f, -0.92388f, -0.382683f, 0.0f, -0.909303f, -0.416135f, 1.0f, 0.875f, 
	0.0f, -0.92388f, -0.382683f, 0.0f, -0.909303f, -0.416135f, 0.0f, 0.875f, 
	0.0f, -0.382683f, -0.92388f, 0.0f, -0.368515f, -0.929622f, 1.0f, 0.625f, 
	0.0f, -0.382683f, -0.92388f, 0.0f, -0.368515f, -0.929622f, 0.0f, 0.625f, 
	-0.951057f, 0.0f, -0.309017f, -0.951056f, -5.48225e-09f, -0.309017f, 0.8f, 0.5f, 
	-0.363954f, -0.92388f, 0.118256f, -0.395768f, -0.909303f, 0.128593f, 0.7f, 0.875f, 
	-0.672499f, -0.707107f, 0.218508f, -0.691162f, -0.686923f, 0.224572f, 0.7f, 0.75f, 
	0.224936f, -0.92388f, -0.309597f, 0.244598f, -0.909303f, -0.33666f, 0.1f, 0.875f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.55f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.65f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.75f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.85f, 1.0f, 
	0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.5f, 
	0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.5f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.95f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.05f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.15f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.25f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.35f, 1.0f, 
	0.0f, -1.0f, -0.0f, -2.19604e-09f, -1.0f, 0.0f, 0.45f, 1.0f, 
	-0.878662f, -0.382683f, 0.285494f, -0.884123f, -0.368515f, 0.287269f, 0.7f, 0.625f, 
	-0.543043f, 0.382683f, -0.747434f, -0.546418f, 0.368514f, -0.75208f, 0.9f, 0.375f, 
	0.415627f, -0.707107f, -0.572061f, 0.427161f, -0.686923f, -0.587937f, 0.1f, 0.75f, 
	-0.224936f, -0.92388f, 0.309597f, -0.244598f, -0.909303f, 0.33666f, 0.6f, 0.875f, 
	-0.878662f, 0.382683f, -0.285494f, -0.884123f, 0.368515f, -0.287269f, 0.8f, 0.375f, 
	0.363954f, -0.92388f, -0.118256f, 0.395768f, -0.909303f, -0.128593f, 0.2f, 0.875f, 
	-0.951057f, 0.0f, 0.309017f, -0.951056f, -5.48225e-09f, 0.309017f, 0.7f, 0.5f, 
	0.543043f, -0.382683f, -0.747434f, 0.546418f, -0.368514f, -0.75208f, 0.1f, 0.625f, 
	-0.415627f, -0.707107f, 0.572061f, -0.427161f, -0.686923f, 0.587937f, 0.6f, 0.75f, 
	0.0f, 0.382683f, -0.92388f, 0.0f, 0.368515f, -0.929622f, 0.0f, 0.375f, 
	0.0f, 0.382683f, -0.92388f, 0.0f, 0.368515f, -0.929622f, 1.0f, 0.375f, 
	0.0f, -0.92388f, 0.382683f, 0.0f, -0.909303f, 0.416135f, 0.5f, 0.875f, 
	0.363954f, -0.92388f, 0.118256f, 0.395768f, -0.909303f, 0.128593f, 0.3f, 0.875f, 
	0.224936f, -0.92388f, 0.309597f, 0.244598f, -0.909303f, 0.33666f, 0.4f, 0.875f, 
	-0.415627f, 0.707107f, -0.572061f, -0.427161f, 0.686923f, -0.587937f, 0.9f, 0.25f, 
	0.672499f, -0.707107f, -0.218508f, 0.691162f, -0.686923f, -0.224572f, 0.2f, 0.75f, 
	0.587785f, 0.0f, -0.809017f, 0.587785f, 0.0f, -0.809017f, 0.1f, 0.5f, 
	-0.878662f, 0.382683f, 0.285494f, -0.884123f, 0.368515f, 0.287269f, 0.7f, 0.375f, 
	-0.672499f, 0.707107f, -0.218508f, -0.691162f, 0.686923f, -0.224572f, 0.8f, 0.25f, 
	-0.543043f, -0.382683f, 0.747434f, -0.546418f, -0.368514f, 0.75208f, 0.6f, 0.625f, 
	0.0f, -0.707107f, 0.707107f, 0.0f, -0.686923f, 0.726731f, 0.5f, 0.75f, 
	0.0f, 0.707107f, -0.707107f, 0.0f, 0.686923f, -0.726731f, 0.0f, 0.25f, 
	0.0f, 0.707107f, -0.707107f, 0.0f, 0.686923f, -0.726731f, 1.0f, 0.25f, 
	0.543043f, 0.382683f, -0.747434f, 0.546418f, 0.368514f, -0.75208f, 0.1f, 0.375f, 
	0.672499f, -0.707107f, 0.218508f, 0.691162f, -0.686923f, 0.224572f, 0.3f, 0.75f, 
	0.878662f, -0.382683f, -0.285494f, 0.884123f, -0.368515f, -0.287269f, 0.2f, 0.625f, 
	-0.587785f, 0.0f, 0.809017f, -0.587785f, 0.0f, 0.809017f, 0.6f, 0.5f, 
	-0.672499f, 0.707107f, 0.218508f, -0.691162f, 0.686923f, 0.224572f, 0.7f, 0.25f, 
	0.415627f, -0.707107f, 0.572061f, 0.427161f, -0.686923f, 0.587937f, 0.4f, 0.75f, 
	-0.224936f, 0.92388f, -0.309597f, -0.244598f, 0.909303f, -0.33666f, 0.9f, 0.125f, 
	-0.363954f, 0.92388f, -0.118256f, -0.395768f, 0.909303f, -0.128593f, 0.8f, 0.125f, 
	0.0f, 0.92388f, -0.382683f, 0.0f, 0.909303f, -0.416135f, 0.0f, 0.125f, 
	0.0f, -0.382683f, 0.92388f, 0.0f, -0.368515f, 0.929622f, 0.5f, 0.625f, 
	0.0f, 0.92388f, -0.382683f, 0.0f, 0.909303f, -0.416135f, 1.0f, 0.125f, 
	0.415627f, 0.707107f, -0.572061f, 0.427161f, 0.686923f, -0.587937f, 0.1f, 0.25f, 
	-0.543043f, 0.382683f, 0.747434f, -0.546418f, 0.368514f, 0.75208f, 0.6f, 0.375f, 
	0.951057f, 0.0f, -0.309017f, 0.951056f, -5.48225e-09f, -0.309017f, 0.2f, 0.5f, 
	-0.363954f, 0.92388f, 0.118256f, -0.395768f, 0.909303f, 0.128593f, 0.7f, 0.125f, 
	0.878662f, -0.382683f, 0.285494f, 0.884123f, -0.368515f, 0.287269f, 0.3f, 0.625f, 
	0.224936f, 0.92388f, -0.309597f, 0.244598f, 0.909303f, -0.33666f, 0.1f, 0.125f, 
	-0.415627f, 0.707107f, 0.572061f, -0.427161f, 0.686923f, 0.587937f, 0.6f, 0.25f, 
	0.543043f, -0.382683f, 0.747434f, 0.546418f, -0.368514f, 0.75208f, 0.4f, 0.625f, 
	0.878662f, 0.382683f, -0.285494f, 0.884123f, 0.368515f, -0.287269f, 0.2f, 0.375f, 
	0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.55f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.05f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.45f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.25f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.35f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.65f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.15f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.75f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.95f, 0.0f, 
	0.0f, 1.0f, -0.0f, -2.19604e-09f, 1.0f, 0.0f, 0.85f, 0.0f, 
	-0.224936f, 0.92388f, 0.309597f, -0.244598f, 0.909303f, 0.33666f, 0.6f, 0.125f, 
	0.672499f, 0.707107f, -0.218508f, 0.691162f, 0.686923f, -0.224572f, 0.2f, 0.25f, 
	0.363954f, 0.92388f, -0.118256f, 0.395768f, 0.909303f, -0.128593f, 0.2f, 0.125f, 
	0.951057f, 0.0f, 0.309017f, 0.951056f, -5.48225e-09f, 0.309017f, 0.3f, 0.5f, 
	0.0f, 0.382683f, 0.92388f, 0.0f, 0.368515f, 0.929622f, 0.5f, 0.375f, 
	0.0f, 0.92388f, 0.382683f, 0.0f, 0.909303f, 0.416135f, 0.5f, 0.125f, 
	0.587785f, 0.0f, 0.809017f, 0.587785f, 0.0f, 0.809017f, 0.4f, 0.5f, 
	0.363954f, 0.92388f, 0.118256f, 0.395768f, 0.909303f, 0.128593f, 0.3f, 0.125f, 
	0.0f, 0.707107f, 0.707107f, 0.0f, 0.686923f, 0.726731f, 0.5f, 0.25f, 
	0.224936f, 0.92388f, 0.309597f, 0.244598f, 0.909303f, 0.33666f, 0.4f, 0.125f, 
	0.878662f, 0.382683f, 0.285494f, 0.884123f, 0.368515f, 0.287269f, 0.3f, 0.375f, 
	0.672499f, 0.707107f, 0.218508f, 0.691162f, 0.686923f, 0.224572f, 0.3f, 0.25f, 
	0.543043f, 0.382683f, 0.747434f, 0.546418f, 0.368514f, 0.75208f, 0.4f, 0.375f, 
	0.415627f, 0.707107f, 0.572061f, 0.427161f, 0.686923f, 0.587937f, 0.4f, 0.25f, 
};

UINT mesh_index[420] = {
	74, 68, 60, 79, 85, 68, 76, 90, 85, 77, 92, 90, 75, 88, 92, 73, 83, 
	88, 78, 66, 83, 80, 59, 66, 82, 58, 59, 81, 62, 58, 60, 68, 63, 60, 
	63, 50, 68, 85, 84, 68, 84, 63, 85, 90, 94, 85, 94, 84, 90, 92, 96, 
	90, 96, 94, 92, 88, 91, 92, 91, 96, 88, 83, 69, 88, 69, 91, 83, 66, 
	56, 83, 56, 69, 66, 59, 47, 66, 47, 56, 59, 58, 43, 59, 43, 47, 58, 
	62, 51, 58, 51, 43, 50, 63, 52, 50, 52, 38, 63, 84, 71, 63, 71, 52, 
	84, 94, 93, 84, 93, 71, 94, 96, 95, 94, 95, 93, 96, 91, 87, 96, 87, 
	95, 91, 69, 64, 91, 64, 87, 69, 56, 46, 69, 46, 64, 56, 47, 33, 56, 
	33, 46, 47, 43, 30, 47, 30, 33, 43, 51, 39, 43, 39, 30, 38, 52, 45, 
	38, 45, 21, 52, 71, 65, 52, 65, 45, 71, 93, 86, 71, 86, 65, 93, 95, 
	89, 93, 89, 86, 95, 87, 72, 95, 72, 89, 87, 64, 55, 87, 55, 72, 64, 
	46, 35, 64, 35, 55, 46, 33, 13, 46, 13, 35, 33, 30, 8, 33, 8, 13, 
	30, 39, 22, 30, 22, 8, 21, 45, 36, 21, 36, 12, 45, 65, 54, 45, 54, 
	36, 65, 86, 67, 65, 67, 54, 86, 89, 70, 86, 70, 67, 89, 72, 61, 89, 
	61, 70, 72, 55, 48, 72, 48, 61, 55, 35, 29, 55, 29, 48, 35, 13, 3, 
	35, 3, 29, 13, 8, 1, 13, 1, 3, 8, 22, 11, 8, 11, 1, 12, 36, 
	31, 12, 31, 6, 36, 54, 44, 36, 44, 31, 54, 67, 53, 54, 53, 44, 67, 
	70, 57, 67, 57, 53, 70, 61, 49, 70, 49, 57, 61, 48, 37, 61, 37, 49, 
	48, 29, 15, 48, 15, 37, 29, 3, 2, 29, 2, 15, 3, 1, 0, 3, 0, 
	2, 1, 11, 5, 1, 5, 0, 6, 31, 16, 6, 16, 10, 31, 44, 34, 31, 
	34, 16, 44, 53, 41, 44, 41, 34, 53, 57, 42, 53, 42, 41, 57, 49, 40, 
	57, 40, 42, 49, 37, 32, 49, 32, 40, 37, 15, 14, 37, 14, 32, 15, 2, 
	7, 15, 7, 14, 2, 0, 4, 2, 4, 7, 0, 5, 9, 0, 9, 4, 10, 
	16, 24, 16, 34, 25, 34, 41, 26, 41, 42, 27, 42, 40, 28, 40, 32, 17, 
	32, 14, 18, 14, 7, 19, 7, 4, 20, 4, 9, 23, 
};
