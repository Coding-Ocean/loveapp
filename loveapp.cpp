#if 1
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	//fontFace("Comic Sans MS", ANSI_CHARSET);
	//fontFace("jokerman", ANSI_CHARSET);
	//fontFace("Showcard Gothic",ANSI_CHARSET);
	//fontFace("Harlow Solid Italic", ANSI_CHARSET);

	fontSize(150);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0.1f, 0.1f);
		fill(0,0.5f,1);
		print("Welcome to Coding Ocean!");
		for (int i = 0; i < 3; i++) {
			if (i == 0)
				fill(1, 0, 0);
			else if (i == 1)
				fill(0, 1, 0);
			else 
				fill(1, 1, 0);
			print("AKB%d", i + 46);
		}
		present();
	}
}
#endif
#if 0
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	USER_FONT userFont("KFhimajiFUDE.otf");
	fontFace("ＫＦひま字ふで");
	fontSize(150);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0.1f, 0.1f);
		print("あるところに");
		print("おじいさんと");
		print("おばあさんが");
		print("しんでいました");
		present();
	}
}
#endif

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

	fontFace("Harlow Solid Italic",ANSI_CHARSET);
	fontFace("Showcard Gothic",ANSI_CHARSET);
	fontFace("Comic Sans MS", ANSI_CHARSET);
	fontFace("jokerman", ANSI_CHARSET);
*/