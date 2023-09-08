#include"../lovelib/lovelib.h"
#include<cmath>
//�O���ϐ�------------------------------------------------------
//���ƌ��ŋ��p����
MAT World;
//��
int VtxFloor,IdxFloor,TexFloor;
//��
int VtxCube;
int IdxFront, IdxBack, IdxRight, IdxLeft, IdxTop, IdxBottom;
int TexFront, TexBack, TexRight, TexLeft, TexTop, TexBottom;
float Px = 0, Py = 0, Pz = 0;
float Vx = 0.05f, Vy = 0, Vz = 0.5f;
float Ry = 0;

//�֐�----------------------------------------------------------
//���p�C���f�b�N�X������
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
//���p���_������
int createVtxFloor()
{
	float l = 0.5f;
	float y = 0.1f;
	VERTEX vertices[] = {
		//����
		-l, 0,-l, 0,0,-1, 0,0,
		-l,-y,-l, 0,0,-1, 0,0.1,
		 l,-y,-l, 0,0,-1, 1,0.1,
		 l, 0,-l, 0,0,-1, 1,0,
		 //����
		  l, 0, l, 0,0,1, 0,0,
		  l,-y, l, 0,0,1, 0,0.1,
		 -l,-y, l, 0,0,1, 1,0.1,
		 -l, 0, l, 0,0,1, 1,0,
		 //�E��
		  l, 0,-l, 1,0,0, 0,0,
		  l,-y,-l, 1,0,0, 0,0.1,
		  l,-y, l, 1,0,0, 1,0.1,
		  l, 0, l, 1,0,0, 1,0,
		  //����
		  -l, 0, l, -1,0,0, 0,0,
		  -l,-y, l, -1,0,0, 0,0.1,
		  -l,-y,-l, -1,0,0, 1,0.1,
		  -l, 0,-l, -1,0,0, 1,0,
		  //���
		  -l, 0, l, 0,1,0, 0,0,
		  -l, 0,-l, 0,1,0, 0,1,
		   l, 0,-l, 0,1,0, 1,1,
		   l, 0, l, 0,1,0, 1,0,
		   //����
		   -l,-y,-l, 0,-1,0, 0,0,
		   -l,-y, l, 0,-1,0, 0,1,
			l,-y, l, 0,-1,0, 1,1,
			l,-y,-l, 0,-1,0, 1,0,
	};
	return createVertexBuffer(vertices, _countof(vertices));

}
//���p�e�N�X�`��������
int createTexFloor()
{
	const int n = 9;
	unsigned int abgr[n * n];
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int i = x + y * n;
			if ((x+y) % 2)
				abgr[i] = 0xffddbbdd;
			else
				abgr[i] = 0xffccaacc;
		}
	}
	return createTexture((unsigned char*)abgr, n, n, "");
}
//��̊֐��Q���Ăяo���đS�ẴO���t�B�b�N������
void createGraphics()
{
	VtxFloor = createVtxFloor();
	IdxFloor = createIdxCube();
	TexFloor = createTexFloor();

	VtxCube = createVtxCube(0.5f);
	IdxFront = createIdxCubeFront();
	IdxBack = createIdxCubeBack();
	IdxRight = createIdxCubeRight();
	IdxLeft = createIdxCubeLeft();
	IdxTop = createIdxCubeTop();
	IdxBottom = createIdxCubeBottom();
	TexFront = loadImage("animal_dog_front.png");
	TexBack = loadImage("animal_dog_back.png");
	TexRight = loadImage("animal_dog_right.png");
	TexLeft = loadImage("animal_dog_left.png");
	TexTop = loadImage("animal_dog_top.png");
	TexBottom = loadImage("animal_dog_bottom.png");
}
//����`�悷��
void drawFloor()
{
	World.identity();
	World.mulScaling(9, 1, 9);
	model(VtxFloor, IdxFloor, TexFloor, World);
}
//����`�悷��
void drawDog()
{
	World.identity();
	World.mulTranslate(0, 0.5f, 0);
	World.mulScaling(0.5f, 1, 1);
	World.mulRotateY(Ry);
	World.mulTranslate(Px, Py, Pz);
	model(VtxCube, IdxFront, TexFront, World);
	model(VtxCube, IdxBack, TexBack, World);
	model(VtxCube, IdxRight, TexRight, World);
	model(VtxCube, IdxLeft, TexLeft, World);
	model(VtxCube, IdxTop, TexTop, World);
	model(VtxCube, IdxBottom, TexBottom, World);
}

//�Q�[�����C���֐�----------------------------------------------
void gmain()
{
	window("Love", 1920, 1080);

	createGraphics();
	
	lightDirection(0,-1,0);
	lightAmbient(0.7f, 0.7f, 0.7f);

	VEC campos(0,1.5,-7);
	VEC lookat(0, 0, 0);
	VEC up(0,1,0);
	setView(campos, lookat, up);
	
	while (!quit()) {
		if (escKeyPressed()) closeWindow();


		clear(0.2f, 0.4f, 0.8f);
		drawFloor();
		drawDog();
		present();
	}
}
