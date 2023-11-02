#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//頂点数：左右(-1.0～+1.0)に伸びる直方体
	const int numX = 31;//横方向頂点数
	const int numY = 8;//縦方向頂点数
	const int numVertices = numY * numX;//全頂点数

	//左側頂点の位置。このX座標ににオフセットを足して全位置を設定していく
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
	//左側頂点の法線。全部同じなのでコピーするだけ。
	VEC leftN[numY] = {
		VEC(0,0,-1),//前
		VEC(0,0,-1),
		VEC(0,1,0),//上
		VEC(0,1,0),
		VEC(0,0,1),//後
		VEC(0,0,1),
		VEC(0,-1,0),//下
		VEC(0,-1,0),
	};

	//座標変換前の頂点要素（定数）
	VEC   p[numVertices]{};//position 位置
	VEC   n[numVertices]{};//normal 法線
	float w0[numVertices]{};//weight0 重み0（行列が影響する割合0）
	float w1[numVertices]{};//weight1 重み1（行列が影響する割合1）
	//p,n,wを設定
	float ofstX = 2.0f / (numX - 1);
	float ofstW = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		int k = i * 8;
		for (int j = 0; j < numY; j++) {
			//position
			p[k + j].x = leftP[j].x + ofstX * i;//ｘ座標を右にずらしていく
			p[k + j].y = leftP[j].y;
			p[k + j].z = leftP[j].z;
			//normal
			n[k + j] = leftN[j];
			//wieght
			w0[k + j] = 1.0f - ofstW * i; //1.0 から 0.0
			w1[k + j] = ofstW * i;		  //0.0 から 1.0
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
	
	//ワールド座標変換行列２つ
	MAT mat0, mat1;

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
	int tex = loadImage("silver.png");

	//三角関数用ラジアン
	float rad = 0;

	//ワイヤーフレーム表示フラッグ
	bool wireFlag = false;

	specularOn();
	
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
	
		//ワイヤーフレーム⇔ソリッド、表示切替
		if (isTrigger(KEY_SPACE)) {
			wireFlag = !wireFlag;
			if (wireFlag)wireframe();
			else solid();
		}

		//ひねるラジアン値
		float r0 = sinf(rad) * 1.5f;
		float r1 = cosf(rad) * 1.5f;
		rad += 0.03f;

		//行列をつくる
		mat0.identity();
		mat0.mulRotateZ(r0);
		mat1.identity();
		mat1.mulRotateX(r1);

		//座標変換
		for (int i = 0; i < numVertices; i++) {
			//位置。行列計算後の位置にWeight(行列が影響する割合)を掛ける
			p_[i] = mul(p[i], mat0) * w0[i];
			p_[i] += mul(p[i], mat1) * w1[i];
			//法線ベクトル。位置と同様の計算をする
			n_[i] = mul(n[i], mat0) * w0[i];
			n_[i] += mul(n[i], mat1) * w1[i];
			//変換後、描画用頂点にコピー
			vertices[i].x = p_[i].x;
			vertices[i].y = p_[i].y;
			vertices[i].z = p_[i].z;
			vertices[i].nx = n_[i].x;
			vertices[i].ny = n_[i].y;
			vertices[i].nz = n_[i].z;
		}

		//描画
		clear(0.f, 0.f, 0.f);
		model(vertices, indices, numTriangles, tex);
		present();
	}
}
