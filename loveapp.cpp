//��{�I�Ȏg����
#if 1
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

