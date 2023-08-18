#include"../lovelib/lovelib.h"
#include"../lovelib/primitive.h"

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int vtxCube = createVtxCube();
	int idxCube = createIdxCube();
	int texCube = loadImage("tex1.png");

	int vtxSphere = createVtxSphere();
	int idxSphere = createIdxSphere();
	int texSphere = loadImage("earth.png");

	MAT world;
	float angle = 0;

	while (!quit()) {
		if (escKeyPressed()) closeWindow();
		
		clear(0.0f, 0.0f, 0.0f);
		
		angle += 0.008f;

		//Cube
		world.identity();
		world.mulRotateX(angle);
		world.mulRotateY(angle);
		world.mulRotateZ(angle);
		model(vtxCube, idxCube, texCube, world);

		//Sphere
		world.identity();
		world.mulScaling(2, 2, 2);
		world.mulRotateY(-angle);
		world.mulRotateX(-0.5f);
		model(vtxSphere, idxSphere, texSphere, world);

		present();
	}
}