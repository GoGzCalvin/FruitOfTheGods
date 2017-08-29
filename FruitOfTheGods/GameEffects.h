#include <iostream> // printing to the screen
#include <windows.h> // changing the color
using namespace std;


void ColorPicker(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void TimedPause(int millisec)
{
	Sleep(millisec);
}

void DelayText(int millisec, char word[])
{
	for (int i = 0; i < strlen(word); i++)
	{
		cout << word[i];
		//this_thread::sleep_for(chrono::milliseconds(millisec));
		Sleep(millisec);
	}

}
void DelayTextWithSkip(int millisec, char word[])
{
	for (int i = 0; i < strlen(word); i++)
	{
		int rando = rand() % 15 + 1;
		ColorPicker(rando);
		cout << word[i];
		Sleep(millisec);
	}
	cout << endl;
}


void main()
{
	ColorPicker(7);
	DelayTextWithSkip(300, "SLLOOOOWWWWWW MOOOTTTIIOOON");
	TimedPause(5000);
	cout << "Hello World" << endl;

	cout << "Hello World" << endl;


	while (true) {}
}