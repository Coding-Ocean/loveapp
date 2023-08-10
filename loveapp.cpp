#include<windows.h>
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Coding Ocean", 960, 540);
	while (!quit()) {
		if (escKeyPressed()) {
			closeWindow();
		}
		clear(0.3f, 0.6f, 1.0f);
		
		present();
	}
}