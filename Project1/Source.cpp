#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <Windows.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <math.h>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <chrono>

#include <tlhelp32.h>
#include <tchar.h>


#define ROI Rect(950, 240, 45, 90)

using namespace std;
using namespace cv;

int reduction = 30;
int x_reduction = 1;
void MouseMove(int x, int y)
{
	double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
	//double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);

	INPUT Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE;
	Input.mi.dx = x * x_reduction*7.5;       
	Input.mi.dy = fy / reduction*7.5;		
	::SendInput(1, &Input, sizeof(INPUT));
}

void fun_alternator(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 22;
	x_reduction = 1;
	if (cnt <= 8) {
		x = 0;
		y = 1;
	}
	else if (cnt > 8 && cnt <= 15) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 30;
	}
	else if (cnt > 15 && cnt <= 22) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 60;
	}
	else if (cnt > 22) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 40;
	}
	MouseMove(x, y);
}

void fun_re45(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 40;

	if (cnt <= 3) {
		x = 0;
		y = 1;
		x_reduction = 1;
	}
	else if (cnt > 3 && cnt <= 7) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 60;
	}
	else if (cnt > 7 && cnt <= 10) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}
	else if (cnt > 10 && cnt <=20) {
		x = -1;
		y = 0;
		x_reduction = 1;
		reduction = 40;
	}
	MouseMove(x, y);
	MouseMove(x, y);
}

/*
void fun_r99(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 20;
	x_reduction = 1;
	if (cnt <= 3) {
		x = 0;
		y = 1;
	}
	else if (cnt > 3 && cnt <= 6) {
		x = -2;
		y = 1;
		x_reduction = 1;
		reduction = 10;
	}
	else if (cnt > 6 && cnt <= 10) {
		x = 2;
		y = 1;
		x_reduction = 1;
		//reduction = 25;
		reduction = 45;
	}
	else if (cnt > 10 && cnt <= 16) {
		x = -1;
		y = 1;
		x_reduction = 1;
		//reduction = 25;
		reduction = 35;
	}
	else if (cnt > 16 && cnt <= 18) {
		x = -1;
		y = 0;
		x_reduction = 1;
		reduction = 25;
	}
	else if (cnt > 18 && cnt <= 22) {
		x = 3;
		y = 1;
		x_reduction = 1;
		reduction = 40;
	}
	else if (cnt > 22 && cnt <= 30) {
		x = -1;
		y = 0;
		x_reduction = 1;
		reduction = 80;
	}
	else if (cnt > 30) {
		x = 0;//1;
		y = -1;
		x_reduction = 1;
		reduction = 30;
	}
	MouseMove(x, y);
}*/

void fun_r99(int cnt) {
	int x = -1;
	int y = 1;
	reduction = 25;
	x_reduction = 1;
	if (cnt <= 3) {
		x = 0;
		y = 1;
	}
	else if (cnt > 3 && cnt <= 5) {
		x = -2;
		y = 1;
		x_reduction = 1;
		reduction = 20;
	}
	else if (cnt > 5 && cnt <= 8) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 15;
	}
	else if (cnt > 8 && cnt <= 16) {
		x = 0;
		y = 1;
		x_reduction = 1;
		//reduction = 25;
		reduction = 60;
	}
	else if (cnt > 16 && cnt <= 18) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 35;
	}
	else if (cnt > 18 && cnt <= 22) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 40;
	}
	else if (cnt > 22 && cnt <= 30) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 80;
	}
	else if (cnt > 30) {
		x = 0;//1;
		y = -1;
		x_reduction = 1;
		reduction = 30;
	}
	MouseMove(x, y);
}

