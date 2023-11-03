#if 1
#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//頂点数：左右(-1.0～+1.0)に伸びる直方体
	const int numX = 31;//横方向頂点数
	const int numY = 8;//縦方向頂点数
	const int numVertices = numY * numX;//全頂点数

	//最左端頂点の位置。このX座標ににオフセットを足して全位置を設定していく
	float l = 0.2f;
	VEC leftP[numY] = {
		VEC(-1,-l,-l),//前面下
		VEC(-1, l,-l),//前面上
		VEC(-1, l,-l),//上面前
		VEC(-1, l, l),//上面後
		VEC(-1, l, l),//後面上
		VEC(-1,-l, l),//後面下
		VEC(-1,-l, l),//下面後
		VEC(-1,-l,-l),//下面前
	};
	//最左端頂点の法線。全部同じなので右方向の頂点にコピーしていくだけ。
	VEC leftN[numY] = {
		VEC(0,0,-1),//前面
		VEC(0,0,-1),
		VEC(0,1,0),//上面
		VEC(0,1,0),
		VEC(0,0,1),//後面
		VEC(0,0,1),
		VEC(0,-1,0),//下面
		VEC(0,-1,0),
	};

	//座標変換前の頂点要素の入れ物（定数）
	//コードを読みやすくするため、あえて構造体にしていない!!
	VEC   p[numVertices]{};//position 位置
	VEC   n[numVertices]{};//normal 法線
	float w0[numVertices]{};//weight0 重み0（行列0が影響する割合）
	float w1[numVertices]{};//weight1 重み1（行列1が影響する割合）
	//p, n, w0, w1を設定
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

	//三角形数とインデックス数
	const int numTriangles = numY * (numX - 1);//1列は８つの三角形
	const int numIndices = numTriangles * 3;
	//インデックスの入れ物
	unsigned indices[numIndices]{};
	//インデックスを設定
	int j = 0;
	for (int i = 0; i < numTriangles/2; i++) {
		int k = i * 2;
		//左上の三角形のインデックス
		indices[j++] = k + 0; 
		indices[j++] = k + 9; 
		indices[j++] = k + 1;
		//右下の三角形のインデックス
		indices[j++] = k + 0; 
		indices[j++] = k + 8; 
		indices[j++] = k + 9;
	}
	
	//ワールド座標変換行列２つ
	MAT mat0;//この行列が頂点や法線に影響する割合が"w0"
	MAT mat1;//この行列が頂点や法線に影響する割合が"w1"
	//回転行列用ラジアン
	float r0;
	float r1;
	//三角関数用ラジアン
	float rad = 0;

	//座標変換後の値を入れる頂点の構造体
	struct VERTEX_ {
		VEC p;
		VEC n;
		float u, v;
	};
	//座標変換後の値を入れる頂点群
	VERTEX_ vertices[numVertices]{};
	//メンバp、nにはメインループ内で座標返還後の値をセットする
	//uvは座標変換に影響を受けないのでここで入れておく
	float ofstU = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		for (int j = 0; j < numY; j++) {
			vertices[i * 8 + j].u = ofstU * i;
			vertices[i * 8 + j].v = float(1 - j % 2);
		}
	}

	//テクスチャ読み込み
	int textureId = loadImage("silver.png");

	//ワイヤーフレーム表示フラッグ
	bool wireFlag = false;

	//ライティング
	specularOn();
	lightDirection(0,-0.5,0.5f);

	//カメラ
	setView(VEC(0,0,-4), VEC(0,0,0), VEC(0,1,0));

	//メインループ。座標変換と描画を繰り返す
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
		r0 = cosf(rad*3) * 2.0f;
		r1 = sinf(rad*2) * 1.5f;
		rad += 0.005f;

		//行列をつくる
		mat0.identity();
		mat0.mulRotateX(r0);
		mat1.identity();
		mat1.mulRotateZ(r1);

		//座標変換
		for (int i = 0; i < numVertices; i++) {
			//位置。行列計算後の位置にWeight(行列が影響する割合)を掛ける
			vertices[i].p = mul(p[i], mat0) * w0[i];
			vertices[i].p += mul(p[i], mat1) * w1[i];
			//法線ベクトル。位置と同様の計算をする
			vertices[i].n = mul(n[i], mat0) * w0[i];
			vertices[i].n += mul(n[i], mat1) * w1[i];
		}

		//描画
		clear(0.0f, 0.0f, 0.0f);
		model_(vertices, indices, numTriangles, textureId);
		present();
	}
}














