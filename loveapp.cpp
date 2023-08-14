#include<vector>
#include"../lovelib/lovelib.h"

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);

	int texFrog = loadImage("frog.png");

	while (!quit()) {
		if (escKeyPressed()) {
			closeWindow();
		}

		clear(0.8f, 0.0f, 0.4f);

		image(texFrog, width / 2.0f, height / 2.0f);

		present();
	}
}