void fun_volt(int cnt) {
	int x = -1;
	int y = 1;
	reduction = 25;
	x_reduction = 1;
	if (cnt <= 3) {
		x = 0;
		y = 1;
	}
	else if (cnt > 3 && cnt <= 5) {
		x = -2;
		y = 1;
		x_reduction = 1;
		reduction = 20;
	}
	else if (cnt > 5 && cnt <= 8) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 15;
	}
	else if (cnt > 8 && cnt <= 12) {
		x = 0;
		y = -1;
		x_reduction = 1;
		//reduction = 25;
		reduction = 60;
	}
	else if (cnt > 12 && cnt <= 18) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 35;
	}
	else if (cnt > 18 && cnt <= 22) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 40;
	}
	else if (cnt > 22 && cnt <= 30) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 80;
	}
	else if (cnt > 30) {
		x = 0;//1;
		y = -1;
		x_reduction = 1;
		reduction = 30;
	}
	MouseMove(x, y);
}

void fun_spitfire(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;

	if (cnt <= 5) {
		reduction = 40;
		x = 1;
		y = 1;
	}
	else if (cnt > 5 && cnt <= 8) {
		x = 0;
		y = 1;
		reduction = 55;
	}
	else if (cnt > 8 && cnt <= 11) {
		x = -2;
		y = 0;
		reduction = 20;
	}
	else if (cnt > 11 && cnt <= 15) {
		x = 1.5;
		y = 1;
		reduction = 80;
	}
	else if (cnt > 15 && cnt <= 20) {
		x = 0;
		y = 0;
		reduction = 80;
	}
	else if (cnt > 20 && cnt <= 30) {
		x = 1;
		y = 1;
		reduction = 80;
	}
	else if (cnt > 30 && cnt <= 45) {
		x = 0;
		y = 1;
		reduction = 80;
	}
	else if (cnt > 45 && cnt < 60) {
		x = -2;
		y = 0;
		reduction = 90;
	}
	else if (cnt >= 60 && cnt < 100) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 60;
	}
	else if (cnt >= 100 && cnt < 120) {
		x = -3;
		y = 1;
		x_reduction = 1;
		reduction = 65;
	}
	else {
		x = 1;
		y = 1;
		reduction = 85;
		x_reduction = 1;
	}
	MouseMove(x, y);
}

void fun_r301(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 2) {
		x = -1;
		y = 1;
		reduction = 20;
		x_reduction = 1;
	}
	if (cnt > 2 && cnt <= 4) {
		x = -1;
		y = 1;
		reduction = 30;
		x_reduction = 1;
	}
	else if (cnt > 4 && cnt <= 5) {
		x = 0;
		y = 1;
		reduction = 60;
	}
	
	else if (cnt > 5 && cnt <= 6) {
		x = 0; //1;
		y = 1;
		reduction = 60;
	}
	else if (cnt > 6 && cnt <= 8) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 80;
	}
	else if (cnt > 8 && cnt <= 11) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}
	else if (cnt > 11 && cnt <= 17) {
		x = 1;
		y = 0;
		x_reduction = 1;
		reduction = 50;
	}
	else if (cnt > 17 && cnt < 23) {
		x = -2;
		y = 0;
		x_reduction = 1;
		reduction = 70;
	}
	else if (cnt >= 23 && cnt < 25) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 100;
	}
	else if (cnt >= 25) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 80;
	}
	MouseMove(x, y);
}

void fun_flatline(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 2) {
		x = 1.5;
		y = 1;
		reduction = 30;
		x_reduction = 1;
	}
	if (cnt > 2 && cnt < 5) {
		x = 1.5;
		y = 1;
		reduction = 35;
		x_reduction = 1;
	}
	if (cnt >= 5 && cnt <  8) {
		x = 1;
		y = 1;
		reduction = 35;
		x_reduction = 1;
	}
	if (cnt >= 8 && cnt < 10) {
		x = -1;
		y = 0;
		reduction = 30;
		x_reduction = 1;
	}
	else if (cnt >= 10 && cnt < 13) {
		x = -1;
		y = 0;
		reduction = 50;
	}
	else if (cnt >= 13 && cnt < 15) {
		x = 0;
		y = 0;
		reduction = 50;
	}
	else if (cnt >= 15 && cnt < 24) {
		x = 1;
		y = 1;
		reduction = 40;
	}
	else if (cnt > 24 && cnt < 30) {
		x = 1;
		y = 0;
		reduction = 40;
	}

	else if (cnt >= 30 && cnt < 40) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 30;
	}
	else if (cnt >= 40 && cnt < 60) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 70;
	}
	else if (cnt >= 60) {
		x = -2;
		y = 1;
		x_reduction = 1;
		reduction = 80;
	}
	MouseMove(x, y);
}

