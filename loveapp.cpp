//�f��
#if 1
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
		text("�K�ߕ�", mouseX, 800);
		present();
	}
}
#endif
//text�֐��̎g����
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0,0,0);
		
		present();
	}
}
#endif
//print�֐��̎g����
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);

		present();
	}
}
#endif
//�t�H���g�t�F�C�X��ς���
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);

		present();
	}
}
#endif
//�C���X�g�[������Ă��Ȃ��t�H���g���g��
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);

		present();
	}
}
#endif

/*
		int size = 100;
		fontSize(size);
		fill(0, 1, 0);
		float x=500, y=0;
		fontFace("�l�r �S�V�b�N");
		text("#include<stdio.h>", x, y); y += size;
		text("int main(){", x, y); y += size;
		text("    printf(\"Hello\");", x, y); y += size;
		text("}", x, y); y += size*2;
		fontFace("�l�r �o�S�V�b�N");
		text("#include<stdio.h>", x, y); y += size;
		text("int main(){", x, y); y += size;
		text("    printf(\"Hello\");", x, y); y += size;
		text("}", x, y); y += size;

		fontFace("Cooper Black", ANSI_CHARSET);
		fontFace("Comic Sans MS", ANSI_CHARSET);
		fontFace("Bauhaus 93", ANSI_CHARSET);
		fontFace("Kristen ITC",ANSI_CHARSET);
		fontFace("Harlow Solid Italic",ANSI_CHARSET);
		fontFace("Showcard Gothic",ANSI_CHARSET);
		fontFace("jokerman", ANSI_CHARSET);

		fontFace("HGP����E");
		fontSize(250);
		fill(1,1,1);
		print("�G���@���Q���I��");
		print("���ɁA����%04.0f�N",mouseX);
		print("�g�k�A�P��");
		fontFace("�������t�H���g");
		fill(1, 1, 0.5f);
		text("�K�ߕ�", mouseX, 800);

		USER_FONT user1("KFhimajiFUDE.otf");
		fontFace("�j�e�Ђ܎��ӂ�");
		fontSize(80);
		print("�G���@���Q���I��:%d", cnt);

		USER_FONT user2("PixelMplus12-Bold.ttf");
		fontFace("PixelMplus12");
		fontSize(100);
		print("�䂤����͂�����������");

*/

