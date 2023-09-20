#include"../lovelib/lovelib.h"

#include<cstdio>
void fontFace(const char* fontname, unsigned char charset = SHIFTJIS_CHARSET);
void fontSize(int size);
void printInit();
void print(const char* format, ...);
void destroyFontMap();
void text(const char* str, float x, float y);

#include<string>
class USER_FONT
{
private:
	std::string Filename;
public:
	USER_FONT(const char* filename)
		:Filename(filename)
	{
		AddFontResourceEx(filename, FR_PRIVATE, 0);
	}
	~USER_FONT() {
		RemoveFontResourceEx(Filename.c_str(), FR_PRIVATE, 0);
	}
};

void gmain()
{
	window("Love", 1920, 1080);

	//USER_FONT user1("PixelMplus12-Bold.ttf");
	USER_FONT user2("KFhimajiFUDE.otf");
	
	int cnt = 0;

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		cnt++;

		clear(0, 0.1f, 0.1f);
		printInit();


		fontSize(20);
		fill(1,1,1);

		//fontFace("�j�e�Ђ܎��ӂ�");
		//print("�G���@���Q���I��");

		//fontFace("HGP����E");
		//print("���ɁA����2017�N");
		//
		//text("�g�k�A�P��", mouseX, mouseY);
		//
		//fontFace("PixelMplus12");
		//print("�䂤����͂����ꂽ");

		//fontFace("�������t�H���g");
		//fontSize(100);
		//print("�u%d�ԁA�K�ߕ��Ɛ\���܂��v",cnt);
		

		//fontFace("�j�e�Ђ܎��ӂ�");
		print("cnt:%d", cnt);
		//fontFace("Comic Sans MS", 0);
		print("Welcome to Coding Ocean!");
		//fontFace("jokerman", 0);
		print("Welcome to Coding Ocean!");

		present();
	}

	destroyFontMap();
}
