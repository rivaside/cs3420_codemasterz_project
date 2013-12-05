#include<Windows.h>
#include<conio.h>
#include"carsimulator.h"
#include"drawengine.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsgId, WPARAM wParam,
							LPARAM lParam);

//create a carsimulator object


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    static char name[]="Traffic Simulaor";
    
    HWND hWnd;
    MSG msg;
    WNDCLASS wndClass;
    wndClass.style=0;
    wndClass.lpfnWndProc=WindowProc;
    wndClass.cbClsExtra=0;
    wndClass.cbWndExtra=0;
    wndClass.hbrBackground=(HBRUSH)GetStockObject(GRAY_BRUSH);
    wndClass.hIcon=LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor=LoadCursor(NULL, IDC_ARROW);
    wndClass.hInstance=hInstance;
    wndClass.lpszMenuName=NULL;
    wndClass.lpszClassName=name;
    
    if(RegisterClass(&wndClass) == 0)
    {
	   MessageBox(0, "The Window is not registered", "Message", MB_OK);
	   return 0;
    }
    
    hWnd=CreateWindow(name, name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,  CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    
    if(hWnd==0)
    {
	   return 0;
    }
    
	ShowWindow(hWnd, SW_MAXIMIZE);
    UpdateWindow(hWnd);
    
    while(GetMessage(&msg, NULL, 0, 0))
    {
	   TranslateMessage(&msg);
	   DispatchMessage(&msg);
    }
    msg.wParam;

	

return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsgId, WPARAM wParam, LPARAM lParam)
{
	switch(uMsgId)
	{
		case WM_PAINT:
			{
				int numCars=100;
				double lightSpeed=3;
				double carspeed=.50;
				double progLength=60;

				CARSIMULATOR car(hWnd, numCars, lightSpeed, carspeed, progLength);
				car.run(hWnd);//run program inside window. pass window handle argument for window access 
				
			 return 0;
			}
		case WM_DESTROY:
			{
				PostQuitMessage(0);
				return 0;
			}
		default:
	 return DefWindowProc(hWnd, uMsgId, wParam, lParam);
		}
}

