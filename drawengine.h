#ifndef DRAW_ENGINE
#define DRAW_ENGINE
#include <Windows.h>


class DRAWENGINE
{
private:
			HBITMAP hbitmap;
			BITMAP bitmap;
			PAINTSTRUCT paintStruct;
			HDC hdc;
			HDC hdcMem;
			HWND window_handle;
						

public:
	DRAWENGINE();
	DRAWENGINE(HWND hWnd);
	void draw(LPCSTR location, int x, int y);
	~DRAWENGINE()
	{
			 DeleteDC(hdcMem);
			 DeleteObject(hbitmap);
			 EndPaint(window_handle, &paintStruct);
			 
	}
	
};









#endif