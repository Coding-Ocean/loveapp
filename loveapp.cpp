#include"../lovelib/lovelib.h"

#include<cstdio>
void fontSize(int size);
void printInit();
void print(const char* format, ...);
void destroyFontMap();
void fontFace(const char* fontname);

void gmain()
{
	window("Love", 1920, 1080);


	int cnt = 0;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		cnt++;

		clear(0, 0.1f, 0.1f);
		printInit();

		fontSize(150);

		fontFace("HGP����E");
		fill(1,1,1);
		print("�G���@���Q���I��");
		print("���ɁA����2017�N");
		print("�g�k�P��:%d", cnt);
		
		fontFace("�������t�H���g");
		print("�K�ߕ�");

		present();
	}

	destroyFontMap();

}
