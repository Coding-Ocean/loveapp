#include<vector>
#include"../lovelib/lovelib.h"

void gmain()
{
	int width = 1920, height = 1080;
	window("Love", width, height);
	wireframe();

	int vtxShape[] = {
		createShape(4, 0.3f),
		createShape(6, 0.3f),
		createShape(8, 0.3f),
		createShape(10, 0.5f),
		createShape(20, 0.8f),
	};

	float len = 250;
	float ofstx = len;
	float px = ofstx;
	float py = height / 2.0f;
	float angle = 0;
	float alpha = 1;
	
	while (!quit()) {
		if (escKeyPressed()) {
			closeWindow();
		}

		clear(0.0f, 0.0f, 0.0f);

		angle += 0.01f;

		fill(1, 0.8f, 0, alpha);
		px = ofstx;
		rect(px, py, len/1.4f, len/1.4f, angle);

		px += ofstx;
		circle(px, py, len);

		for (int i = 0; i < 5; i++) {
			px += ofstx;
			shape(vtxShape[i], px, py, len, len, angle);
		}

		present();
	}
}