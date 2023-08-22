#if 1
#include"../lovelib/lovelib.h"
#include"../lovelib/primitive.h"
#include<cmath>

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	//Cube
	int vtxCube = createVtxCube();
	int idxCube = createIdxCube();
	int texCube = loadImage("tex1.png");
	//Sphere
	float radius = 1;
	int numCorners = 60;
	int vtxSphere = createVtxSphere(radius, numCorners);
	int idxSphere = createIdxSphere(numCorners);
	int texSphere = loadImage("earth.png");
	//Logo
	int texLogo = loadImage("logo.png");

	MAT world;
	float angle = 0;

	while (!quit()) {
		if (escKeyPressed()) closeWindow();
		
		clear(0.0f, 0.0f, 0.0f);
		
		angle += 0.008f;

		//Cube
		world.identity();
		world.mulRotateZ(angle);
		world.mulRotateX(angle);
		world.mulRotateY(angle);
		fill(1, 1, 1, 1);
		model(vtxCube, idxCube, texCube, world);
		
		//Sphere
		world.identity();
		world.mulRotateY(-angle);
		world.mulRotateX(-0.5f);
		fill(1, 1, 1, 1);
		model(vtxSphere, idxSphere, texSphere, world);
		
		//Logo
		fill(1, 1, 1, 1);
		image(texLogo, width/2.0f, height/2.0f);

		present();
	}
}
#endif

#if 0
#include"../lovelib/lovelib.h"
#include"../lovelib/primitive.h"

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int vtxSphere = createVtxSphere(0.5f,50);
	int idxSphere = createIdxSphere(50);
	int texSun = loadImage("sun.png");
	int texEarth = loadImage("earth.png");
	int texMoon = loadImage("moon.png");

	MAT world;
	float angle = 0;
	float rotationSpeed = 0.008f;

	VEC lookat(0,0,0), up(0, 1, 0);
	VEC campos(0, 6, -13);
	setView(campos, lookat, up);

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.0f, 0.0f, 0.0f);

		angle += rotationSpeed;

		//���z-------------------------------------------------------
		world.identity();
		world.mulScaling(3.f, 3.f, 3.f);
		//���z�̎��]
		world.mulRotateY(-angle*0.3f);
		//���z�̕`��
		ambient(1.f, 1.f, 1.f);
		model(vtxSphere, idxSphere, texSun, world);

		//�n��-------------------------------------------------------
		world.identity();
		//�n���̎��]
		world.mulRotateY(-angle*5);
		//�n���̌��]
		world.mulTranslate(6, 0, 0);
		world.mulRotateY(-angle);
		//�n���̕`��
		setLightDirection(world._41, world._42, world._43);
		ambient(0.f, 0.f, 0.f);
		model(vtxSphere, idxSphere, texEarth, world);

		//��---------------------------------------------------------
		world.identity();
		world.mulScaling(0.25f, 0.25f, 0.25f);
		//���̌��]
		world.mulTranslate(1, 0, 0);
		world.mulRotateY(-angle);
		//�n���̌��]������
		world.mulTranslate(6, 0, 0);
		world.mulRotateY(-angle);
		//���`��
		model(vtxSphere, idxSphere, texMoon, world);

		present();
	}
}
#endif

