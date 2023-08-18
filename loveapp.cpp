#include"../lovelib/lovelib.h"

int createVtxCube()
{
	float l = 0.5f;
	VERTEX vertices[] = {
		//ê≥ñ 
		-l, l,-l, 0,0,-1, 0,0,
		-l,-l,-l, 0,0,-1, 0,1,
		 l,-l,-l, 0,0,-1, 1,1,
		 l, l,-l, 0,0,-1, 1,0,
		//ó†ñ 
		 l, l, l, 0,0,1, 0,0,
		 l,-l, l, 0,0,1, 0,1,
		-l,-l, l, 0,0,1, 1,1,
		-l, l, l, 0,0,1, 1,0,
		//âEñ 
		 l, l,-l, 1,0,0, 0,0,
		 l,-l,-l, 1,0,0, 0,1,
		 l,-l, l, 1,0,0, 1,1,
		 l, l, l, 1,0,0, 1,0,
		//ç∂ñ 
		-l, l, l, -1,0,0, 0,0,
		-l,-l, l, -1,0,0, 0,1,
		-l,-l,-l, -1,0,0, 1,1,
		-l, l,-l, -1,0,0, 1,0,
		//è„ñ 
		-l, l, l, 0,1,0, 0,0,
		-l, l,-l, 0,1,0, 0,1,
		 l, l,-l, 0,1,0, 1,1,
		 l, l, l, 0,1,0, 1,0,
		//â∫ñ 
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

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int vtxCube = createVtxCube();
	int idxCube = createIdxCube();
	int texCube = loadImage("tex1.png");

	MAT world;
	float angle = 0;

	while (!quit()) {
		if (escKeyPressed()) closeWindow();
		
		clear(0.0f, 0.0f, 0.0f);
		
		//3D
		angle += 0.005f;
		world.identity();
		world.mulRotateX(angle);
		world.mulRotateZ(angle);
		model(vtxCube, idxCube, texCube, world);

		present();
	}
}