#include"../lovelib/lovelib.h"

void gmain()
{
	window("Love", 800, 800);

	while (!quit()) {
		getInputState();
		if (isTrigger(KEY_ESC)) closeWindow();
		
		//•`‰æ
		clear(0.0f, 0.2f, 0.2f);



		present();
	}
}
