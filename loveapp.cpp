#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//���_���F���E(-1.0�`+1.0)�ɐL�т钼����
	const int numX = 31;//���������_��
	const int numY = 8;//�c�������_��
	const int numVertices = numY * numX;//�S���_��

	//�������_�̈ʒu�B����X���W�ɂɃI�t�Z�b�g�𑫂��đS�ʒu��ݒ肵�Ă���
	float l = 0.2f;
	VEC leftP[numY] = {
		VEC(-1,-l,-l),//�O��
		VEC(-1, l,-l),//�O��
		VEC(-1, l,-l),//��O
		VEC(-1, l, l),//���
		VEC(-1, l, l),//���
		VEC(-1,-l, l),//�㉺
		VEC(-1,-l, l),//����
		VEC(-1,-l,-l),//���O
	};
	//�������_�̖@���B�S�������Ȃ̂ŃR�s�[���邾���B
	VEC leftN[numY] = {
		VEC(0,0,-1),//�O
		VEC(0,0,-1),
		VEC(0,1,0),//��
		VEC(0,1,0),
		VEC(0,0,1),//��
		VEC(0,0,1),
		VEC(0,-1,0),//��
		VEC(0,-1,0),
	};

	//���W�ϊ��O�̒��_�v�f�i�萔�j
	VEC   p[numVertices]{};//position �ʒu
	VEC   n[numVertices]{};//normal �@��
	float w0[numVertices]{};//weight0 �d��0�i�s�񂪉e�����銄��0�j
	float w1[numVertices]{};//weight1 �d��1�i�s�񂪉e�����銄��1�j
	//p,n,w��ݒ�
	float ofstX = 2.0f / (numX - 1);
	float ofstW = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		int k = i * 8;
		for (int j = 0; j < numY; j++) {
			//position
			p[k + j].x = leftP[j].x + ofstX * i;//�����W���E�ɂ��炵�Ă���
			p[k + j].y = leftP[j].y;
			p[k + j].z = leftP[j].z;
			//normal
			n[k + j] = leftN[j];
			//wieght
			w0[k + j] = 1.0f - ofstW * i; //1.0 ���� 0.0
			w1[k + j] = ofstW * i;		  //0.0 ���� 1.0
		}
	}

	//�C���f�b�N�X������
	const int numTriangles = numY * (numX - 1);//1��͂W�̎O�p�`
	const int numIndices = numTriangles * 3;
	unsigned indices[numIndices]{};
	int j = 0;
	for (int i = 0; i < numTriangles/2; i++) {
		int k = i * 2;
		//�O�p�`�P
		indices[j++] = k + 0; 
		indices[j++] = k + 9; 
		indices[j++] = k + 1;
		//�O�p�`�Q
		indices[j++] = k + 0; 
		indices[j++] = k + 8; 
		indices[j++] = k + 9;
	}
	
	//���[���h���W�ϊ��s��Q��
	MAT mat0, mat1;

	//���W�ϊ���̈ʒu�Ɩ@��
	VEC p_[numVertices];
	VEC n_[numVertices];

	//�`��p���_pos,normal,uv�����B���W�ϊ��ケ���ɃZ�b�g����B
	VERTEX vertices[numVertices]{};
	//uv�͍��W�ϊ��ɉe�����󂯂Ȃ��̂ł����œ���Ă���
	float ofstU = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		for (int j = 0; j < numY; j++) {
			vertices[i * 8 + j].u = ofstU * i;
			vertices[i * 8 + j].v = float(j % 2);
		}
	}

	//�e�N�X�`���ǂݍ���
	int tex = loadImage("silver.png");

	//�O�p�֐��p���W�A��
	float rad = 0;

	//���C���[�t���[���\���t���b�O
	bool wireFlag = false;

	specularOn();
	
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
	
		//���C���[�t���[���̃\���b�h�A�\���ؑ�
		if (isTrigger(KEY_SPACE)) {
			wireFlag = !wireFlag;
			if (wireFlag)wireframe();
			else solid();
		}

		//�Ђ˂郉�W�A���l
		float r0 = sinf(rad) * 1.5f;
		float r1 = cosf(rad) * 1.5f;
		rad += 0.03f;

		//�s�������
		mat0.identity();
		mat0.mulRotateZ(r0);
		mat1.identity();
		mat1.mulRotateX(r1);

		//���W�ϊ�
		for (int i = 0; i < numVertices; i++) {
			//�ʒu�B�s��v�Z��̈ʒu��Weight(�s�񂪉e�����銄��)���|����
			p_[i] = mul(p[i], mat0) * w0[i];
			p_[i] += mul(p[i], mat1) * w1[i];
			//�@���x�N�g���B�ʒu�Ɠ��l�̌v�Z������
			n_[i] = mul(n[i], mat0) * w0[i];
			n_[i] += mul(n[i], mat1) * w1[i];
			//�ϊ���A�`��p���_�ɃR�s�[
			vertices[i].x = p_[i].x;
			vertices[i].y = p_[i].y;
			vertices[i].z = p_[i].z;
			vertices[i].nx = n_[i].x;
			vertices[i].ny = n_[i].y;
			vertices[i].nz = n_[i].z;
		}

		//�`��
		clear(0.f, 0.f, 0.f);
		model(vertices, indices, numTriangles, tex);
		present();
	}
}