#else
//説明用
#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//頂点数：左右(-1.0～+1.0)に伸びる直方体
	const int numX = 5;//横方向頂点数
	const int numY = 8;//縦方向頂点数
	const int numVertices = numY * numX;//全頂点数

	//最左端頂点の位置。このX座標ににオフセットを足して全位置を設定していく
	float l = 0.2f;
	VEC leftP[numY] = {
		VEC(-1,-l,-l),//前面下
		VEC(-1, l,-l),//前面上
		VEC(-1, l,-l),//上面前
		VEC(-1, l, l),//上面後
		VEC(-1, l, l),//後面上
		VEC(-1,-l, l),//後面下
		VEC(-1,-l, l),//下面後
		VEC(-1,-l,-l),//下面前
	};
	//最左端頂点の法線。全部同じなので右方向の頂点にコピーしていくだけ。
	VEC leftN[numY] = {
		VEC(0,0,-1),//前面
		VEC(0,0,-1),
		VEC(0,1,0),//上面
		VEC(0,1,0),
		VEC(0,0,1),//後面
		VEC(0,0,1),
		VEC(0,-1,0),//下面
		VEC(0,-1,0),
	};

	//座標変換前の頂点要素の入れ物（定数）
	//読みやすくするため、あえて構造体にしていない!!
	VEC   p[numVertices]{};//position 位置
	VEC   n[numVertices]{};//normal 法線
	float w0[numVertices]{};//weight0 重み0（行列0が影響する割合）
	float w1[numVertices]{};//weight1 重み1（行列1が影響する割合）
	//p, n, w0, w1を設定
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

	//三角形数とインデックス数
	const int numTriangles = numY * (numX - 1);//1列は８つの三角形
	const int numIndices = numTriangles * 3;
	//インデックスの入れ物
	unsigned indices[numIndices]{};
	//インデックスを設定
	int j = 0;
	for (int i = 0; i < numTriangles / 2; i++) {
		int k = i * 2;
		//左上の三角形のインデックス
		indices[j++] = k + 0;
		indices[j++] = k + 9;
		indices[j++] = k + 1;
		//右下の三角形のインデックス
		indices[j++] = k + 0;
		indices[j++] = k + 8;
		indices[j++] = k + 9;
	}

	//ワールド座標変換行列２つ
	MAT mat0;//この行列が頂点や法線に影響する割合が"w0"
	MAT mat1;//この行列が頂点や法線に影響する割合が"w1"
	//回転行列用ラジアン
	float r0;
	float r1;
	//三角関数用ラジアン
	float rad = 0;
	//アニメーション状態切り替え
	int state = 0;

	//座標返還後の値を入れる頂点の構造体
	struct VERTEX_ {
		VEC p;
		VEC n;
		float u, v;
	};
	//座標変換後の値を入れる頂点群
	VERTEX_ vertices[numVertices]{};
	//メンバp、nにはメインループ内で座標返還後の値をセットする
	//uvは座標変換に影響を受けないのでここで入れておく
	float ofstU = 1.0f / (numX - 1);
	for (int i = 0; i < numX; i++) {
		for (int j = 0; j < numY; j++) {
			vertices[i * 8 + j].u = ofstU * i;
			vertices[i * 8 + j].v = float(1-j % 2);
		}
	}

	//テクスチャ読み込み
	int texSilver = loadImage("silver.png");
	int textureId = 0;

	//ワイヤーフレーム表示フラッグ
	bool wireFlag = false;
	//cullnone();
	//ライティング
	specularOn();
	lightDirection(0, -0.5, 0.5f);
	lightAmbient(0.4f,0.4f,0.4f);

	//カメラ
	setView(VEC(0, 1, -4), VEC(0, 0, 0), VEC(0, 1, 0));

	//メインループ。座標変換と描画を繰り返す
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		//ワイヤーフレーム⇔ソリッド、表示切替
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

		//座標変換
		for (int i = 0; i < numVertices; i++) {
			//位置。行列計算後の位置にWeight(行列が影響する割合)を掛ける
			vertices[i].p = mul(p[i], mat0) * w0[i];
			vertices[i].p += mul(p[i], mat1) * w1[i];
			//法線ベクトル。位置と同様の計算をする
			vertices[i].n = mul(n[i], mat0) * w0[i];
			vertices[i].n += mul(n[i], mat1) * w1[i];
		}

		//描画
		clear(0.0f, 0.1f, 0.1f);
		model_(vertices, indices, numTriangles, textureId);
		present();
	}
}
#endif