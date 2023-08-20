#include"../lovelib/lovelib.h"

int createVtxCube()
{
	float l = 0.5f;
	VERTEX vertices[] = {
		//����
		-l, l,-l, 0,0,-1, 0,0,
		-l,-l,-l, 0,0,-1, 0,1,
		 l,-l,-l, 0,0,-1, 1,1,
		 l, l,-l, 0,0,-1, 1,0,
		//����
		 l, l, l, 0,0,1,  0,0,
		 l,-l, l, 0,0,1,  0,1,
		-l,-l, l, 0,0,1,  1,1,
		-l, l, l, 0,0,1,  1,0,
		//�E��
		 l, l,-l, 1,0,0,  0,0,
		 l,-l,-l, 1,0,0,  0,1,
		 l,-l, l, 1,0,0,  1,1,
		 l, l, l, 1,0,0,  1,0,
		//����
		-l, l, l, -1,0,0, 0,0,
		-l,-l, l, -1,0,0, 0,1,
		-l,-l,-l, -1,0,0, 1,1,
		-l, l,-l, -1,0,0, 1,0,
		//���
		-l, l, l, 0,1,0,  0,0,
		-l, l,-l, 0,1,0,  0,1,
		 l, l,-l, 0,1,0,  1,1,
		 l, l, l, 0,1,0,  1,0,
		//����
		-l,-l,-l, 0,-1,0, 0,0,
		-l,-l, l, 0,-1,0, 0,1,
		 l,-l, l, 0,-1,0, 1,1,
		 l,-l,-l, 0,-1,0, 1,0,
	};
	return createVertexBuffer(vertices, _countof(vertices));
}

int createIdxCube()
{
	unsigned short indices[] = {
		0,1,2,
		0,2,3,
		4,5,6,
		4,6,7,
		8,9,10,
		8,10,11,
		12,13,14,
		12,14,15,
		16,17,18,
		16,18,19,
		20,21,22,
		20,22,23,
	};
	return createIndexBuffer(indices, _countof(indices));
}

int createTexCube()
{
	unsigned char rgba[] = {
		0x40, 0x80, 0xff, 0xff,
	};
	return createTexture(rgba, 1, 1, "smallTex");
}

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);
	
	//Create DirectX buffer objects
	int vtxCube = createVtxCube();
	int idxCube = createIdxCube();
	int texCube = createTexCube();

	MAT world;
	float angle = 0;

	while (!quit()) {
		if (escKeyPressed()) closeWindow();
		
		clear(0.0f, 0.0f, 0.0f);
		
		//3D
		angle += 0.005f;
		world.identity();
		world.mulRotateZ(angle);
		world.mulRotateY(angle);
		model(vtxCube, idxCube, texCube, world);

		present();
	}
}