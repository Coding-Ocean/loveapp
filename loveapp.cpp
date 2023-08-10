#include<windows.h>
#include"../lovelib/lovelib.h"
void gmain()
{
	window("Coding Ocean", 960, 540);
	while (!quit()) {
		if (escKeyPressed()) {
			closeWindow();
		}
		Sleep(1);
	}
}