//��{�I�Ȏg����
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);
	int score = 1250;
	int counter = 0;
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);
		
		//text function(�w����W�ɕ\�������)
		fontSize(200);
		text("Stage1", 800, 100);

		//print function(���ォ��\������A�����I�ɉ��s����)
		fontSize(50);
		print("SCORE:%08d", score);
		counter++;
		if (counter >= 300) {
			counter = 0;
		}print("counter:%d", counter);

		present();
	}
}
#endif
//text�֐��ō��W�w�肷��͖̂ʓ|
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0,0,0);
		int size = 130;
		fontSize(size);
		fill(1, 1, 0.7f);
		float x = 500, y = 0;
		text("#include<stdio.h>", x, y); y += size;
		text("int main(){", x, y); y += size;
		text("    printf(\"Hello\");", x, y); y += size;
		text("}", x, y); y += size;
		present();
	}
}
#endif
//�t�H���g�t�F�C�X��ς���P
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);
		setPrintInitX(500);
		for (int i = 0; i < 7; i++) {
			switch (i) {
			case 0:fontFace("Cooper Black", ANSI_CHARSET); break;
			case 1:fontFace("Comic Sans MS", ANSI_CHARSET); break;
			case 2:fontFace("Bauhaus 93", ANSI_CHARSET); break;
			case 3:fontFace("Kristen ITC", ANSI_CHARSET); break;
			case 4:fontFace("Harlow Solid Italic", ANSI_CHARSET); break;
			case 5:fontFace("Showcard Gothic", ANSI_CHARSET); break;
			default: fontFace("jokerman", ANSI_CHARSET); break;
			}
			fontSize(150);
			fill(1, 1.0f / 6 * i, 1);
			print("%d.Coding Ocean", i);
		}
		present();
	}
}
#endif
//�t�H���g�t�F�C�X��ς���Q
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);
		fontFace("HGP����E");
		fontSize(250);
		fill(1, 1, 1);
		print("�G���@���Q���I��");
		print("���ɁA����%04.0f�N", mouseX);
		print("�g�k�A�P��");

		fontFace("�������t�H���g");
		fontSize(250);
		text("�K�ߕ�", mouseX, 780);
		present();
	}
}
#endif
//�C���X�g�[������Ă��Ȃ��t�H���g���g��
#if 0
#include<memory>
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	//����ŃC���X�g�[������Ă��Ȃ��t�H���g���g����
	//�i���[�v���ɂ���Ă͂����Ȃ��j
	USER_FONT uf("PixelMplus12-Bold.ttf");

	fontFace("PixelMplus12");
	fontSize(130);
	//������i�S�p�����O��j
	const char* src{ "�������m�̓G���N�T�[�𗎂Ƃ���" };
	size_t len = strlen(src);
	auto disp = std::make_unique<char[]>(len + 1);//�\�����镶�����������ɃR�s�[����
	len /= 2;//�S�p�������ɂ���
	int dispCnt = 0;//�\���S�p������
	int frameCnt = 0;//�t���[���J�E���g
	int interval = 10;//�t���[���Ԋu
	int rest = 80;//��~�t���[����
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		dispCnt = ++frameCnt / interval;
		if (dispCnt <= len) {
			//�R�s�[
			int i;
			for (i = 0; i < dispCnt * 2; i++) {
				disp[i] = src[i];
			}
			disp[i] = '\0';
		}
		else if (frameCnt > len * interval + rest) {
			//���Z�b�g
			frameCnt = 0;
			dispCnt = 0;
		}

		clear(0, 0, 0);
		text(disp.get(), 0, 0);
		present();
	}
}
#endif
//�x�[�X���C��(tmAscent)
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);
	
	fontSize(300);
	float tmAscent = 258;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);
		fill(0.8f, 0.8f, 0.8f);
		text("abcdefg", 0, 0);
		fill(1, 1, 0);
		line(0, tmAscent, width, tmAscent, 2);
		present();
	}
}
#endif

//Distance Point Segment
#if 1
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);
	hideCursor();

	//���_
	float ox = width / 2;
	float oy = height / 2;
	//�P�Ƃ���傫��
	float scl = 500;
	bool flag = false;

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

		fill(0.0f, 0.0f, 0.0f);
		mathAxis(ox, oy, scl, 0.01f, 10);

		VEC p{ mathMouseX,  mathMouseY };
		VEC a{ -0.5f, -0.5f };
		VEC b{ 0.5f,  0.5f };
		VEC ab = b - a;
		VEC ap = p - a;
		float t = dot(ab, ap) / dot(ab, ab);
		float save_t = t;
		if (isTrigger(KEY_SPACE)) { flag = !flag; }
		if (flag)t = clamp(t, 0, 1);
		float d = length(ap - ab * t);

		fill(0.7f, 0.7f, 0.7f);
		float thickness = 0.01f;
		mathArrow(a.x, a.y, b.x, b.y, thickness, 0.05f);
		mathArrow(a.x, a.y, p.x, p.y, thickness, 0.05f);
		fill(0.9f, 0.9f, 0.0f);
		mathLine(p.x, p.y, a.x + ab.x * t, a.y + ab.y * t, thickness);

		thickness = 0.001f;
		VEC norm{ ab.y, -ab.x };
		mathLine(a.x, a.y, a.x + norm.x, a.y + norm.y, thickness);
		mathLine(a.x, a.y, a.x - norm.x * 2, a.y - norm.y * 2, thickness);
		mathLine(b.x, b.y, b.x + norm.x * 2, b.y + norm.y * 2, thickness);
		mathLine(b.x, b.y, b.x - norm.x, b.y - norm.y, thickness);
		if (flag) {
		}
		else {
			thickness = 0.005f;
			fill(0.7f, 0.7f, 0.7f);
			mathLine(a.x, a.y, a.x + ab.x * t, a.y + ab.y * t, thickness, 5);
		}

		fill(0.2, 0.2, 0.2);
		rect(410, 85, 820, 170);
		fill(0, 1, 1);
		print("t = dot(ab,ap)/dot(ab,ab) :%0.2f", save_t);
		if (flag)print("t = clamp(t,0,1)          :%0.2f", t);
		fill(0.9, 0.9, 0.0);
		print("d = length(ap - ab*t):%0.2f", d);

		//����
		fill(1, 1, 1);
		mathText("a", a.x, a.y);
		if (flag && t >= 1); else mathText("b", b.x, b.y);
		VEC nap = normalize(ap) * 0.05;
		mathText("p", p.x + nap.x - 12.5f / scl, p.y + nap.y + 28 / scl);
		mathText("��", (a.x + ab.x * t + 5 / scl), (a.y + ab.y * t + 25 / scl));
		mathText("ab", (a.x + ab.x * t), (a.y + ab.y * t));
		fill(0, 1, 1);
		mathText("  *t", a.x + ab.x * t, a.y + ab.y * t);

		present();
	}
}
#endif
