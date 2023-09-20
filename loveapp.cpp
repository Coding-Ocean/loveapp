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

		//fontFace("ＫＦひま字ふで");
		//print("エヴァンゲリオン");

		//fontFace("HGP明朝E");
		//print("時に、西暦2017年");
		//
		//text("使徒、襲来", mouseX, mouseY);
		//
		//fontFace("PixelMplus12");
		//print("ゆうしゃはたおれた");

		//fontFace("あずきフォント");
		//fontSize(100);
		//print("「%d番、習近平と申します」",cnt);
		

		//fontFace("ＫＦひま字ふで");
		print("cnt:%d", cnt);
		//fontFace("Comic Sans MS", 0);
		print("Welcome to Coding Ocean!");
		//fontFace("jokerman", 0);
		print("Welcome to Coding Ocean!");

		present();
	}

	destroyFontMap();
}
