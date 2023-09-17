#include<cmath>
#include"../lovelib/lovelib.h"

/*--------------------------------------------
math�n�֐���lovelib��mathGraphic.cpp�ɂ���܂�
--------------------------------------------*/

//�֐���������mathGraph�ŕ`�悵�Ă��炤
float quadratic(float x)
{
	return x * x;
}
float circlePosi(float x)
{
	//�~�̕����� x*x + y*y = r*r;
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
float zero(float x)
{
	return 0;
}

void gmain()
{
	window("Love", 1920, 1080);

	//���_
	float ox = width / 2;
	float oy = height / 2;
	//�P�Ƃ���傫��
	float scl = 100;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		//���_���ړ�
		if (isPress(MOUSE_LBUTTON)) {
			ox += mouseVx;
			oy -= mouseVy;
		}
		//�P�Ƃ���傫����ύX
		scl += mouseWheel * 10;
		if (scl < 10)scl = 10;

		//�`��
		clear(0.0f, 0.0f, 0.0f);

		fill(0.8f, 0.8f, 0.8f);
		mathAxis(ox, oy, scl, 0.01f, 0);

		fill(0.9f, 0.4f, 0.4f);
		mathGraph(sin);

		fill(0.4f, 0.9f, 0.4f);
		mathGraph(quadratic);

		fill(0.9f, 0.9f, 0.4f);
		mathGraph(circlePosi, 0.01f);
		mathGraph(circleNega, 0.01f);

		fill(0.4f, 0.4f, 0.9f);
		mathGraph(cos, 0.1f, 0.2f, 0.2f);
		mathGraph(minus_cos, 0.1f, 0.2f, 0.2f);
		mathGraph(zero, 3.1415926f, 0, 1.6f);

		//mathMouseX,Y�͕��ʂ̃f�J���g���W
		fill(0.4f, 0.9f, 0.9f);
		mathArrow(0, 0, mathMouseX, mathMouseY, 0.04f, 0.2f);

		mathCircle(0, 0, 1.0f);
		mathLine(0, 0, 0, -3, 0.04f);

		present();
	}
}
