#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//���E(-1�`+1)�ɐL�т钼����
	const int numX = 21;//���������_��
	const int numY = 8;//�c�������_��
	const int numVertices = numY * numX;//�S���_��

	//�����̈ʒu�B�����ɃI�t�Z�b�g�𑫂��đS�ʒu��ݒ肵�Ă���
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
	//�����̖@���B�S�������Ȃ̂ŃR�s�[���邾���B
	VEC leftN[numY] = {
		VEC(0,0,-1),
		VEC(0,0,-1),
		VEC(0,1,0),
		VEC(0,1,0),
		VEC(0,0,1),
		VEC(0,0,1),
		VEC(0,-1,0),
		VEC(0,-1,0),
	};

	//���W�ϊ��O�̒��_�v�f�i�萔�j
	VEC p[numVertices]{};//position �ʒu
	VEC n[numVertices]{};//normal �@��
	float w[numVertices][2]{};//weight �s��̏d��
	//p,n,w��ݒ�
	float ofstX = 2.0f / (numX - 1);
	float ofstW = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		for (int j = 0; j < numY; j++) {
			//position
			p[i*8+j].x = leftP[j].x + ofstX * i;
			p[i*8+j].y = leftP[j].y;
			p[i*8+j].z = leftP[j].z;
			//normal
			n[i*8+j]   = leftN[j];
			//wieght
			w[i*8+j][0] = 1.0f - ofstW * i;
			w[i*8+j][1] = ofstW * i;
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
	
	//���[���h���W�ϊ��s��
	MAT mat[2];

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
	int tex = 0;// loadImage("silver.png");

	//�O�p�֐��p���W�A��
	float rad=0;

	//wireframe();
	
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		//�Ђ˂�p���W�A��
		float r0 = sinf(rad) * 1.5f;
		float r1 = cosf(rad) * 1.5f;
		rad += 0.01f;

		//�s�������
		mat[0].identity();
		mat[0].mulRotateZ(r0);
		mat[1].identity();
		mat[1].mulRotateX(r1);

		//���W�ϊ�
		for (int i = 0; i < numVertices; i++) {
			//�P���_�����W�ϊ�
			p_[i]  = w[i][0] * mat[0].mul(p[i]);
			n_[i]  = w[i][0] * mat[0].mul(n[i]);
			p_[i] += w[i][1] * mat[1].mul(p[i]);
			n_[i] += w[i][1] * mat[1].mul(n[i]);
			//�ϊ���A�`��p���_�ɃR�s�[
			vertices[i].x  = p_[i].x; 
			vertices[i].y  = p_[i].y; 
			vertices[i].z  = p_[i].z;
			vertices[i].nx = n_[i].x; 
			vertices[i].ny = n_[i].y; 
			vertices[i].nz = n_[i].z;
		}

		//�`��
		clear(0.1f, 0.1f, 0.1f);
		model(vertices, indices, numTriangles, tex);
		present();
	}
}
