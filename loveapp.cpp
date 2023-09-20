#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 1920, 1080);

	int cnt = 0;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();

		clear(0, 0.1f, 0.1f);

		fontFace("HGP–¾’©E");
		fontSize(100);
		for (int i = 0; i < 10; i++) {
			fill(1, 0.1f*i, 1);
			text("Žg“kAP—ˆ",900,i*100);
		}

		present();
	}
}

/*
		fontFace("HGP–¾’©E");
		fontSize(250);
		fill(1,1,1);
		print("ƒGƒ”ƒ@ƒ“ƒQƒŠƒIƒ“");
		print("Žž‚ÉA¼—ï%04.0f”N",mouseX);
		print("Žg“kAP—ˆ");

		fontFace("‚ ‚¸‚«ƒtƒHƒ“ƒg");
		fill(1, 1, 0.5f);
		text("K‹ß•½", mouseX, 800);

	USER_FONT user1("PixelMplus12-Bold.ttf");
	USER_FONT user2("KFhimajiFUDE.otf");
		fontFace("‚j‚e‚Ð‚ÜŽš‚Ó‚Å");
		fontSize(80);
		print("‚ ‚¯‚Ü‚µ‚Ä‚¨‚ß‚Å‚½‚¤:%d", cnt);

		fontFace("PixelMplus12");
		print("‚ä‚¤‚µ‚á‚Í•mŽ€");

		fontFace("Comic Sans MS", 0);
		fontSize(100);
		print("Welcome to Coding Ocean!");

		fontFace("jokerman", 0);
		print("Welcome to Coding Ocean!");
*/