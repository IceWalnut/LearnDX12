#include "stdafx.h"

/**
 * Main windows function
 */
int WINAPI WinMain(HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nShowCmd)
{
	// Create the window
	if (!InitializeWindow(hInstance, nShowCmd, Width, Height, FullScreen))
	{
		MessageBox(0, L"Window Initialization - Failed",
			L"Error", MB_OK);
		return 0;
	}

	// start the main loop
	mainloop();

	return 0;
}


bool InitializeWindow(HINSTANCE hInstance,
	int ShowWnd,
	int width, int height,
	bool fullscreen)
{
	// If we want fullscreen, we get the monitors width and length and set the global width and length to that.
	if (fullscreen)
	{
		// `HMONITOR` stands for "Handle to a Monitor"
		// represents a handle or identifier for a physical display monitor
		/** 
		 * - MonitorFromWindow: retrieve the monitor handle associated with a given window.
		 *		This function allows you to determine on which monitor a particular window is located.
		 *		The monitor handle (`HMONITOR`) can then be used to obtain various information about the monitor,
		 *		such as its size, position and capabilities.
		 * - MONITOR_DEFAULTTONEAREST
		 *		This flag is used in Windows programming as one of the possible values for the `dwFlags` parameter
		 *		in functions that retrieve information about monitors, such as the `MonitorFromWindow` function.
		 *		Specifically, it's used to specify that the function should return a handle to the monitor that is
		 *		nearest to the specified window.
		 */
		HMONITOR hMon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);

		/**
		 * This line initializes a `MONITORINFO` structure and sets its `cbSize` member to the size of the structure.
		 * This is a common pattern used in Windows programming to ensure that the structure is correctly sized before
		 * passing it to fuctions that require it.
		 * 
		 * `cbSize` is a common member found in many structures, and it typically represents the size ofthe structure
		 * in bytes. The "cb" prefix stands for "count of bytes".
		 * 
		 * Structure:
		 *		- cbSize: Size of the structure, in bytes
		 *		- rcMonitor: A RECT structure that specifies the display monitor rectangle, in screen coordiates
		 *		- rcWork: A RECT structure that specifies the work area rectangle of the display monitor, in 
		 *			screen coordinates.
		 *		- dwFlags: A set of flags that indicate which members of the structure are valid.
		 */
		MONITORINFO monitorInfo = { sizeof(monitorInfo) };

		/**
		 * GetMonitorInfo: retrieves infomation about a display monitor
		 * Parameters:
		 *		- hMonitor: Handle to the display monitor of interest
		 *		- lpmi: Pointer to a `MONITORINFO` structure that receives information about the motitor
		 */
		GetMonitorInfo(hMon, &monitorInfo);

		width = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
		height = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;



		//---------------------------- fill out a WNDCLASSEX structure -------------------------//
		WNDCLASSEX wc;

		wc.cbSize = sizeof(WNDCLASSEX);

		wc.style = CS_HREDRAW | CS_VREDRAW;
	}
}


