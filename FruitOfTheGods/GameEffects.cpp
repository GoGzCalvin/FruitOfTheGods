#include "GameEffects.h"

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
		cout << word[i];
		Sleep(millisec);
	}
	cout << endl;
}

void DelayText(int millisec, string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		cout << word[i];
		//this_thread::sleep_for(chrono::milliseconds(millisec));
		Sleep(millisec);
	}
}

void DelayTextWithSkip(int millisec, string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		cout << word[i];
		Sleep(millisec);
	}
	cout << endl;
}