void fun_havoc(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 5) {
		x = 0;
		y = 0;
		reduction = 70;
		x_reduction = 2;
	}
	else if (cnt > 5 && cnt < 8) {
		x = -2.5;
		y = 1;
		reduction = 15;
	}
	else if (cnt >= 8 && cnt < 15) {
		x = 0.5;
		y = 1;
		x_reduction = 1;
		reduction = 25;
	}
	else if (cnt >= 15 && cnt < 20) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 35;
	}
	else if (cnt >= 20 && cnt < 26) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 35;
	}
	else if (cnt >= 26 && cnt < 32) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 35;
	}
	else if (cnt >= 32 && cnt < 37) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 100;
	}
	else if (cnt >= 37 && cnt < 43) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 100;
	}
	else if (cnt >= 43 && cnt < 70) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 60;
	}
	else if (cnt >= 70 && cnt < 80) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}
	else if (cnt >= 80 && cnt < 100) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}
	else if (cnt >= 100 && cnt < 120) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 70;
	}
	else if (cnt >= 120 && cnt < 140) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 120;
	}
	else if (cnt >= 140) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}
	MouseMove(x, y);
}

void fun_lstar(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt < 5) {
		x = 1.5;
		y = 1;
		reduction = 20;
		x_reduction = 1;
	}
	else if (cnt >= 5 && cnt < 8) {
		x = -0.5;
		y = 1;
		reduction = 30;
		x_reduction = 1;
	}
	else if (cnt >= 8 && cnt < 12) {
		x = -1;
		y = 1;
		reduction = 45;
		x_reduction = 1;
	}
	else if (cnt >= 12 && cnt < 17) {
		x = 1;
		y = 1;
		reduction = 50;
		x_reduction = 1;
	}
	else if (cnt >= 17 && cnt < 24) {
		x = 1;
		y = 1;
		reduction = 35;
		x_reduction = 1;
	}	
	else if (cnt >= 24 && cnt < 32) {
		x = -1;
		y = 1;
		reduction = 80;
		x_reduction = 1;
	}
	else if (cnt >= 32 && cnt < 70) {
		x = 0;
		y = 1;
		reduction = 40;
		x_reduction = 1;
	}	/*
	else if (cnt >= 17 && cnt < 22) {
		x = 0;
		y = 1;
		reduction = 15;
		x_reduction = 1;
	}
	else if (cnt >= 22 && cnt < 35) {
		x = 1;
		y = 1;
		reduction = 40;
	}

	else if (cnt >= 35 && cnt < 50) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 40;
	}
	else if (cnt >= 50 && cnt < 70) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 45;
	}
	else if (cnt >= 70 && cnt < 80) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}
	else if (cnt >= 80 && cnt < 100) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}
	else if (cnt >= 100 && cnt < 120) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 70;
	}
	else if (cnt >= 120 && cnt < 140) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 120;
	}
	else if (cnt >= 140) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 50;
	}*/
	MouseMove(x, y);
}

void fun_hemlok(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt == 1) {
		x = -1;
		y = 1;
		reduction = 20;
		x_reduction = 1;
	}
		if (cnt == 2 ) {
		x = 2;
		y = 1;
		reduction = 30;
		x_reduction = 1;
	}
		if (cnt > 2) {
			x = 1;
			y = 0;
			reduction = 30;
			x_reduction = 1;
		}
	MouseMove(x, y);
}

