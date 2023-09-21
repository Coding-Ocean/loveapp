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

		fill(1, 1, 1);
		print("%s%d", str, cnt);
		print("AKB:%.0f", mouseX);
		print("HKT:%.0f", mouseY);


		present();
	}
}

/*
		int size = 100;
		fontSize(size);
		fill(0, 1, 0);
		float x=500, y=0;
		fontFace("ＭＳ ゴシック");
		text("#include<stdio.h>", x, y); y += size;
		text("int main(){", x, y); y += size;
		text("    printf(\"Hello\");", x, y); y += size;
		text("}", x, y); y += size*2;
		fontFace("ＭＳ Ｐゴシック");
		text("#include<stdio.h>", x, y); y += size;
		text("int main(){", x, y); y += size;
		text("    printf(\"Hello\");", x, y); y += size;
		text("}", x, y); y += size;

		fontFace("HGP明朝E");
		fontSize(250);
		fill(1,1,1);
		print("エヴァンゲリオン");
		print("時に、西暦%04.0f年",mouseX);
		print("使徒、襲来");

		fontFace("あずきフォント");
		fill(1, 1, 0.5f);
		text("習近平", mouseX, 800);

	USER_FONT user2("KFhimajiFUDE.otf");
		fontFace("ＫＦひま字ふで");
		fontSize(80);
		print("あけましておめでたう:%d", cnt);

	USER_FONT user1("PixelMplus12-Bold.ttf");
		fontFace("PixelMplus12");
		fontSize(100);
		print("ゆうしゃはいきかえった");

		fontFace("Comic Sans MS", 0);
		fontSize(100);
		print("Welcome to Coding Ocean!");

		fontFace("jokerman", 0);
		print("Welcome to Coding Ocean!");
*/