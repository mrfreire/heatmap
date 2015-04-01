#include "../../Heatmap.h"

#include <windows.h>

static bool g_quit = false;
static Heatmap g_heatmap;
FILE* g_heatmapFile;

static LRESULT CALLBACK WindowCallback(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
    LRESULT result = 0;

    switch (message)
    {
        case WM_CLOSE:
        {
            g_quit = true;
            break;
        }
        case WM_DESTROY:
        {
            g_quit = true;
            break;
        }
        case WM_MOUSEMOVE:
        {
            POINT p;
            if (GetCursorPos(&p))
            {
                if (ScreenToClient(window, &p))
                {
                    if (g_heatmap.m_count == g_heatmap.m_capacity)
                    {
                        HeatmapUtils::PrintStream(g_heatmapFile, g_heatmap);
                        HeatmapUtils::Clear(&g_heatmap);
                    }

                    HeatmapUtils::AddPoint(&g_heatmap, p.x, p.y, 0, 0);
                }
            }
            break;
        }
        default:
        {
            result = DefWindowProc(window, message, wparam, lparam);
            break;
        }
    }

    return result;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //
    // Create window
    //

    const wchar_t kClassName[] = L"HeatmapTestWindowClass";
    const wchar_t kWindowName[] = L"Manuel Freire's Heatmap Test (2015)";

    WNDCLASS windowClass = {};
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = WindowCallback;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = kClassName;

    if (!RegisterClassW(&windowClass))
    {
        return 1;
    }

    HWND window = CreateWindowExW(
        0,
        kClassName,
        kWindowName,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        512 + 16,
        512 + 38,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (!window)
    {
        return 1;
    }

    //
    // Open heatmap file
    //

    g_heatmapFile = fopen("heatmap_out.txt", "w");
    if (!g_heatmapFile)
    {
        return 1;
    }

    //
    // Core loop
    //

    while (!g_quit)
    {
        //
        // Parse Windows messages
        //

        MSG message;

        while (PeekMessageA(&message, 0, 0, 0, PM_REMOVE))
        {
            if (message.message == WM_QUIT)
            {
                g_quit = true;
            }

            TranslateMessage(&message);
            DispatchMessageA(&message);
        }
    }

    HeatmapUtils::PrintStream(g_heatmapFile, g_heatmap);
    
    return 0;
}
