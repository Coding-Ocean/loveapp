#if 1
#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//���_���F���E(-1.0�`+1.0)�ɐL�т钼����
	const int numX = 31;//���������_��
	const int numY = 8;//�c�������_��
	const int numVertices = numY * numX;//�S���_��

	//�ō��[���_�̈ʒu�B����X���W�ɂɃI�t�Z�b�g�𑫂��đS�ʒu��ݒ肵�Ă���
	float l = 0.2f;
	VEC leftP[numY] = {
		VEC(-1,-l,-l),//�O�ʉ�
		VEC(-1, l,-l),//�O�ʏ�
		VEC(-1, l,-l),//��ʑO
		VEC(-1, l, l),//��ʌ�
		VEC(-1, l, l),//��ʏ�
		VEC(-1,-l, l),//��ʉ�
		VEC(-1,-l, l),//���ʌ�
		VEC(-1,-l,-l),//���ʑO
	};
	//�ō��[���_�̖@���B�S�������Ȃ̂ŉE�����̒��_�ɃR�s�[���Ă��������B
	VEC leftN[numY] = {
		VEC(0,0,-1),//�O��
		VEC(0,0,-1),
		VEC(0,1,0),//���
		VEC(0,1,0),
		VEC(0,0,1),//���
		VEC(0,0,1),
		VEC(0,-1,0),//����
		VEC(0,-1,0),
	};

	//���W�ϊ��O�̒��_�v�f�̓��ꕨ�i�萔�j
	//�R�[�h��ǂ݂₷�����邽�߁A�����č\���̂ɂ��Ă��Ȃ�!!
	VEC   p[numVertices]{};//position �ʒu
	VEC   n[numVertices]{};//normal �@��
	float w0[numVertices]{};//weight0 �d��0�i�s��0���e�����銄���j
	float w1[numVertices]{};//weight1 �d��1�i�s��1���e�����銄���j
	//p, n, w0, w1��ݒ�
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

	//�O�p�`���ƃC���f�b�N�X��
	const int numTriangles = numY * (numX - 1);//1��͂W�̎O�p�`
	const int numIndices = numTriangles * 3;
	//�C���f�b�N�X�̓��ꕨ
	unsigned indices[numIndices]{};
	//�C���f�b�N�X��ݒ�
	int j = 0;
	for (int i = 0; i < numTriangles/2; i++) {
		int k = i * 2;
		//����̎O�p�`�̃C���f�b�N�X
		indices[j++] = k + 0; 
		indices[j++] = k + 9; 
		indices[j++] = k + 1;
		//�E���̎O�p�`�̃C���f�b�N�X
		indices[j++] = k + 0; 
		indices[j++] = k + 8; 
		indices[j++] = k + 9;
	}
	
	//���[���h���W�ϊ��s��Q��
	MAT mat0;//���̍s�񂪒��_��@���ɉe�����銄����"w0"
	MAT mat1;//���̍s�񂪒��_��@���ɉe�����銄����"w1"
	//��]�s��p���W�A��
	float r0;
	float r1;
	//�O�p�֐��p���W�A��
	float rad = 0;

	//���W�ϊ���̒l�����钸�_�̍\����
	struct VERTEX_ {
		VEC p;
		VEC n;
		float u, v;
	};
	//���W�ϊ���̒l�����钸�_�Q
	VERTEX_ vertices[numVertices]{};
	//�����op�An�ɂ̓��C�����[�v���ō��W�ԊҌ�̒l���Z�b�g����
	//uv�͍��W�ϊ��ɉe�����󂯂Ȃ��̂ł����œ���Ă���
	float ofstU = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		for (int j = 0; j < numY; j++) {
			vertices[i * 8 + j].u = ofstU * i;
			vertices[i * 8 + j].v = float(1 - j % 2);
		}
	}

	//�e�N�X�`���ǂݍ���
	int textureId = loadImage("silver.png");

	//���C���[�t���[���\���t���b�O
	bool wireFlag = false;

	//���C�e�B���O
	specularOn();
	lightDirection(0,-0.5,0.5f);

	//�J����
	setView(VEC(0,0,-4), VEC(0,0,0), VEC(0,1,0));

	//���C�����[�v�B���W�ϊ��ƕ`����J��Ԃ�
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
		r0 = cosf(rad*3) * 2.0f;
		r1 = sinf(rad*2) * 1.5f;
		rad += 0.005f;

		//�s�������
		mat0.identity();
		mat0.mulRotateX(r0);
		mat1.identity();
		mat1.mulRotateZ(r1);

		//���W�ϊ�
		for (int i = 0; i < numVertices; i++) {
			//�ʒu�B�s��v�Z��̈ʒu��Weight(�s�񂪉e�����銄��)���|����
			vertices[i].p = mul(p[i], mat0) * w0[i];
			vertices[i].p += mul(p[i], mat1) * w1[i];
			//�@���x�N�g���B�ʒu�Ɠ��l�̌v�Z������
			vertices[i].n = mul(n[i], mat0) * w0[i];
			vertices[i].n += mul(n[i], mat1) * w1[i];
		}

		//�`��
		clear(0.0f, 0.0f, 0.0f);
		model_(vertices, indices, numTriangles, textureId);
		present();
	}
}














