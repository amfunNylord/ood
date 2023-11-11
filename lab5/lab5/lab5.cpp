// ISpringWord.cpp : Defines the entry point for the console application.
//
#include "CEditor.h"

int main()
{
	CHistory history;
	CEditor editor(history);
	editor.Start();
	return 0;
}