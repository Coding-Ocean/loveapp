#include<cmath>
#include"../lovelib/lovelib.h"

static float Ox, Oy, Scl;

void mathAxis(float ox, float oy, float scl, float thickness)
{
	Ox = ox;
	Oy = oy;
	Scl = scl;

	thickness *= scl;
	line(0, oy, width, oy, thickness);
	line(ox, 0, ox, height, thickness);

	float l = thickness * 5;
	int num, i;
	num = (width - ox) / scl;
	for (i = 1; i <= num; i++) {
		float x = ox + scl * i;
		line(x, oy - l, x, oy + l, thickness);
	}
	num = ox / scl;
	for (i = 1; i <= num; i++) {
		float x = ox + scl * -i;
		line(x, oy - l, x, oy + l, thickness);
	}
	num = (height - oy) / scl;
	for (i = 1; i <= num; i++) {
		float y = oy + scl * i;
		line(ox-l,y,ox+l,y, thickness);
	}
	num = oy / scl;
	for (i = 1; i <= num; i++) {
		float y = oy + scl * -i;
		line(ox - l, y, ox + l, y, thickness);
	}
}
void mathCircle(float x, float y, float diameter)
{
	x = Ox + Scl * x;
	y = Oy - Scl * y;
	diameter *= Scl;
	circle(x, y, diameter);
}
void mathLine(float sx, float sy, float ex, float ey, float thickness)
{
	sx = Ox + Scl * sx;
	sy = Oy - Scl * sy;
	ex = Ox + Scl * ex;
	ey = Oy - Scl * ey;
	thickness *= Scl;
	line(sx, sy, ex, ey, thickness);
}
void mathArrow(float sx, float sy, float ex, float ey, float thickness)
{
	sx = Ox + Scl * sx;
	sy = Oy - Scl * sy;
	ex = Ox + Scl * ex;
	ey = Oy - Scl * ey;
	thickness *= Scl;
	arrow(sx, sy, ex, ey, thickness);
}
void mathGraph(float (*f)(float), float inc=0.1f, float thickness=0.04f, float diameter=0.04f);
void mathGraph(float (*f)(float),float inc,float thickness, float diameter)
{
	float maxX = (width - Ox) / Scl;
	for (float x = 0; x < maxX; x += inc) {
		mathCircle(x, f(x), diameter);
		mathLine(x, f(x), x + inc, f(x + inc), thickness);
	}
	float minX = -Ox / Scl;
	for (float x = 0; x > minX; x -= inc) {
		mathCircle(x, f(x), diameter);
		mathLine(x, f(x), x - inc, f(x - inc), thickness);
	}
}

float quadratic(float x)
{
	return x * x;
}
//x*x + y*y = r*r;
float circlePosi(float x)
{
	float r = 1.5f;
	return sqrt(r * r - x * x);
}
float circleNega(float x)
{
	float r = 1.5f;
	return -sqrt(r * r - x * x);
}
float minus_cos(float x)
{
	return -cos(x);
}
float ball(float x)
{
	return 0;
}

void gmain()
{
	window("Love", 800, 800);
	float ox = width / 2;
	float oy = height / 2;
	float scl = 100;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		if (isPress(MOUSE_LBUTTON)) {
			ox += mouseVx;
			oy -= mouseVy;
		}

		scl += mouseWheel * 10;
		if (scl < 10)scl = 10;

		//•`‰æ
		clear(0.0f, 0.0f, 0.0f);

		fill(0.8f, 0.8f, 0.8f);
		mathAxis(ox,oy,scl, 0.02f);

		//fill(0.9f, 0.4f, 0.4f);
		//mathGraph(sin);
		fill(0.4f, 0.4f, 0.9f);
		mathGraph(cos,0.1f,0.2f,0.2f);
		mathGraph(minus_cos,0.1f,0.2f,0.2f);
		mathGraph(ball, 3.1415926f, 0, 0.8f);
		//fill(0.9f, 0.9f, 0.4f);
		//mathGraph(circlePosi, 0.01f);
		//mathGraph(circleNega, 0.01f);

		//mathCircle(2, 3, 0.08f);
		//mathLine(0, 0, -2, 3, 0.04f);
		//mathArrow(0, 0, -2, -3, 0.04f);

		present();
	}
}