#else
//�����p
#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//���_���F���E(-1.0�`+1.0)�ɐL�т钼����
	const int numX = 5;//���������_��
	const int numY = 8;//�c�������_��
	const int numVertices = numY * numX;//�S���_��

	//�ō��[���_�̈ʒu�B����X���W�ɂɃI�t�Z�b�g�𑫂��đS�ʒu��ݒ肵�Ă���
	float l = 0.2f;
	VEC leftP[numY] = {
		VEC(-1,-l,-l),//�O�ʉ�
		VEC(-1, l,-l),//�O�ʏ�
		VEC(-1, l,-l),//��ʑO
		VEC(-1, l, l),//��ʌ�
		VEC(-1, l, l),//��ʏ�
		VEC(-1,-l, l),//��ʉ�
		VEC(-1,-l, l),//���ʌ�
		VEC(-1,-l,-l),//���ʑO
	};
	//�ō��[���_�̖@���B�S�������Ȃ̂ŉE�����̒��_�ɃR�s�[���Ă��������B
	VEC leftN[numY] = {
		VEC(0,0,-1),//�O��
		VEC(0,0,-1),
		VEC(0,1,0),//���
		VEC(0,1,0),
		VEC(0,0,1),//���
		VEC(0,0,1),
		VEC(0,-1,0),//����
		VEC(0,-1,0),
	};

	//���W�ϊ��O�̒��_�v�f�̓��ꕨ�i�萔�j
	//�ǂ݂₷�����邽�߁A�����č\���̂ɂ��Ă��Ȃ�!!
	VEC   p[numVertices]{};//position �ʒu
	VEC   n[numVertices]{};//normal �@��
	float w0[numVertices]{};//weight0 �d��0�i�s��0���e�����銄���j
	float w1[numVertices]{};//weight1 �d��1�i�s��1���e�����銄���j
	//p, n, w0, w1��ݒ�
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

	//�O�p�`���ƃC���f�b�N�X��
	const int numTriangles = numY * (numX - 1);//1��͂W�̎O�p�`
	const int numIndices = numTriangles * 3;
	//�C���f�b�N�X�̓��ꕨ
	unsigned indices[numIndices]{};
	//�C���f�b�N�X��ݒ�
	int j = 0;
	for (int i = 0; i < numTriangles / 2; i++) {
		int k = i * 2;
		//����̎O�p�`�̃C���f�b�N�X
		indices[j++] = k + 0;
		indices[j++] = k + 9;
		indices[j++] = k + 1;
		//�E���̎O�p�`�̃C���f�b�N�X
		indices[j++] = k + 0;
		indices[j++] = k + 8;
		indices[j++] = k + 9;
	}

	//���[���h���W�ϊ��s��Q��
	MAT mat0;//���̍s�񂪒��_��@���ɉe�����銄����"w0"
	MAT mat1;//���̍s�񂪒��_��@���ɉe�����銄����"w1"
	//��]�s��p���W�A��
	float r0;
	float r1;
	//�O�p�֐��p���W�A��
	float rad = 0;
	//�A�j���[�V������Ԑ؂�ւ�
	int state = 0;

	//���W�ԊҌ�̒l�����钸�_�̍\����
	struct VERTEX_ {
		VEC p;
		VEC n;
		float u, v;
	};
	//���W�ϊ���̒l�����钸�_�Q
	VERTEX_ vertices[numVertices]{};
	//�����op�An�ɂ̓��C�����[�v���ō��W�ԊҌ�̒l���Z�b�g����
	//uv�͍��W�ϊ��ɉe�����󂯂Ȃ��̂ł����œ���Ă���
	float ofstU = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		for (int j = 0; j < numY; j++) {
			vertices[i * 8 + j].u = ofstU * i;
			vertices[i * 8 + j].v = float(1-j % 2);
		}
	}

	//�e�N�X�`���ǂݍ���
	int texSilver = loadImage("silver.png");
	int textureId = 0;

	//���C���[�t���[���\���t���b�O
	bool wireFlag = false;
	//cullnone();
	//���C�e�B���O
	specularOn();
	lightDirection(0, -0.5, 0.5f);
	lightAmbient(0.4f,0.4f,0.4f);

	//�J����
	setView(VEC(0, 1, -4), VEC(0, 0, 0), VEC(0, 1, 0));

	//���C�����[�v�B���W�ϊ��ƕ`����J��Ԃ�
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		//���C���[�t���[���̃\���b�h�A�\���ؑ�
		if (isTrigger(KEY_SPACE)) {
			wireFlag = !wireFlag;
			if (wireFlag)wireframe();
			else solid();
		}

		if (isTrigger(KEY_S)) {
			++state %= 3;
			rad = 0;
		}
		mat0.identity();
		mat1.identity();
		switch (state) {
		case 0:
			r0 = 0.6f - cosf(rad) * 0.6f;
			r1 = 0.6f - cosf(rad) * 0.6f;
			rad += 0.02f;
			mat0.mulRotateX(-r0);
			mat1.mulRotateX(-r1);
			textureId = 0;
			break;
		case 1:
			r0 = 0.6f - cosf(rad) * 0.6f;
			r1 = 0;
			rad += 0.02f;
			mat0.mulRotateX(-r0);
			mat1.mulRotateX(-r1);
			textureId = 0;
			break;
		case 2:
			r0 = 0.6f - cosf(rad) * 0.6f;
			r1 = 0.55f - cosf(rad) * 0.55f;
			rad += 0.02f;
			mat0.mulRotateX(-r0);
			mat1.mulRotateZ(-r1);
			textureId = 0;
			break;
		}

		//���W�ϊ�
		for (int i = 0; i < numVertices; i++) {
			//�ʒu�B�s��v�Z��̈ʒu��Weight(�s�񂪉e�����銄��)���|����
			vertices[i].p = mul(p[i], mat0) * w0[i];
			vertices[i].p += mul(p[i], mat1) * w1[i];
			//�@���x�N�g���B�ʒu�Ɠ��l�̌v�Z������
			vertices[i].n = mul(n[i], mat0) * w0[i];
			vertices[i].n += mul(n[i], mat1) * w1[i];
		}

		//�`��
		clear(0.0f, 0.1f, 0.1f);
		model_(vertices, indices, numTriangles, textureId);
		present();
	}
}
#endif