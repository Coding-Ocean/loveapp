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

	//軸
	//x
	line(0, Oy, width, Oy, Scl * thickness);
	//y
	line(Ox, 0, Ox, height, Scl * thickness);

	//目盛り
	//x
	float l = Scl * thickness * 2;
	int num = 0;
	num = (width-Ox) / Scl;
	for (int x = 1; x <= num; x++) {
		line(Ox + Scl * x, Oy - l, Ox + Scl * x, Oy + l, Scl * thickness);
	}
	num = Ox / Scl;
	for (int x = 1; x <= num; x++) {
		line(Ox + Scl * -x, Oy - l, Ox + Scl * -x, Oy + l, Scl * thickness);
	}
	//y
	num = (height-Oy) / Scl;
	for (int y = 1; y <= num; y++) {
		line(Ox - l, Oy + Scl * y, Ox + l, Oy + Scl * y, Scl * thickness);
	}
	num = Oy / Scl;
	for (int y = 1; y <= num; y++) {
		line(Ox - l, Oy + Scl * -y, Ox + l, Oy + Scl * -y, Scl * thickness);
	}
}
void mathCircle(float x, float y, float diameter)
{
	circle(Ox + Scl * x, Oy - Scl * y, Scl * diameter);
}
void mathLine(float sx, float sy, float ex, float ey, float thickness)
{
	line(Ox + Scl * sx, Oy - Scl * sy, Ox + Scl * ex, Oy - Scl * ey, Scl * thickness);
}
void mathGraph(float (*func)(float), float inc, float thickness, float diameter)
{
	float minX = -(Ox / Scl);
	float maxX = (width - Ox) / Scl;
	float sx, sy, ex, ey;
	//正
	for (sx = 0; sx < maxX; sx += inc) {
		sy = func(sx);
		ex = sx + inc;
		ey = func(ex);
		mathLine(sx, sy, ex, ey, thickness);
		mathCircle(sx, sy, diameter);
	}
	//負
	for (sx = 0; sx > minX; sx -= inc) {
		sy = func(sx);
		ex = sx - inc;
		ey = func(ex);
		mathLine(sx, sy, ex, ey, thickness);
		mathCircle(sx, sy, diameter);
	}
}

float func0(float x)
{
	return x*x;
}
float func1(float x)
{
	return x * x * x;
}
float func2(float x)
{
	return sin(x);
}
float func3(float x)
{
	return cos(x);
}

void gmain()
{
	window("Love", 800, 800);

	float ox = width / 2;
	float oy = height / 2;
	float scale = width / 8;
	float thickness = 0.025f;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0.0f, 0.2f, 0.2f);

		//軸
		if (isPress(MOUSE_LBUTTON)) {
			ox += mouseVx;
			oy += -mouseVy;
		}
		scale += mouseWheel * 5;
		if (scale < 10)scale = 10;
		fill(0.8f, 0.8f, 0.8f);
		mathAxis(ox, oy, scale, thickness);
		

		float increments = 0.2f;
		float thickness = 0.05f;
		float plotsize = thickness;

		fill(0.6f, 0.6f, 0.962f);
		mathGraph(func0, increments, thickness, plotsize);
		
		fill(1, 0.952f, 0.247f);
		mathGraph(func1, increments*0.5f, thickness, plotsize);

		fill(0.913f, 0.329f, 0.419f);
		mathGraph(func2, increments, thickness, plotsize);

		fill(0, 0.678f, 0.662f);
		mathGraph(func3, increments, thickness, plotsize);

		//円
		fill(0.913f, 0.529f, 0.119f);
		float radius = 1.5f;
		float sx = radius, sy = 0, ex = 0, ey = 0;
		int num = 8;
		float divAngle = 3.141592f * 2 / num;
		static float angle = 0;
		angle += 0.01f;
		for (int i = 0; i < num; i++) {
			ex = cos(angle + divAngle * i) * radius;
			ey = sin(angle + divAngle * i) * radius;
			//mathLine(sx, sy, ex, ey, thickness);
			//mathCircle(ex, ey, diameter*13);
			sx = ex;
			sy = ey;
		}

		present();
	}
}