void fun_prowler(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 1) {
		x = 1;
		y = 1;
		//reduction = 30;
		reduction = 10;
		x_reduction = 1;
	}
	else if (cnt == 2) {
		x = 0;
		y = 1;
		reduction = 30;
		x_reduction = 1;
	}
	else if (cnt>2 && cnt <= 4) {
		x = 0;
		y = 0;
		reduction = 30;
		x_reduction = 1;
	}
	else if (cnt>4 && cnt <=11) {
		x = 1;
		y = 1;
		reduction = 35;
		x_reduction = 1;
	}

	else if (cnt>11 && cnt <= 17) {
		x = -1;
		y = 0;
		reduction = 25;
		x_reduction = 1;
	}
	else if (cnt>17 && cnt <= 23) {
		x = -1;
		y = 1;
		reduction = 25;
		x_reduction = 1;
	}
	/*
	else if (cnt>20 && cnt <= 28) {
		x = -3;
		y = 1;
		reduction = 40;
		x_reduction = 1;
	}
	else if (cnt>28 && cnt <= 35) {
		x = 0;
		y = 1;
		reduction = 60;
		x_reduction = 1;
	}
	else if (cnt>35 ) {
		x = 0;
		y = 1;
		reduction = 35;
		x_reduction = 1;
	}*/
	MouseMove(x, y);
}

void fun_devotion(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 6) {
		x = 1;
		y = 1;
		reduction = 20;
		x_reduction = 1;
	}
	else if (cnt > 6 && cnt <= 9) {
		x = -2;
		y = 1;
		reduction = 15;
	}
	else if (cnt > 9 && cnt <= 15) {
		x = 2;
		y = 0;
		reduction = 25;
	}
	else if (cnt > 15 && cnt <= 23) {
		x = 0;
		y = 1;
		reduction = 60;
	}
	else if (cnt > 23 && cnt <= 30) {
		x = 0;
		y = 0;
		reduction = 80;
	}
	else if (cnt > 30 && cnt <= 40) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 60;
	}
	else if (cnt >= 40 && cnt < 65) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 60;
	}
	else if (cnt >= 65 && cnt < 80) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 60;
	}
	else if (cnt >= 80 && cnt < 100) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 20;
	}
	else if (cnt >= 100 && cnt < 120) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 70;
	}
	else if (cnt >= 120 && cnt < 140) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 120;
	}
	else if (cnt >= 140) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 50;
	}
	MouseMove(x, y);
}

void fun_g7(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt == 1) {
		x = 0;
		y = 1;
		reduction = 30;
		x_reduction = 2;
	}
	if (cnt == 2) {
		x = 0;
		y = 1;
		reduction = 20;
		x_reduction = 2;
	}
	if (cnt == 3) {
		x = -1;
		y = 0;
		reduction = 20;
		x_reduction = 2;
	}
	else if (cnt >= 140) {
		x = 0;
		y = 0;
		x_reduction = 1;
		reduction = 50;
	}
	MouseMove(x, y);
}

void fun_wingman(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 1) {
		x = -1;
		y = 1;
		reduction = 20;
		x_reduction = 1;
	}
	else if (cnt >= 2 & cnt <4 ) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 20;
	}
	MouseMove(x, y);
}


Mat hwnd2mat(HWND hwnd)
{
	HDC hwindowDC, hwindowCompatibleDC;

	int height, width, srcheight, srcwidth;
	HBITMAP hbwindow;
	Mat src;
	BITMAPINFOHEADER  bi;

	hwindowDC = GetDC(hwnd);
	hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
	SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

	RECT windowsize;    // get the height and width of the screen
	GetClientRect(hwnd, &windowsize);

	srcheight = windowsize.bottom;
	srcwidth = windowsize.right;
	height = windowsize.bottom / 1;  
	width = windowsize.right / 1;

	src.create(height, width, CV_8UC4);

	// create a bitmap
	hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
	bi.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
	bi.biWidth = width;
	bi.biHeight = -height;  //this is the line that makes it draw upside down or not
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	// use the previously created device context with the bitmap
	SelectObject(hwindowCompatibleDC, hbwindow);
	// copy from the window device context to the bitmap device context
	StretchBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, 0, 0, srcwidth, srcheight, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
	GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow

																									   // avoid memory leak
	DeleteObject(hbwindow);
	DeleteDC(hwindowCompatibleDC);
	ReleaseDC(hwnd, hwindowDC);

	return src;
}

