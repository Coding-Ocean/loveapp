#include<cmath>
#include"../lovelib/lovelib.h"

//原点とする座標
static float Ox, Oy;
//ひと目盛りの大きさ
static float Scl;

void mathAxis(float ox, float oy, float scl, float thickness=0.01f)
{
	//set globals
	Ox = ox;
	Oy = oy;
	Scl = scl;

	//stroke weight
	float sw = scl * thickness;
	if (sw < 1.0f)sw = 1;
	//axis X
	line(0, oy, width, oy, sw);
	//axis Y
	line(ox, 0, ox, height, sw);

	//目盛りを引くところ
	float x, y;
	//目盛りの半分の長さ
	float l = sw * 5;
	//目盛りを描く数、カウンタi
	int num, i;
	//ｘ軸上の正の目盛り
	num = int((width - ox) / scl);
	for (i = 1; i <= num; i++) {
		x = ox + scl * i;
		line(x, oy - l, x, oy + l, sw);
	}
	//ｘ軸上の負の目盛り
	num = int(ox / scl);
	for (i = 1; i <= num; i++) {
		x = ox + scl * -i;
		line(x, oy - l, x, oy + l, sw);
	}
	//ｙ軸上の正の目盛り
	num = int((height - oy) / scl);
	for (i = 1; i <= num; i++) {
		y = oy + scl * i;
		line(ox - l, y, ox + l, y, sw);
	}
	//ｙ軸上の負の目盛り
	num = int(oy / scl);
	for (i = 1; i <= num; i++) {
		y = oy + scl * -i;
		line(ox - l, y, ox + l, y, sw);
	}
}
void mathCircle(float x, float y, float diameter)
{
	//スクリーン座標に変換
	x = Ox + Scl * x;
	y = Oy - Scl * y;
	circle(x, y, Scl * diameter);
}
void mathLine(float sx, float sy, float ex, float ey, float thickness)
{
	//スクリーン座標に変換
	sx = Ox + Scl * sx;
	sy = Oy - Scl * sy;
	ex = Ox + Scl * ex;
	ey = Oy - Scl * ey;
	line(sx, sy, ex, ey, Scl * thickness);
}
void mathGraph(float (*f)(float), float inc=0.1f, float thickness=0.04f, float diameter=0.04f)
{
	float maxX = (width - Ox) / Scl;
	for (float x = 0; x <= maxX; x += inc) {
		mathCircle(x, f(x), diameter);
		mathLine(x, f(x), x + inc, f(x + inc), thickness);
	}
	float minX = -Ox / Scl;
	for (float x = 0; x >= minX; x -= inc) {
		mathCircle(x, f(x), diameter);
		mathLine(x, f(x), x - inc, f(x - inc), thickness);
	}
}
float quadratic(float x)
{
	return x * x;
}
float cubic(float x)
{
	return x * x * x;
}
void gmain()
{
	window("Love",1920,1080);
	//原点とする座標
	float ox = width / 2;
	float oy = height / 2;
	//ひと目盛りの大きさ
	float scl = 100;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		//原点を移動
		if (isPress(MOUSE_LBUTTON)) {
			ox += mouseVx;
			oy -= mouseVy;
		}
		//ひと目盛りの大きさを変更
		scl += mouseWheel * 10;
		if (scl < 5)scl = 5;

		//描画
		clear(0.0f, 0.2f, 0.2f);

		fill(0.8f, 0.8f, 0.8f);
		mathAxis(ox, oy, scl);

		fill(0.9f, 0.9f, 0.2f);
		mathGraph(quadratic);
		fill(0.4f, 0.9f, 0.4f);
		mathGraph(cubic);
		fill(0.9f, 0.4f, 0.4f);
		mathGraph(sin);
		fill(0.4f, 0.4f, 0.9f);
		mathGraph(cos);

		present();
	}
}
