#if 1
#include"../lovelib/lovelib.h"
#include"../lovelib/primitive.h"
#include<cmath>
void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int numCorners = 4;
	int vtx = createVtxCylinder(0.02f,numCorners);
	int idx = createIdxCylinder(numCorners);
	int tex = 0;// loadImage("earth.png");

	int vtxSphere = createVtxSphere(0.02f, numCorners);
	int idxSphere = createIdxSphere(numCorners);

	MAT world;
	float angle = 0;

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.f, 0.f, 0.f);

		angle += 0.01f;

		//ambient(0.4f, 0.4f, 0.4f);
		
		VEC p(1, -1, -0.3f);
		world.identity();
		fill(1, 1, 0);
		model(vtxSphere, idxSphere, 0, world);
		world.mulTranslate(p.x, p.y, p.z);
		model(vtxSphere, idxSphere, 0, world);
		
		world.identity();
		world.mulScaling(p.mag(), 1, 1);
		VEC n = normalize(p);
		world.mulRotateZ(acos(-n.y) - 1.57f);
		world.mulRotateY(-atan2(p.z, p.x));
		fill(1, 1, 0);
		model(vtx, idx, tex, world);

		present();
	}
}
#endif

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
	int tex = loadImage("tex2.png");

	MAT world;
	float angle = 0;

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.4f, 0.4f, 0.4f);

		angle += 0.01f;

		world.identity();
		world.mulRotateY(angle);
		world.mulTranslate(0, 0, 0);
		model(vtx, idx, tex, world);

		present();
	}
}
#endif

#if 0
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

		//Sphere
		world.identity();
		world.mulRotateY(-angle);
		world.mulRotateX(-0.5f);
		model(vtxSphere, idxSphere, texSphere, world);
		
		//Cube
		world.identity();
		world.mulRotateZ(angle);
		world.mulRotateX(angle);
		world.mulRotateY(angle);
		model(vtxCube, idxCube, texCube, world);

		//Logo
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
		ambient(1.f, 1.f, 1.f);
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
		ambient(0.f, 0.f, 0.f);
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

