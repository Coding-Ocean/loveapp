#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);

	int cnt = 0;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0.1f, 0.1f);

		fontFace("HGP����E");
		fontSize(100);
		for (int i = 0; i < 10; i++) {
			fill(1, 0.1f*i, 1);
			text("�g�k�A�P��",900,i*100);
		}

		present();
	}
}

/*
		fontFace("HGP����E");
		fontSize(250);
		fill(1,1,1);
		print("�G���@���Q���I��");
		print("���ɁA����%04.0f�N",mouseX);
		print("�g�k�A�P��");

		fontFace("�������t�H���g");
		fill(1, 1, 0.5f);
		text("�K�ߕ�", mouseX, 800);

	USER_FONT user1("PixelMplus12-Bold.ttf");
	USER_FONT user2("KFhimajiFUDE.otf");
		fontFace("�j�e�Ђ܎��ӂ�");
		fontSize(80);
		print("�����܂��Ă��߂ł���:%d", cnt);

		fontFace("PixelMplus12");
		print("�䂤����͕m��");

		fontFace("Comic Sans MS", 0);
		fontSize(100);
		print("Welcome to Coding Ocean!");

		fontFace("jokerman", 0);
		print("Welcome to Coding Ocean!");
*/