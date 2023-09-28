//デモ
#if 1
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0, 0);
		fontFace("HGP明朝E");
		fontSize(250);
		fill(1, 1, 1);
		print("エヴァンゲリオン");
		print("時に、西暦%04.0f年", mouseX);
		print("使徒、襲来");

		fontFace("あずきフォント");
		fontSize(250);
		text("習近平", mouseX, 800);
		present();
	}
}
#endif
//text関数の使い方
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
//print関数の使い方
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
//フォントフェイスを変える
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
//インストールされていないフォントを使う
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

		fontFace("Cooper Black", ANSI_CHARSET);
		fontFace("Comic Sans MS", ANSI_CHARSET);
		fontFace("Bauhaus 93", ANSI_CHARSET);
		fontFace("Kristen ITC",ANSI_CHARSET);
		fontFace("Harlow Solid Italic",ANSI_CHARSET);
		fontFace("Showcard Gothic",ANSI_CHARSET);
		fontFace("jokerman", ANSI_CHARSET);

		fontFace("HGP明朝E");
		fontSize(250);
		fill(1,1,1);
		print("エヴァンゲリオン");
		print("時に、西暦%04.0f年",mouseX);
		print("使徒、襲来");
		fontFace("あずきフォント");
		fill(1, 1, 0.5f);
		text("習近平", mouseX, 800);

		USER_FONT user1("KFhimajiFUDE.otf");
		fontFace("ＫＦひま字ふで");
		fontSize(80);
		print("エヴァンゲリオン:%d", cnt);

		USER_FONT user2("PixelMplus12-Bold.ttf");
		fontFace("PixelMplus12");
		fontSize(100);
		print("ゆうしゃはいきかえった");

*/

