#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	srand(time(0));
	string a1;
	getline(cin, a1);
	
	wstring down = L"\u0316\u0317\u0318\u0319\u031c\u031d\u031e\u031f\u0320\u0324\u0325\u0326\u0329\u032a\u032b\u032c\u032d\u032e\u032f\u0330\u0331\u0332\u0333\u0339\u033a\u033b\u033c\u0345\u0347\u0348\u0349\u034d\u034e\u0353\u0354\u0355\u0356\u0359\u035a\u0323",
	up = L"\u030d\u030e\u0304\u0305\u033f\u0311\u0306\u0310\u0352\u0357\u0351\u0307\u0308\u030a\u0342\u0343\u0344\u034a\u034b\u034c\u0303\u0302\u030c\u0350\u0300\u0301\u030b\u030f\u0312\u0313\u0314\u033d\u0309\u0363\u0364\u0365\u0366\u0367\u0368\u0369\u036a\u036b\u036c\u036d\u036e\u035b\u0346\u031a",
	mid = L"\u0315\u031b\u0340\u0341\u0358\u0321\u0322\u0327\u0328\u0334\u0335\u0336\u034f\u035c\u035d\u035e\u035f\u0360\u0362\u0338\u0337\u0361\u0489",
	a, b;
	
	for (int i = 0; i < a1.length(); i++)
	{
		if ((int)a1[i] > -65 && (int)a1[i] < 0)
		a += (wchar_t)((int)(a1[i]) + 1104);
		else
		a += (wchar_t)(a1[i]);
	}
		
	for (int i = 0; i < a.length(); i++)
	{
		int r = rand() % 40;
		b += a[i];
		for (int i1 = 0; i1 < r + rand() % 20; i1++)
			b += down[rand() % down.length()];
		for (int i1 = 0; i1 < r + rand() % 20; i1++)
			b += up[rand() % up.length()];
		for (int i1 = 0; i1 < r + rand() % 20; i1++)
			b += mid[rand() % mid.length()];
	}

	const wchar_t* c = b.c_str();

	if (OpenClipboard(0)) {
		EmptyClipboard();
		HGLOBAL h = GlobalAlloc(GMEM_DDESHARE, sizeof(WCHAR) * (wcslen(c) + 1));
		wchar_t* d = (WCHAR*)GlobalLock(h);
		wcscpy(d, c);
		GlobalUnlock(h);
		SetClipboardData(CF_UNICODETEXT, h);
		CloseClipboard();
	}
}
