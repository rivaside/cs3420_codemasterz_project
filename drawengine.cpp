#include "drawengine.h"

DRAWENGINE::DRAWENGINE()
{

}

DRAWENGINE::DRAWENGINE(HWND hWnd)
{
	window_handle=hWnd;
	hdc= BeginPaint(hWnd, &paintStruct);
	hdcMem= CreateCompatibleDC(hdc);
	
}

void DRAWENGINE::draw(LPCSTR location, int x, int y)
{
	hbitmap= (HBITMAP)LoadImage(NULL, location,IMAGE_BITMAP, 0,0, LR_LOADFROMFILE );

			if(hbitmap == NULL)
			 {
				MessageBox(NULL, "Bitmap not loaded- Ensure the file 'car.bmp' is present in the project folder","Error",MB_OK);
			 }
	 SelectObject(hdcMem, hbitmap);

	 GetObject(hbitmap, sizeof(BITMAP), &bitmap);
	 
			 
	 BitBlt(hdc, x, y, bitmap.bmWidth,bitmap.bmHeight, hdcMem,0,0, SRCCOPY);
			 			
			 
}
