#include"../lovelib/lovelib.h"


void gmain()
{
	window("Love", 1920, 1080);

	const int num = 10;
	VERTEX vertices[num]{};
	
	VEC p[num]{};
	VEC n[num]{};
	float w[num][2]{};

	float divX = 1.0f / (num / 2 - 1);
	float divW = 0.5f / (num / 2 - 1);
	for (int i = 0; i < num; i+=2) {
		p[i].x     = -1.0f + divX * i;
		p[i + 1].x = p[i].x;
		p[i].y = 0.5f;
		p[i + 1].y = -0.5f;
		n[i] = n[i+1]= { 0,0,-1 };
		w[i][0] = 1 - divW * i;
		w[i][1] = 1 - w[i][0];
		w[i + 1][0] = w[i][0];
		w[i + 1][1] = w[i][1];
	}

	int numTriangles = num-2;
	int numIndices = numTriangles * 3;
	unsigned* indices = new unsigned[numIndices] {};
	int j = 0;
	for (int i = 0; i < numTriangles/2; i++) {
		int k = i * 2;
		indices[j++] = k + 0; 
		indices[j++] = k + 1; 
		indices[j++] = k + 2;
		indices[j++] = k + 2; 
		indices[j++] = k + 1; 
		indices[j++] = k + 3;
	}

	VEC p_[num];
	VEC n_[num];

	MAT m[2];
	
	float rad=0;
	wireframe();

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		rad += 0.01f;
		float rx0 = sin(rad) * 1.2f;
		float rx1 = cos(rad) * 1.2f;
		m[0].identity();
		m[0].mulRotateX(rx0);
		m[1].identity();
		m[1].mulRotateX(rx1);

		for (int i = 0; i < num; i++) {
			p_[i]  = w[i][0] * m[0].mul(p[i]);
			n_[i]  = w[i][0] * m[0].mul(n[i]);
			p_[i] += w[i][1] * m[1].mul(p[i]);
			n_[i] += w[i][1] * m[1].mul(n[i]);
			vertices[i].x  = p_[i].x; 
			vertices[i].y  = p_[i].y; 
			vertices[i].z  = p_[i].z;
			vertices[i].nx = n_[i].x; 
			vertices[i].ny = n_[i].y; 
			vertices[i].nz = n_[i].z;
		}

		clear(0.2, 0.4, 0.8);
		model(vertices, indices, numTriangles);
		present();

	}
	delete[]indices;
}
