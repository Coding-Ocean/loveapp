#include<cmath>
#include"../lovelib/lovelib.h"

//���_�Ƃ�����W
static float Ox, Oy;
//�ЂƖڐ���̑傫��
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

	//�ڐ���������Ƃ���
	float x, y;
	//�ڐ���̔����̒���
	float l = sw * 5;
	//�ڐ����`�����A�J�E���^i
	int num, i;
	//������̐��̖ڐ���
	num = int((width - ox) / scl);
	for (i = 1; i <= num; i++) {
		x = ox + scl * i;
		line(x, oy - l, x, oy + l, sw);
	}
	//������̕��̖ڐ���
	num = int(ox / scl);
	for (i = 1; i <= num; i++) {
		x = ox + scl * -i;
		line(x, oy - l, x, oy + l, sw);
	}
	//������̐��̖ڐ���
	num = int((height - oy) / scl);
	for (i = 1; i <= num; i++) {
		y = oy + scl * i;
		line(ox - l, y, ox + l, y, sw);
	}
	//������̕��̖ڐ���
	num = int(oy / scl);
	for (i = 1; i <= num; i++) {
		y = oy + scl * -i;
		line(ox - l, y, ox + l, y, sw);
	}
}
void mathCircle(float x, float y, float diameter)
{
	//�X�N���[�����W�ɕϊ�
	x = Ox + Scl * x;
	y = Oy - Scl * y;
	circle(x, y, Scl * diameter);
}
void mathLine(float sx, float sy, float ex, float ey, float thickness)
{
	//�X�N���[�����W�ɕϊ�
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
	//���_�Ƃ�����W
	float ox = width / 2;
	float oy = height / 2;
	//�ЂƖڐ���̑傫��
	float scl = 100;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		//���_���ړ�
		if (isPress(MOUSE_LBUTTON)) {
			ox += mouseVx;
			oy -= mouseVy;
		}
		//�ЂƖڐ���̑傫����ύX
		scl += mouseWheel * 10;
		if (scl < 5)scl = 5;

		//�`��
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
