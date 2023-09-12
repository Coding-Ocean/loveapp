#include<cmath>
#include"../lovelib/lovelib.h"

//原点とする座標
float Ox, Oy;
//１とするドット数
float Scl;

void mathAxis(float originX, float originY, float scale, float thickness)
{
	Ox = originX;
	Oy = originY;
	Scl = scale;

	//線の太さ
	float sw = Scl * thickness;

	//軸
	//x
	line(0, Oy, width, Oy, sw);
	//y
	line(Ox, 0, Ox, height, sw);

	//目盛り
	//x
	float l = Scl * thickness * 2.5f;
	int num, i;
	float x, y;
	num = int((width-Ox) / Scl);
	for (i = 1; i <= num; i++) {
		x = Ox + Scl * i;
		line(x, Oy - l, x, Oy + l, sw);
	}
	num = int(Ox / Scl);
	for (i = 1; i <= num; i++) {
		x = Ox + Scl * -i;
		line(x, Oy - l, x, Oy + l, sw);
	}
	//y
	num = int((height-Oy) / Scl);
	for (i = 1; i <= num; i++) {
		y = Oy + Scl * i;
		line(Ox - l, y, Ox + l, y, sw);
	}
	num = int(Oy / Scl);
	for (i = 1; i <= num; i++) {
		y = Oy + Scl * -i;
		line(Ox - l, y, Ox + l, y, sw);
	}
}
void mathCircle(float x, float y, float diameter)
{
	circle(Ox + Scl * x, Oy - Scl * y, Scl * diameter, 10);
}
void mathLine(float sx, float sy, float ex, float ey, float thickness)
{
	line(Ox + Scl * sx, Oy - Scl * sy, Ox + Scl * ex, Oy - Scl * ey, Scl * thickness, 10);
}
void mathGraph(float (*func)(float), float inc, float thickness, float diameter)
{
	//正
	float maxX = (width - Ox) / Scl;
	for (float x = 0; x < maxX; x += inc) {
		mathLine(x, func(x), x + inc, func(x + inc), thickness);
		mathCircle(x, func(x), diameter);
	}
	//負
	float minX = -(Ox / Scl);
	for (float x = 0; x > minX; x -= inc) {
		mathLine(x, func(x), x - inc, func(x - inc), thickness);
		mathCircle(x, func(x), diameter);
	}
}

float func1(float x)
{
	return x;
}
float func2(float x)
{
	return x * x;
}
float func3(float x)
{
	return x * x * x;
}
float func4(float x)
{
	return cos(x);
}

void gmain()
{
	window("Love", 800, 800);

	float ox = width / 2;
	float oy = height / 2;
	float scale = width / 8;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0.0f, 0.2f, 0.2f);

		//軸
		if (isPress(MOUSE_LBUTTON)) {
			ox += mouseVx;
			oy += -mouseVy;
		}
		scale += mouseWheel * 10;
		if (scale < 10)scale = 10;
		fill(0.8f, 0.8f, 0.8f);
		mathAxis(ox, oy, scale, 0.01f);
		
		//関数グラフ
		float increments = 0.05f;
		float thickness = 0.02f;
		float plotsize = 0.02f;

		fill(0.6f, 0.6f, 0.962f);
		mathGraph(func1, increments, thickness, plotsize);
		
		fill(1.0f, 0.952f, 0.247f);
		mathGraph(func2, increments*0.5f, thickness, plotsize);

		fill(0.913f, 0.329f, 0.419f);
		mathGraph(func3, increments, thickness, plotsize);

		fill(0, 0.678f, 0.662f);
		mathGraph(func4, increments, thickness, plotsize);

		present();
	}
}
