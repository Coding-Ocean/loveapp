#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);

	const char* str = "cnt=";
	int cnt = 0;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		cnt++;

		clear(0, 0.1f, 0.1f);

		//fontFace("Lucida Console", 0);

		int size = 100;
		fontSize(size);

		fontFace("�l�r �S�V�b�N");
		fill(1, 1, 1);
		print("%s%d", str, cnt);
		print("AKB:%.0f", mouseX);
		print("HKT:%.0f", mouseY);
		print("jjj");

		fontFace("jokerman", 0);
		fill(0, 1, 0);
		float x=900, y=10;
		text("#include<stdio.h>", x, y); y += size;
		text("int main(){", x, y); y += size;
		text("    printf(\"Hello\");", x, y); y += size;
		text("}", x, y); y += size;

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