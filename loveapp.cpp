//éOäpÉ|ÉäÉSÉì
#if 0
#include"../lovelib/lovelib.h"

int createVtxTriangle(float l)
{
	VERTEX vertices[] = {
		-l, l, 0, 0,0,-1, 0,0,
		-l,-l, 0, 0,0,-1, 0,1,
		 l,-l, 0, 0,0,-1, 1,1,
	};
	return createVertexBuffer(vertices, _countof(vertices));
}
int createIdxTriangle()
{
	unsigned short indices[] = {
		0,1,2,
	};
	return createIndexBuffer(indices, _countof(indices));
}

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int vtx = createVtxTriangle(0.5f);
	int idx = createIdxTriangle();
	int tex = loadImage("earth.png");

	MAT world;
	float angle = 0;
	float scale = 1;
	
	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.6f, 0.2f, 0.2f);

		angle += 0.01f;
		world.identity();
		world.mulScaling(scale, scale, scale);
		world.mulRotateY(angle);
		world.mulTranslate(0, 0, 0);
		model(vtx, idx, tex, world);

		present();
	}
}
#endif
//ínãÖÇ∆óßï˚ëÃ
#if 0
#include"../lovelib/lovelib.h"
#include"../lovelib/primitive.h"
#include<cmath>

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);
	hideCursor();

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
		model(vtxCube, idxCube, texCube, world);

		//Sphere
		world.identity();
		world.mulRotateY(-angle);
		world.mulRotateX(-0.5f);
		model(vtxSphere, idxSphere, texSphere, world);

		present();
	}
}
#endif
//É\Å[ÉâÅ[ÉVÉXÉeÉÄ
#if 0
#include"../lovelib/lovelib.h"
#include"../lovelib/primitive.h"
#include<cmath>

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);
	hideCursor();

	int numCorners = 50;
	int vtxSphere = createVtxSphere(0.5f,numCorners);
	int idxSphere = createIdxSphere(numCorners);
	int texSun = loadImage("sun.png");
	int texEarth = loadImage("earth.png");
	int texMoon = loadImage("moon.png");

	MAT world;
	float angle = 0;
	float rotationSpeed = 0.008f;

	VEC campos(0, 6, -12);
	VEC lookat(0, 0, 0);
	VEC up(0, 1, 0);
	setView(campos, lookat, up);

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.0f, 0.0f, 0.0f);

		angle += rotationSpeed;

		//ëæóz-------------------------------------------------------
		world.identity();
		world.mulScaling(3.f, 3.f, 3.f);
		//ëæózÇÃé©ì]
		world.mulRotateY(-angle*0.3f);
		//ëæózÇÃï`âÊ
		ambient(1, 1, 1);
		model(vtxSphere, idxSphere, texSun, world);

		//ínãÖ-------------------------------------------------------
		world.identity();
		//ínãÖÇÃé©ì]
		world.mulRotateY(-angle*5);
		//ínãÖÇÃåˆì]
		world.mulTranslate(6, 0, 0);
		world.mulRotateY(-angle);
		//ínãÖÇÃï`âÊ
		setLightDirection(world._41, world._42, world._43);
		ambient(0, 0, 0);
		model(vtxSphere, idxSphere, texEarth, world);

		//åé---------------------------------------------------------
		world.identity();
		world.mulScaling(0.25f, 0.25f, 0.25f);
		//åéÇÃåˆì]
		world.mulTranslate(1, 0, 0);
		world.mulRotateY(-angle);
		//ínãÖÇÃåˆì]Ççáê¨
		world.mulTranslate(6, 0, 0);
		world.mulRotateY(-angle);
		//åéï`âÊ
		model(vtxSphere, idxSphere, texMoon, world);
		
		present();
	}
}
#endif
//â~íå
#if 0
#include"../lovelib/lovelib.h"
#include<cmath>
void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);
	hideCursor();

	int numCorners = 30;
	int vtx = createVtxCylinder(0.5f/*radius*/, numCorners, -0.6f/*low*/, 0.6f/*high*/);
	int idx = createIdxCylinder(numCorners);
	int tex = loadImage("earth.png");

	MAT world;
	float angle = 0;

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.1f, 0.2f, 0.2f);

		angle += -0.01f;

		world.identity();
		world.mulRotateY(angle);
		world.mulRotateX(angle);
		model(vtx, idx, tex, world);

		present();
	}
}
#endif
//äOêœÉxÉNÉgÉã
#if 0
#include"../lovelib/lovelib.h"
#include<cmath>
void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	createLine3D(0.01f,4);

	MAT world;
	float angle = 0;

	setView(VEC(3, 1, -3), VEC(0, 0, 0), VEC(0, 1, 0));
	setLightDirection(-1, -1, 1);

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.1f, 0.2f, 0.2f);

		angle += -0.01f;

		VEC o{ 0,0,0 };
		VEC v1{ 1,0,0 };
		VEC v2{ cos(angle), 0, sin(angle) };
		VEC v3 = cross(v1, v2);

		ambient(0.4f, 0.4f, 0.4f);
		fill(1, 0, 0);
		line3D(o, v1);
		fill(0, 1, 0);
		line3D(o, v2);
		fill(1, 1, 0);
		line3D(o, v3);

		present();
	}
}
#endif
