#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <Windows.h>
#include <iostream>

using namespace std;
using namespace cv;

int reduction = 30;
int x_reduction = 1;
void MouseMove(int x, int y)
{
	double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);

	INPUT Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE;
	Input.mi.dx = x * x_reduction;
	Input.mi.dy = fy / reduction;
	::SendInput(1, &Input, sizeof(INPUT));
}

void r99(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 30;
	x_reduction = 1;
	if (cnt <= 10) {
		x = 0;
		y = 1;
	}
	else if (cnt > 10 && cnt <= 17) {
		x = -1;
		y = 1;
		x_reduction = 1;
	}
	MouseMove(x, y);
}

void spitfire(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 53) {
		x = 0;
		y = 1;
	}
	else if (cnt > 53 && cnt < 75) {
		x = 0;
		y = 1;
		reduction = 120;
	}
	else if (cnt >= 75 && cnt < 120) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 120;
	}
	else {
		x = -1;
		y = 1;
		reduction = 85;
		x_reduction = 1;
	}
	MouseMove(x, y);
}

void r301(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 15) {
		x = -1;
		y = 1;
		reduction = 40;
		x_reduction = 1;
	}
	else if (cnt > 15 && cnt < 25) {
		x = 1;
		y = 1;
		reduction = 120;
	}
	else if (cnt >= 25 && cnt < 35) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 80;
	}
	else if (cnt >= 35 && cnt < 50) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 100;
	}
	else if (cnt >= 50 && cnt < 70) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 100;
	}
	else if (cnt >= 70) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 80;
	}
	MouseMove(x, y);
}

void vk(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 22) {
		x = 1;
		y = 1;
		reduction = 70;
		x_reduction = 1;
	}
	else if (cnt > 22 && cnt < 35) {
		x = 0;
		y = 1;
		reduction = 90;
	}

	else if (cnt >= 35 && cnt < 50) {
		x = -1;
		y = 1;
		x_reduction = 1;
		reduction = 120;
	}
	else if (cnt >= 50 && cnt < 70) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 100;
	}
	else if (cnt >= 70) {
		x = 1;
		y = 1;
		x_reduction = 1;
		reduction = 80;
	}
	MouseMove(x, y);
}

void havoc(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt <= 22) {
		x = 0;
		y = 0;
		reduction = 70;
		x_reduction = 2;
	}
	else if (cnt > 22 && cnt < 35) {
		x = 0;
		y = 1;
		reduction = 30;
	}

	else if (cnt >= 35 && cnt < 50) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 30;
	}
	else if (cnt >= 50 && cnt < 70) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 40;
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
	}
	MouseMove(x, y);
}

void lstar(int cnt) {
	int x = 0;
	int y = 1;
	reduction = 80;
	x_reduction = 1;
	if (cnt < 8) {
		x = 1;
		y = 1;
		reduction = 30;
		x_reduction = 1;
	}
	if (cnt >= 8 && cnt < 22) {
		x = 1;
		y = 1;
		reduction = 30;
		x_reduction = 0.5;
	}
	else if (cnt >= 22 && cnt < 35) {
		x = 1;
		y = 1;
		reduction = 30;
	}

	else if (cnt >= 35 && cnt < 50) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 30;
	}
	else if (cnt >= 50 && cnt < 70) {
		x = 0;
		y = 1;
		x_reduction = 1;
		reduction = 40;
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
	height = windowsize.bottom / 1;  //change this to whatever size you want to resize to
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

int main(int argc, char **argv)
{
	HWND hwndDesktop = GetDesktopWindow();
	namedWindow("output", WINDOW_NORMAL);
	int key = 0;
	int frame_width = 1920;
	int frame_height = 1080;

	int state = 0;
	POINT pt;
	int cnt = 0;
	int key = 0;
	while (1)
	{
		Mat src = hwnd2mat(hwndDesktop);
		Mat cropped = src(Rect(1100, 680, 120, 32));
		int white = 0;
		cvtColor(cropped, cropped, CV_BGR2GRAY);
		threshold(cropped, cropped, 160, 255, THRESH_BINARY);
		white = countNonZero(cropped);

		state = GetKeyState(VK_LBUTTON);
		if (state == -127 || state == -128) {
			cnt++;
			if (white > 900 && white < 920) {
				r301(cnt);
				cout << "r301" << endl;
			}
			else if (white > 1260 && white < 1280) {
				havoc(cnt);
				cout << "havoc" << endl;
			}
			else if (white > 920 && white < 940) {
				r99(cnt);
				cout << "r99" << endl;
			}
			else if (white > 1132 && white < 1150) {
				vk(cnt);
				cout << "vk" << endl;
			}
			else if (white > 1320 && white < 1340) {
				spitfire(cnt);
				cout << "spitfire" << endl;
			}
			else if (white > 1680 && white < 1700) {
				lstar(cnt);
				cout << "lstar" << endl;
			}
		}
		else {
			cnt = 0;
		}
	}
	return 0;
}
