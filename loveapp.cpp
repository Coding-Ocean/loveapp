//���v���𗠖ʂƂ��A�\�����Ȃ������_�[�X�e�[�g
#if 1
#include"../lovelib/lovelib.h"
#include<cmath>

int createVtxTriangle(float l)
{
	VERTEX vertices[] = {
		-l, l, 0, 0,0,-1, 0,0,// 0:����
		-l,-l, 0, 0,0,-1, 0,1,// 1:����
		 l,-l, 0, 0,0,-1, 1,1,// 2:�E��
	};
	return createVertexBuffer(vertices, _countof(vertices));
}
int createIdxTriangle()
{
	unsigned short indices[] = {
		0,1,2,//�����v���ɒ��_��I��
	};
	return createIndexBuffer(indices, _countof(indices));
}
int createTexBlack()
{
	unsigned char rgba[] = { 0x00,0x00,0x00,0xff };
	return createTexture(rgba, 1, 1, "texBlack");
}

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int vtx = createVtxTriangle(0.5f);
	int idx = createIdxTriangle();
	int tex = createTexBlack();

	MAT world;
	float angle = 0;
	
	//���v���𗠖ʂƂ��A�\�����Ȃ������_�[�X�e�[�g
	cullcw();

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.2f, 0.4f, 0.8f);

		angle += 0.02f;

		world.identity();
		world.mulRotateY(angle);
		world.mulTranslate(0, 0, 0);
		model(vtx, idx, tex, world);

		present();
	}
}
#endif
//�g�債�Ă����邳��ς��Ȃ������_�[�X�e�[�g
#if 0
#include"../lovelib/lovelib.h"
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

	MAT world;
	float angle = 0;
	float scale = 1;

	//�g�債�Ă����邳��ς��Ȃ������_�[�X�e�[�g
	normalizeNormals();

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.f, 0.f, 0.f);

		angle += 0.008f;
		scale = sin(angle) + 1;

		world.identity();
		world.mulScaling(scale, scale, scale);
		world.mulRotateZ(angle);
		world.mulRotateX(angle);
		world.mulRotateY(angle);
		model(vtxCube, idxCube, texCube, world);

		present();
	}
}
#endif
//�[�x�o�b�t�@�A���C�g���}�e���A���A���u�����h�A�e�N�X�`��
#if 0
#include"../lovelib/lovelib.h"
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
	int numCorners = 120;
	int vtxSphere = createVtxSphere(radius, numCorners);
	int idxSphere = createIdxSphere(numCorners);
	int texSphere = loadImage("earth.png");

	MAT world;
	float angle = 0;

	//�[�x�o�b�t�@�ɐ[�x�f�[�^����������
	writeDepth();

	while (!quit()) {
		if (escKeyPressed()) closeWindow();
		
		clear(0.f, 0.f, 0.f);
		
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

		present();
	}
}
#endif
//�\�[���[�V�X�e��
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

		//���z-------------------------------------------------------
		world.identity();
		world.mulScaling(3.f, 3.f, 3.f);
		//���z�̎��]
		world.mulRotateY(-angle * 0.3f);
		//���z�̕`��
		lightAmbient(1, 1, 1);
		model(vtxSphere, idxSphere, texSun, world);

		//�n��-------------------------------------------------------
		world.identity();
		//�n���̎��]
		world.mulRotateY(-angle*5);
		//�n���̌��]
		world.mulTranslate(6, 0, 0);
		world.mulRotateY(-angle);
		//�n���̕`��
		lightDirection(world._41, world._42, world._43);
		lightAmbient(0, 0, 0);
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
//line�֐�(�Q����������`���j
#if 0
#include"../lovelib/lovelib.h"
#include<cmath>
void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);
	hideCursor();
	//�~�̃f�[�^
	struct DATA {
		float x, y, radius;
	};
	DATA c1{ 960,540, 80 };
	DATA c2{ 960,540, 100 };
	//���T����[�Ȑ���𓮂������̃��W�A���l
	float angle = 0;
	//���C�����[�v
	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.2f, 0.2f, 0.2f);

		//���T����[�Ȑ���𓮂���
		angle += 0.005f;
		c1.x = 960 + sin(angle * 2) * 400;
		c1.y = 540 + cos(angle * 3) * 400;
		c2.x = 960 + cos(angle) * 400;
		c2.y = 540 + sin(angle * 2) * 400;
		//������Ă�����F��ς���
		float a = c1.x - c2.x;
		float b = c1.y - c2.y;
		float c = sqrt(a * a + b * b);
		if (c < c1.radius + c2.radius)
			fill(233 / 255.0f, 84 / 255.0f, 107 / 255.0f, 0.9f);
		else
			fill(0, 173 / 255.0f, 169 / 255.0f);
		//�~�`��
		circle(c1.x, c1.y, c1.radius * 2);
		circle(c2.x, c2.y, c2.radius * 2);
		//�����`��
		fill(255 / 255.0f, 243 / 255.0f, 63 / 255.0f);
		float thickness = 2;
		line(c1.x, c1.y, c2.x, c2.y, thickness);

		present();
	}
}
#endif
//primitive:�~��
#if 0
#include"../lovelib/lovelib.h"
#include<cmath>
void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);
	hideCursor();

	int numCorners = 50;
	int vtx = createVtxCylinder(0.5f/*radius*/, numCorners, -0.9f/*low*/, 0.9f/*high*/);
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
//�O�σx�N�g��
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
	lightDirection(-1, -1, 1);

	while (!quit()) {
		if (escKeyPressed()) closeWindow();

		clear(0.1f, 0.2f, 0.2f);

		angle += -0.01f;

		VEC o{ 0,0,0 };
		VEC v1{ 1,0,0 };
		VEC v2{ cos(angle), 0, sin(angle) };
		VEC v3 = cross(v1, v2);

		lightAmbient(0.4f, 0.4f, 0.4f);
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
