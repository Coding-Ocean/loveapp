#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//左右(-1～+1)に伸びる直方体
	const int numX = 21;//横方向頂点数
	const int numY = 8;//縦方向頂点数
	const int numVertices = numY * numX;//全頂点数

	//左側の位置。ここにオフセットを足して全位置を設定していく
	float l = 0.2f;
	VEC leftP[numY] = {
		VEC(-1,-l,-l),//前下
		VEC(-1, l,-l),//前上
		VEC(-1, l,-l),//上前
		VEC(-1, l, l),//上後
		VEC(-1, l, l),//後上
		VEC(-1,-l, l),//後下
		VEC(-1,-l, l),//下後
		VEC(-1,-l,-l),//下前
	};
	//左側の法線。全部同じなのでコピーするだけ。
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

	//座標変換前の頂点要素（定数）
	VEC p[numVertices]{};//position 位置
	VEC n[numVertices]{};//normal 法線
	float w[numVertices][2]{};//weight 行列の重み
	//p,n,wを設定
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

	//インデックスをつくる
	const int numTriangles = numY * (numX - 1);//1列は８つの三角形
	const int numIndices = numTriangles * 3;
	unsigned indices[numIndices]{};
	int j = 0;
	for (int i = 0; i < numTriangles/2; i++) {
		int k = i * 2;
		//三角形１
		indices[j++] = k + 0; 
		indices[j++] = k + 9; 
		indices[j++] = k + 1;
		//三角形２
		indices[j++] = k + 0; 
		indices[j++] = k + 8; 
		indices[j++] = k + 9;
	}
	
	//ワールド座標変換行列
	MAT mat[2];

	//座標変換後の位置と法線
	VEC p_[numVertices];
	VEC n_[numVertices];

	//描画用頂点pos,normal,uvを持つ。座標変換後ここにセットする。
	VERTEX vertices[numVertices]{};
	//uvは座標変換に影響を受けないのでここで入れておく
	float ofstU = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		for (int j = 0; j < numY; j++) {
			vertices[i * 8 + j].u = ofstU * i;
			vertices[i * 8 + j].v = float(j % 2);
		}
	}

	//テクスチャ読み込み
	int tex = 0;// loadImage("silver.png");

	//三角関数用ラジアン
	float rad=0;

	//wireframe();
	
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		//ひねる角ラジアン
		float r0 = sinf(rad) * 1.5f;
		float r1 = cosf(rad) * 1.5f;
		rad += 0.01f;

		//行列をつくる
		mat[0].identity();
		mat[0].mulRotateZ(r0);
		mat[1].identity();
		mat[1].mulRotateX(r1);

		//座標変換
		for (int i = 0; i < numVertices; i++) {
			//１頂点ずつ座標変換
			p_[i]  = w[i][0] * mat[0].mul(p[i]);
			n_[i]  = w[i][0] * mat[0].mul(n[i]);
			p_[i] += w[i][1] * mat[1].mul(p[i]);
			n_[i] += w[i][1] * mat[1].mul(n[i]);
			//変換後、描画用頂点にコピー
			vertices[i].x  = p_[i].x; 
			vertices[i].y  = p_[i].y; 
			vertices[i].z  = p_[i].z;
			vertices[i].nx = n_[i].x; 
			vertices[i].ny = n_[i].y; 
			vertices[i].nz = n_[i].z;
		}

		//描画
		clear(0.1f, 0.1f, 0.1f);
		model(vertices, indices, numTriangles, tex);
		present();
	}
}
