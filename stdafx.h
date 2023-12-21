#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

// Handle to the window
// HWND means "Handle to a Window"
HWND hwnd = NULL;

// name of the window (not the title)
// LPCTSTR: Long Pointer to a Consant TCHAR String
LPCTSTR WindowName = L"QzzTutsApp";

// title of the window
LPCTSTR WindowTitle = L"Qzz Window";

// width and height of the window
int Width = 800;
int Height = 600;

// is window full screen?
bool FullScreen = false;

// create a window
// HINSTANCE means "Handle to an Instance"
bool InitializeWindow(HINSTANCE hInstance,
	int ShowWnd,
	int width, int height,
	bool fullscreen);

// main application loop
void mainloop();

// callback function for windows messages
// LRESULT
// `LRESULT` stands for "Long Result" in the context of Microsoft Windows programming.
// It is a data type used to represent the result of a message processing function in the Windows API.
// Messages are a fundamental part of the communication between different parts of a Windows application,
// such as between a window and its associated window procedure.
LRESULT CALLBACK WndProc(HWND hWnd,
	UINT msg,
	/**
	 * `WPARAM` stands for "Word Parameter" in the context of MS Windows programming.
	 * It is a data type used to represent a parameter in a msg sent to a window procedure or callback function.
	 * Messages are a fundamental part of communication in Windows applications, and they are often used to 
	 * notify a window about events or to request specific actions.
	 */
	WPARAM wParam,
	/**
	 * `LPARAM` stands for "Long Parameter"
	 * `L` stands for "Long". In this context, it typically refers to a 32-bit signed integer on 32-
	 */
	LPARAM lParam);
