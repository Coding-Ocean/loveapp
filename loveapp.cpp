//基本的な使い方
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
		
		//text function(指定座標に表示される)
		fontSize(200);
		text("Stage1", 800, 100);

		//print function(左上から表示され、自動的に改行する)
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
//text関数で座標指定するのは面倒
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
//フォントフェイスを変える１
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
//フォントフェイスを変える２
#if 0
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
		text("習近平", mouseX, 780);
		present();
	}
}
#endif
//インストールされていないフォントを使う
#if 0
#include<memory>
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Love", 1920, 1080);

	//これでインストールされていないフォントが使える
	//（ループ中にいれてはいけない）
	USER_FONT uf("PixelMplus12-Bold.ttf");

	fontFace("PixelMplus12");
	fontSize(130);
	//文字列（全角文字前提）
	const char* src{ "白魔導士はエリクサーを落とした" };
	size_t len = strlen(src);
	auto disp = std::make_unique<char[]>(len + 1);//表示する文字だけここにコピーする
	len /= 2;//全角文字数にする
	int dispCnt = 0;//表示全角文字数
	int frameCnt = 0;//フレームカウント
	int interval = 10;//フレーム間隔
	int rest = 80;//停止フレーム数
	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		dispCnt = ++frameCnt / interval;
		if (dispCnt <= len) {
			//コピー
			int i;
			for (i = 0; i < dispCnt * 2; i++) {
				disp[i] = src[i];
			}
			disp[i] = '\0';
		}
		else if (frameCnt > len * interval + rest) {
			//リセット
			frameCnt = 0;
			dispCnt = 0;
		}

		clear(0, 0, 0);
		text(disp.get(), 0, 0);
		present();
	}
}
#endif
//ベースライン(tmAscent)
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

