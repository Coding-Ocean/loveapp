#include"../lovelib/lovelib.h"


void gmain()
{
	window("Love", 1920, 1080);

	const int num = 50;
	VERTEX vtx[num]{};
	
	VEC p[num]{};
	VEC n[num]{};
	float weight[num][2]{};

	float div = 1.0f / (num / 2 - 1);
	for (int i = 0; i < num; i+=2) {
		p[i].x     = -1.0f + div * i;
		p[i + 1].x = p[i].x;
		p[i].y = 0.5f;
		p[i + 1].y = -0.5f;
		n[i] = n[i+1]= { 0,0,-1 };
	}
	div = 0.5f / (num / 2 - 1);
	for (int i = 0; i < num; i += 2) {
		weight[i][0] = 1 - div * i;
		weight[i][1] = 1 - weight[i][0];
		weight[i + 1][0] = weight[i][0];
		weight[i + 1][1] = weight[i][1];
	}

	int numTriangles = num-2;
	int numIndices = numTriangles * 3;
	unsigned* idx = new unsigned[numIndices] {};
	int j = 0;
	for (int i = 0; i < numTriangles/2; i++) {
		int k = i * 2;
		idx[j++] = k + 0; 
		idx[j++] = k + 1; 
		idx[j++] = k + 2;
		idx[j++] = k + 2; 
		idx[j++] = k + 1; 
		idx[j++] = k + 3;
	}

	VEC p_[num];
	VEC n_[num];

	MAT m[2];
	
	float rx = 0;
	float rad=0;
	//wireframe();
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		rad += 0.01f;
		rx = sin(rad)*1.5f;
		float rx2 = cos(rad) * 1.5f;
		m[0].identity();
		m[0].mulRotateX(rx);
		m[1].identity();
		m[1].mulRotateX(rx2);
		for (int i = 0; i < num; i++) {
			p_[i]  = weight[i][0] * m[0].mul(p[i]);
			n_[i]  = weight[i][0] * m[0].mul(n[i]);
			p_[i] += weight[i][1] * m[1].mul(p[i]);
			n_[i] += weight[i][1] * m[1].mul(n[i]);
			vtx[i].x  = p_[i].x; vtx[i].y  = p_[i].y; vtx[i].z  = p_[i].z;
			vtx[i].nx = n_[i].x; vtx[i].ny = n_[i].y; vtx[i].nz = n_[i].z;
		}

		clear(0.2, 0.2, 0.2);
		model(vtx,idx,numTriangles);
		present();

	}
	delete[]idx;
}
