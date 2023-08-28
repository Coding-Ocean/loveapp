#if 1
#include"../lovelib/lovelib.h"
#include<cmath>

int createIdxCubeFront()
{
	unsigned short indices[] = {
		0,1,2,
		0,2,3,
	};
	return createIndexBuffer(indices, _countof(indices));
}
int createIdxCubeBack()
{
	unsigned short indices[] = {
		4,5,6,
		4,6,7,
	};
	return createIndexBuffer(indices, _countof(indices));
}
int createIdxCubeLeft()
{
	unsigned short indices[] = {
		12,13,14,
		12,14,15,
	};
	return createIndexBuffer(indices, _countof(indices));
}
int createIdxCubeRight()
{
	unsigned short indices[] = {
		8,9,10,
		8,10,11,
	};
	return createIndexBuffer(indices, _countof(indices));
}
int createIdxCubeTop()
{
	unsigned short indices[] = {
		16,17,18,
		16,18,19,
	};
	return createIndexBuffer(indices, _countof(indices));
}
int createIdxCubeBottom()
{
	unsigned short indices[] = {
		20,21,22,
		20,22,23,
	};
	return createIndexBuffer(indices, _countof(indices));
}
int createTex()
{
	const int n = 10;
	unsigned int abgr[n * n];
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int i = x + y * n;
			if ((x+y) % 2)
				abgr[i] = 0xffffffff;
			else
				abgr[i] = 0xff808080;
		}
	}
	return createTexture((unsigned char*)abgr, n, n, "");
}
void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int vtxCube = createVtxCube(0.5f);
	int idxCube = createIdxCube();
	int texCube = createTex();
	int idxFront = createIdxCubeFront();
	int idxBack = createIdxCubeBack();
	int idxRight = createIdxCubeRight();
	int idxLeft = createIdxCubeLeft();
	int idxTop = createIdxCubeTop();
	int idxBottom = createIdxCubeBottom();
	int texFront = loadImage("animal_dog_front.png");
	int texBack = loadImage("animal_dog_back.png");
	int texRight = loadImage("animal_dog_right.png");
	int texLeft = loadImage("animal_dog_left.png");
	int texTop = loadImage("animal_dog_top.png");
	int texBottom = loadImage("animal_dog_bottom.png");

	MAT world;
	float angle = 0;
	
	lightDirection(0,0,1);

	setView(VEC(0, 3, -8.01), VEC(0, 0, 0), VEC(0, 1, 0));

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.2f, 0.4f, 0.8f);

		angle += 0.01f;

		world.identity();
		world.mulScaling(7, 7, 7);
		world.mulTranslate(0, -3.5f, 0);
		lightAmbient(0.9f,0.9f,0.9f);
		model(vtxCube, idxCube, texCube, world);

		world.identity();
		world.mulScaling(0.5f, 1, 1);
		world.mulRotateY(angle);
		world.mulTranslate(0, 0.5f, 0);
		//lightAmbient(0.5f, 0.5f, 0.5f);
		model(vtxCube, idxFront, texFront, world);
		model(vtxCube, idxBack, texBack, world);
		model(vtxCube, idxRight, texRight, world);
		model(vtxCube, idxLeft, texLeft, world);
		model(vtxCube, idxTop, texTop, world);
		model(vtxCube, idxBottom, texBottom, world);
		
		present();
	}
}
#endif
