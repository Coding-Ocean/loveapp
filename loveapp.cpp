#include"../lovelib/lovelib.h"
int createFont(const char* c, int size);

void gmain()
{
	window("Love", 800, 800);

	int size = 200;
	int imgs[] = {
		createFont("‚ ",size),
		createFont(" ",size),
		createFont("‚¢",size),
		createFont("‚¤",size),
	};

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		clear(0, 0, 0);

		fill(1, 1, 1);
		for (int i = 0; i < _countof(imgs); i++) {
			image(imgs[i], size / 2+size*i, size / 2);
		}

		present();
	}
}