//get process hwnd
HWND g_HWND = NULL;
BOOL CALLBACK EnumWindowsProcMy(HWND hwnd, LPARAM lParam)
{
	DWORD lpdwProcessId;
	GetWindowThreadProcessId(hwnd, &lpdwProcessId);
	if (lpdwProcessId == lParam)
	{
		g_HWND = hwnd;
		return FALSE;
	}
	return TRUE;
}

DWORD GetProcId(const wchar_t* procName) {
	DWORD procId = 0; 
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry)) {
			do {
				wchar_t * wcstring = new wchar_t[strlen(procEntry.szExeFile) + 1];
				size_t convertedChars = 0;
				mbstowcs_s(&convertedChars, wcstring, strlen(procEntry.szExeFile)+1, procEntry.szExeFile, _TRUNCATE);
				if (!_wcsicmp(wcstring, procName)) {
					cout << "FOUND" << endl;
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);
	return procId;
}

int main(int argc, char **argv)
{

	HWND hwndDesktop = GetDesktopWindow();
	namedWindow("apex", WINDOW_AUTOSIZE);
	//get process hnwd
	DWORD procId = (unsigned int)GetProcId(L"r5apex.exe"); 
	cout << (unsigned int)procId  << endl;
	EnumWindows(EnumWindowsProcMy, procId);
	int key = 0;
	int frame_width = 1920;
	int frame_height = 1080;

	int state = 0;
	POINT pt;
	int cnt = 0;


	Mat hemlok = imread("resource/hemlok.png");
	Mat alternator = imread("resource/alternator.png");
	Mat flatline = imread("resource/flatline.png");
	Mat havoc = imread("resource/havoc.png");
	Mat lstar = imread("resource/lstar.png");
	Mat prowler = imread("resource/prowler.png");
	Mat r99 = imread("resource/r99.png");
	Mat r301 = imread("resource/r301.png");
	Mat spitfire = imread("resource/spitfire.png");
	Mat re45 = imread("resource/re45.png");
	Mat devotion = imread("resource/devotion.png");
	Mat radius = imread("resource/radius.png");
	Mat g7 = imread("resource/g7.png");
	Mat wingman = imread("resource/wingman.png");
	Mat volt = imread("resource/volt.png");



	//transform all the images
	transpose(hemlok, hemlok); flip(hemlok, hemlok, 0); hemlok = hemlok(ROI); resize(hemlok, hemlok, Size(64, 128)); cvtColor(hemlok, hemlok, CV_BGR2GRAY); threshold(hemlok, hemlok, 160, 255, THRESH_BINARY);
	transpose(alternator, alternator); flip(alternator, alternator, 0); alternator = alternator(ROI); resize(alternator, alternator, Size(64, 128)); cvtColor(alternator, alternator, CV_BGR2GRAY); threshold(alternator, alternator, 160, 255, THRESH_BINARY);
	transpose(flatline, flatline); flip(flatline, flatline, 0); flatline = flatline(ROI); resize(flatline, flatline, Size(64, 128)); cvtColor(flatline, flatline, CV_BGR2GRAY); threshold(flatline, flatline, 160, 255, THRESH_BINARY);
	transpose(havoc, havoc); flip(havoc, havoc, 0); havoc = havoc(ROI); resize(havoc, havoc, Size(64, 128)); cvtColor(havoc, havoc, CV_BGR2GRAY); threshold(havoc, havoc, 160, 255, THRESH_BINARY);
	transpose(lstar, lstar); flip(lstar, lstar, 0); lstar = lstar(ROI); resize(lstar, lstar, Size(64, 128)); cvtColor(lstar, lstar, CV_BGR2GRAY); threshold(lstar, lstar, 160, 255, THRESH_BINARY);
	transpose(prowler, prowler); flip(prowler, prowler, 0); prowler = prowler(ROI); resize(prowler, prowler, Size(64, 128)); cvtColor(prowler, prowler, CV_BGR2GRAY); threshold(prowler, prowler, 160, 255, THRESH_BINARY);
	transpose(r99, r99); flip(r99, r99, 0); r99 = r99(ROI); resize(r99, r99, Size(64, 128)); cvtColor(r99, r99, CV_BGR2GRAY); threshold(r99, r99, 160, 255, THRESH_BINARY);
	transpose(r301, r301); flip(r301, r301, 0); r301 = r301(ROI); resize(r301, r301, Size(64, 128)); cvtColor(r301, r301, CV_BGR2GRAY); threshold(r301, r301, 160, 255, THRESH_BINARY);
	transpose(spitfire, spitfire); flip(spitfire, spitfire, 0); spitfire = spitfire(ROI); resize(spitfire, spitfire, Size(64, 128)); cvtColor(spitfire, spitfire, CV_BGR2GRAY); threshold(spitfire, spitfire, 160, 255, THRESH_BINARY);
	transpose(re45, re45); flip(re45, re45, 0); re45 = re45(ROI); resize(re45, re45, Size(64, 128)); cvtColor(re45, re45, CV_BGR2GRAY); threshold(re45, re45, 160, 255, THRESH_BINARY);
	transpose(devotion, devotion); flip(devotion, devotion, 0); devotion = devotion(ROI); resize(devotion, devotion, Size(64, 128)); cvtColor(devotion, devotion, CV_BGR2GRAY); threshold(devotion, devotion, 160, 255, THRESH_BINARY);
	transpose(radius, radius); flip(radius, radius, 0); radius = radius(ROI); resize(radius, radius, Size(64, 128)); cvtColor(radius, radius, CV_BGR2GRAY); threshold(radius, radius, 160, 255, THRESH_BINARY);
	transpose(g7, g7); flip(g7, g7, 0); g7 = g7(ROI); resize(g7, g7, Size(64, 128)); cvtColor(g7, g7, CV_BGR2GRAY); threshold(g7, g7, 160, 255, THRESH_BINARY);
	transpose(wingman, wingman); flip(wingman, wingman, 0); wingman = wingman(ROI); resize(wingman, wingman, Size(64, 128)); cvtColor(wingman, wingman, CV_BGR2GRAY); threshold(wingman, wingman, 160, 255, THRESH_BINARY);
	transpose(volt, volt); flip(volt, volt, 0); volt = volt(ROI); resize(volt, volt, Size(64, 128)); cvtColor(volt, volt, CV_BGR2GRAY); threshold(volt, volt, 160, 255, THRESH_BINARY);


	//features
	vector<float> f_hemlok, f_alternator, f_flatline, f_havoc, f_lstar, f_prowler, f_r99, f_r301, f_spitfire, f_re45, f_devotion, f_radius, f_g7, f_wingman, f_volt;

	//hogs
	HOGDescriptor h_hemlok, h_alternator, h_flatline, h_havoc, h_lstar, h_prowler, h_r99, h_r301, h_spitfire, h_re45, h_devotion, h_radius, h_g7, h_wingman, h_volt;

	//hogs compute
	Mat H_hemlok, H_alternator, H_flatline, H_havoc, H_lstar, H_prowler, H_r99, H_r301, H_spitfire, H_re45, H_devotion, H_radius, H_g7, H_wingman, H_volt;

	h_hemlok.compute(hemlok, f_hemlok, Size(1, 1), Size(0, 0));
	H_hemlok.create(f_hemlok.size(), 1, CV_32FC1);
	for (int i = 0; i < f_hemlok.size(); i++)
		H_hemlok.at<float>(i, 0) = f_hemlok.at(i);

	h_alternator.compute(alternator, f_alternator, Size(1, 1), Size(0, 0));
	H_alternator.create(f_alternator.size(), 1, CV_32FC1);
	for (int i = 0; i < f_alternator.size(); i++)
		H_alternator.at<float>(i, 0) = f_alternator.at(i);

	h_flatline.compute(flatline, f_flatline, Size(1, 1), Size(0, 0));
	H_flatline.create(f_flatline.size(), 1, CV_32FC1);
	for (int i = 0; i < f_flatline.size(); i++)
		H_flatline.at<float>(i, 0) = f_flatline.at(i);

	h_havoc.compute(havoc, f_havoc, Size(1, 1), Size(0, 0));
	H_havoc.create(f_havoc.size(), 1, CV_32FC1);
	for (int i = 0; i < f_havoc.size(); i++)
		H_havoc.at<float>(i, 0) = f_havoc.at(i);

	h_lstar.compute(lstar, f_lstar, Size(1, 1), Size(0, 0));
	H_lstar.create(f_lstar.size(), 1, CV_32FC1);
	for (int i = 0; i < f_lstar.size(); i++)
		H_lstar.at<float>(i, 0) = f_lstar.at(i);

	h_prowler.compute(prowler, f_prowler, Size(1, 1), Size(0, 0));
	H_prowler.create(f_prowler.size(), 1, CV_32FC1);
	for (int i = 0; i < f_prowler.size(); i++)
		H_prowler.at<float>(i, 0) = f_prowler.at(i);

	h_r99.compute(r99, f_r99, Size(1, 1), Size(0, 0));
	H_r99.create(f_r99.size(), 1, CV_32FC1);
	for (int i = 0; i < f_r99.size(); i++)
		H_r99.at<float>(i, 0) = f_r99.at(i);

	h_r301.compute(r301, f_r301, Size(1, 1), Size(0, 0));
	H_r301.create(f_r301.size(), 1, CV_32FC1);
	for (int i = 0; i < f_r301.size(); i++)
		H_r301.at<float>(i, 0) = f_r301.at(i);

	h_spitfire.compute(spitfire, f_spitfire, Size(1, 1), Size(0, 0));
	H_spitfire.create(f_spitfire.size(), 1, CV_32FC1);
	for (int i = 0; i < f_spitfire.size(); i++)
		H_spitfire.at<float>(i, 0) = f_spitfire.at(i);

	h_re45.compute(re45, f_re45, Size(1, 1), Size(0, 0));
	H_re45.create(f_re45.size(), 1, CV_32FC1);
	for (int i = 0; i < f_re45.size(); i++)
		H_re45.at<float>(i, 0) = f_re45.at(i);

	h_devotion.compute(devotion, f_devotion, Size(1, 1), Size(0, 0));
	H_devotion.create(f_devotion.size(), 1, CV_32FC1);
	for (int i = 0; i < f_devotion.size(); i++)
		H_devotion.at<float>(i, 0) = f_devotion.at(i);

	h_radius.compute(radius, f_radius, Size(1, 1), Size(0, 0));
	H_radius.create(f_radius.size(), 1, CV_32FC1);
	for (int i = 0; i < f_radius.size(); i++)
		H_radius.at<float>(i, 0) = f_radius.at(i);

	h_g7.compute(g7, f_g7, Size(1, 1), Size(0, 0));
	H_g7.create(f_g7.size(), 1, CV_32FC1);
	for (int i = 0; i < f_g7.size(); i++)
		H_g7.at<float>(i, 0) = f_g7.at(i);

	h_wingman.compute(wingman, f_wingman, Size(1, 1), Size(0, 0));
	H_wingman.create(f_wingman.size(), 1, CV_32FC1);
	for (int i = 0; i < f_wingman.size(); i++)
		H_wingman.at<float>(i, 0) = f_wingman.at(i);

	h_volt.compute(volt, f_volt, Size(1, 1), Size(0, 0));
	H_volt.create(f_volt.size(), 1, CV_32FC1);
	for (int i = 0; i < f_volt.size(); i++)
		H_volt.at<float>(i, 0) = f_volt.at(i);
	//define all hogs in one vector 
	Mat H_weapons[] = { H_hemlok, H_alternator, H_flatline, H_havoc, H_lstar, H_prowler, H_r99, H_r301, H_spitfire, H_re45, H_devotion, H_radius, H_g7, H_wingman, H_volt };

	while (1)
	{
		auto start = chrono::steady_clock::now();
		Mat apex = hwnd2mat(g_HWND);
		cvtColor(apex, apex, CV_BGR2GRAY);
		//transpose(apex, apex); flip(apex, apex, 0); apex = apex(Rect(675, 160, 45, 90)); resize(apex, apex, Size(64, 128));
		transpose(apex, apex); flip(apex, apex, 0); apex = apex(Rect(950, 240, 45, 90)); resize(apex, apex, Size(64, 128));

		imshow("apex", apex);

		vector<float> f_apex;
		HOGDescriptor h_apex;
		Mat H_apex;

		h_apex.compute(apex, f_apex, Size(1, 1), Size(0, 0));
		H_apex.create(f_apex.size(), 1, CV_32FC1);
		for (int i = 0; i < f_apex.size(); i++)
			H_apex.at<float>(i, 0) = f_apex.at(i);

		vector<double> distance = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int j = 0; j < 15; j++) {
			for (int i = 0; i < H_apex.rows; i++)
			{
				distance[j] += abs(H_apex.at<float>(i, 0) - H_weapons[j].at<float>(i, 0));
			}
		}
		int weapon = min_element(distance.begin(), distance.end()) - distance.begin();
		if (~GetAsyncKeyState(VK_MENU) & 0x8000) {
			state = GetAsyncKeyState(VK_LBUTTON);
			if (state < 0 && GetKeyState(VK_RSHIFT)>= 0){// && GetAsyncKeyState(VK_RBUTTON)< 0) {
				cnt++;
				cout << cnt << endl;
				auto fine = chrono::steady_clock::now();

				switch (weapon)
				{
				case 0:
					cout << "hemlok" << endl;
					//fun_hemlok(cnt);
					break;
				case 1:
					cout << "alternator" << endl;
					fun_alternator(cnt);
					break;
				case 2:
					cout << "flatline" << endl;
					fun_flatline(cnt);
					break;
				case 3:
					cout << "havoc" << endl;
					fun_havoc(cnt);
					break;
				case 4:
					cout << "lstar" << endl;
					fun_lstar(cnt);
					break;
				case 5:
					cout << "prowler" << endl;
					fun_prowler(cnt);
					break;
				case 6:
					cout << "r99" << endl;
					fun_r99(cnt);
					break;
				case 7:
					cout << "r301" << endl;
					fun_r301(cnt);
					break;
				case 8:
					cout << "spitfire" << endl;
					fun_spitfire(cnt);
					break;
				case 9:
					cout << "re45" << endl;
					fun_re45(cnt);
					break;
				case 10:
					cout << "devotion" << endl;
					fun_devotion(cnt);
					break;
				case 11:
					cout << "radius" << endl;
					//fun_radius(cnt);
					break;			
				case 12:
					cout << "g7" << endl;
					fun_g7(cnt);
					break;
				case 13:
					cout << "wingman" << endl;
					//fun_wingman(cnt);
					break;
				case 14:
					cout << "volt" << endl;
					fun_volt(cnt);
					break;
			}
			}
			else {
				cnt = 0;
			}
		}
		waitKey(5);
	}
	return 0;
}