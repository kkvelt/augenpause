typedef void* HANDLE;
typedef HANDLE HWND;
typedef HANDLE HINSTANCE;
typedef HANDLE HICON;
typedef HANDLE HCURSOR;
typedef HANDLE HBRUSH;
typedef HANDLE HDC;
typedef HANDLE HGDIOBJ;
typedef HANDLE HFONT;
typedef HANDLE HMENU;
typedef unsigned short WCHAR;
typedef const WCHAR* LPCWSTR;
typedef unsigned char BYTE;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef int BOOL;
typedef long LONG;
typedef unsigned long long ULONGLONG;
typedef unsigned long long UINT_PTR;
typedef unsigned long long WPARAM;
typedef long long LPARAM;
typedef long long LRESULT;
typedef LRESULT (__stdcall *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

_Static_assert(sizeof(WCHAR) == 2, "Windows requires 16-bit WCHAR");
_Static_assert(sizeof(void*) == 8, "This build targets Windows x64");
_Static_assert(sizeof(DWORD) == 4, "Windows DWORD is 32 bits");

typedef struct { LONG x, y; } POINT;
typedef struct { LONG left, top, right, bottom; } RECT;
typedef struct { HWND hwnd; UINT message; WPARAM wParam; LPARAM lParam;
                 DWORD time; POINT pt; DWORD lPrivate; } MSG;
typedef struct { HDC hdc; BOOL fErase; RECT rcPaint; BOOL fRestore;
                 BOOL fIncUpdate; BYTE rgbReserved[32]; } PAINTSTRUCT;
typedef struct { UINT cbSize, style; WNDPROC lpfnWndProc; int cbClsExtra;
                 int cbWndExtra; HINSTANCE hInstance; HICON hIcon;
                 HCURSOR hCursor; HBRUSH hbrBackground; LPCWSTR lpszMenuName;
                 LPCWSTR lpszClassName; HICON hIconSm; } WNDCLASSEXW;

typedef struct { DWORD cbSize; HWND hWnd; UINT uID, uFlags;
                 UINT uCallbackMessage; HICON hIcon; WCHAR szTip[128];
               } NOTIFYICONDATAW_V1;

_Static_assert(sizeof(MSG) == 48, "Unexpected MSG structure layout");
_Static_assert(sizeof(PAINTSTRUCT) == 72, "Unexpected PAINTSTRUCT layout");
_Static_assert(sizeof(WNDCLASSEXW) == 80, "Unexpected WNDCLASSEXW layout");
_Static_assert(sizeof(NOTIFYICONDATAW_V1) == 296, "Unexpected tray ABI layout");

#define WINAPI __stdcall
#define DLL __declspec(dllimport)


DLL HINSTANCE WINAPI GetModuleHandleW(LPCWSTR);
DLL HANDLE WINAPI CreateMutexW(void*, BOOL, LPCWSTR);
DLL DWORD WINAPI GetLastError(void);
DLL BOOL WINAPI CloseHandle(HANDLE);
DLL ULONGLONG WINAPI GetTickCount64(void);
DLL void WINAPI ExitProcess(UINT);
DLL unsigned short WINAPI RegisterClassExW(const WNDCLASSEXW*);
DLL HWND WINAPI CreateWindowExW(DWORD, LPCWSTR, LPCWSTR, DWORD,
                                 int, int, int, int, HWND, HMENU, HINSTANCE, void*);
DLL BOOL WINAPI DestroyWindow(HWND);
DLL LRESULT WINAPI DefWindowProcW(HWND, UINT, WPARAM, LPARAM);
DLL BOOL WINAPI ShowWindow(HWND, int);
DLL BOOL WINAPI SetWindowPos(HWND, HWND, int, int, int, int, UINT);
DLL BOOL WINAPI SetForegroundWindow(HWND);
DLL BOOL WINAPI InvalidateRect(HWND, const RECT*, BOOL);
DLL BOOL WINAPI UpdateWindow(HWND);
DLL int WINAPI GetSystemMetrics(int);
DLL UINT_PTR WINAPI SetTimer(HWND, UINT_PTR, UINT, void*);
DLL BOOL WINAPI KillTimer(HWND, UINT_PTR);
DLL int WINAPI GetMessageW(MSG*, HWND, UINT, UINT);
DLL BOOL WINAPI TranslateMessage(const MSG*);
DLL LRESULT WINAPI DispatchMessageW(const MSG*);
DLL void WINAPI PostQuitMessage(int);
DLL HDC WINAPI BeginPaint(HWND, PAINTSTRUCT*);
DLL BOOL WINAPI EndPaint(HWND, const PAINTSTRUCT*);
DLL BOOL WINAPI FillRect(HDC, const RECT*, HBRUSH);
DLL BOOL WINAPI GetClientRect(HWND, RECT*);
DLL int WINAPI DrawTextW(HDC, LPCWSTR, int, RECT*, UINT);
DLL HICON WINAPI LoadIconW(HINSTANCE, LPCWSTR);
DLL BOOL WINAPI SetProcessDPIAware(void);
DLL BOOL WINAPI RegisterHotKey(HWND, int, UINT, UINT);
DLL BOOL WINAPI UnregisterHotKey(HWND, int);
DLL UINT WINAPI RegisterWindowMessageW(LPCWSTR);
DLL int WINAPI MessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT);
DLL BOOL WINAPI GetCursorPos(POINT*);
DLL HMENU WINAPI CreatePopupMenu(void);
DLL BOOL WINAPI AppendMenuW(HMENU, UINT, UINT_PTR, LPCWSTR);
DLL BOOL WINAPI DestroyMenu(HMENU);
DLL BOOL WINAPI TrackPopupMenu(HMENU, UINT, int, int, int, HWND, const RECT*);
DLL BOOL WINAPI PostMessageW(HWND, UINT, WPARAM, LPARAM);
DLL BOOL WINAPI Shell_NotifyIconW(DWORD, NOTIFYICONDATAW_V1*);
DLL HFONT WINAPI CreateFontW(int, int, int, int, int, DWORD, DWORD,
                             DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, LPCWSTR);
DLL HGDIOBJ WINAPI SelectObject(HDC, HGDIOBJ);
DLL BOOL WINAPI DeleteObject(HGDIOBJ);
DLL HBRUSH WINAPI CreateSolidBrush(DWORD);
DLL int WINAPI SetBkMode(HDC, int);
DLL DWORD WINAPI SetTextColor(HDC, DWORD);
DLL BOOL WINAPI WTSRegisterSessionNotification(HWND, DWORD);
DLL BOOL WINAPI WTSUnRegisterSessionNotification(HWND);

#define WM_CREATE 0x0001u
#define WM_DESTROY 0x0002u
#define WM_CLOSE 0x0010u
#define WM_QUERYENDSESSION 0x0011u
#define WM_ENDSESSION 0x0016u
#define WM_PAINT 0x000Fu
#define WM_ERASEBKGND 0x0014u
#define WM_COMMAND 0x0111u
#define WM_TIMER 0x0113u
#define WM_DISPLAYCHANGE 0x007Eu
#define WM_WTSSESSION_CHANGE 0x02B1u
#define WM_POWERBROADCAST 0x0218u
#define PBT_APMRESUMESUSPEND 0x0007u
#define PBT_APMRESUMEAUTOMATIC 0x0012u
#define WTS_CONSOLE_DISCONNECT 0x2u
#define WTS_REMOTE_DISCONNECT 0x4u
#define WTS_SESSION_LOCK 0x7u
#define WTS_CONSOLE_CONNECT 0x1u
#define WTS_REMOTE_CONNECT 0x3u
#define WTS_SESSION_UNLOCK 0x8u
#define NOTIFY_FOR_THIS_SESSION 0u
#define WM_KEYDOWN 0x0100u
#define WM_SYSKEYDOWN 0x0104u
#define WM_HOTKEY 0x0312u
#define WM_LBUTTONDOWN 0x0201u
#define WM_RBUTTONDOWN 0x0204u
#define WM_RBUTTONUP 0x0205u
#define WM_LBUTTONUP 0x0202u
#define WM_CONTEXTMENU 0x007Bu
#define WM_APP 0x8000u
#define WM_NULL 0u
#define VK_ESCAPE 0x1Bu
#define MOD_ALT 0x0001u
#define MOD_CONTROL 0x0002u
#define MOD_SHIFT 0x0004u
#define NIM_ADD 0u
#define NIM_DELETE 2u
#define NIF_MESSAGE 1u
#define NIF_ICON 2u
#define NIF_TIP 4u
#define MF_STRING 0u
#define TPM_RIGHTBUTTON 0x0002u
#define TPM_BOTTOMALIGN 0x0020u
#define DT_CENTER 0x0001u
#define DT_VCENTER 0x0004u
#define DT_SINGLELINE 0x0020u
#define TRANSPARENT 1
#define MB_ICONERROR 0x00000010u
#define SW_HIDE 0
#define WS_POPUP 0x80000000u
#define WS_EX_TOPMOST 0x00000008u
#define WS_EX_TOOLWINDOW 0x00000080u
#define SWP_SHOWWINDOW 0x0040u
#define SWP_NOACTIVATE 0x0010u
#define SM_CXSCREEN 0
#define SM_CYSCREEN 1
#define SM_XVIRTUALSCREEN 76
#define SM_YVIRTUALSCREEN 77
#define SM_CXVIRTUALSCREEN 78
#define SM_CYVIRTUALSCREEN 79
#define DEFAULT_CHARSET 1u
#define FW_NORMAL 400
#define FW_BOLD 700
#define ERROR_ALREADY_EXISTS 183u
#define IDI_APPLICATION 32512u
#define HOTKEY_EXIT 500
#define MENU_BREAK 501
#define MENU_EXIT 502
#define WM_TRAY (WM_APP + 37u)
#define TIMER_ID 1u
#define INTERVAL_MS 1200000ULL
#define BREAK_MS 20000ULL

static void app_entry(void);
static HWND g_control, g_overlay;
static HANDLE g_mutex;
static UINT g_taskbar_created;
static BOOL g_hotkey_registered;
static BOOL g_session_notification_registered;
static BOOL g_session_available = 1;
static BOOL g_tray_added;
static BOOL g_in_break;
static ULONGLONG g_next_break;
static ULONGLONG g_break_ends;
static HFONT g_font_big, g_font_small;
static HBRUSH g_background;
static NOTIFYICONDATAW_V1 g_tray;
static WNDCLASSEXW g_class_control, g_class_overlay;
static MSG g_msg;

static LPCWSTR volatile g_window_title = L"Augenpause";

static void copy_tip(WCHAR* dest, const WCHAR* src, UINT capacity)
{
    UINT i = 0;
    while (i + 1 < capacity && src[i] != 0) { dest[i] = src[i]; ++i; }
    dest[i] = 0;
}

static void remove_tray(void)
{
    if (g_tray_added) { Shell_NotifyIconW(NIM_DELETE, &g_tray); g_tray_added = 0; }
}

static void add_tray(void)
{

    remove_tray();
    g_tray_added = Shell_NotifyIconW(NIM_ADD, &g_tray);
}

static BOOL reposition_overlay(BOOL show)
{
    int x = GetSystemMetrics(SM_XVIRTUALSCREEN);
    int y = GetSystemMetrics(SM_YVIRTUALSCREEN);
    int w = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    int h = GetSystemMetrics(SM_CYVIRTUALSCREEN);
    if (w < 1 || h < 1) return 0;
    return SetWindowPos(g_overlay, (HWND)(-1), x, y, w, h,
                        show ? SWP_SHOWWINDOW : 0u);
}

static void finish_break(void)
{
    if (!g_in_break) return;
    g_in_break = 0;
    ShowWindow(g_overlay, SW_HIDE);
    g_next_break = GetTickCount64() + INTERVAL_MS;
}

static void start_break(void)
{
    if (g_in_break || !g_overlay || !g_session_available) return;
    g_in_break = 1;
    g_break_ends = GetTickCount64() + BREAK_MS;
    if (!reposition_overlay(1)) {

        finish_break();
        return;
    }
    SetForegroundWindow(g_overlay);
    InvalidateRect(g_overlay, 0, 0);
    UpdateWindow(g_overlay);
}

static void show_tray_menu(void)
{
    POINT pt;
    HMENU menu;
    if (!GetCursorPos(&pt)) return;
    menu = CreatePopupMenu();
    if (!menu) return;
    AppendMenuW(menu, MF_STRING, MENU_BREAK, L"Start break now");
    AppendMenuW(menu, MF_STRING, MENU_EXIT, L"Exit");
    SetForegroundWindow(g_control);
    TrackPopupMenu(menu, TPM_RIGHTBUTTON | TPM_BOTTOMALIGN,
                   (int)pt.x, (int)pt.y, 0, g_control, 0);
    PostMessageW(g_control, WM_NULL, 0, 0);
    DestroyMenu(menu);
}

static LRESULT WINAPI overlay_proc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp)
{
    if (message == WM_ERASEBKGND) return 1;
    if (message == WM_KEYDOWN || message == WM_SYSKEYDOWN) {
        if ((UINT)wp == VK_ESCAPE) { finish_break(); return 0; }
    }
    if (message == WM_LBUTTONDOWN || message == WM_RBUTTONDOWN ||
        message == WM_CLOSE) {
        finish_break();
        return 0;
    }
    if (message == WM_PAINT) {
        PAINTSTRUCT ps;
        RECT canvas, line;
        HDC dc = BeginPaint(hwnd, &ps);
        if (!dc) return 0;
        GetClientRect(hwnd, &canvas);
        FillRect(dc, &canvas, g_background);
        SetBkMode(dc, TRANSPARENT);
        SetTextColor(dc, 0x00EDEDEDu);

        int l = -GetSystemMetrics(SM_XVIRTUALSCREEN);
        int t = -GetSystemMetrics(SM_YVIRTUALSCREEN);
        int w = GetSystemMetrics(SM_CXSCREEN);
        int h = GetSystemMetrics(SM_CYSCREEN);
        line.left = l + 10; line.right = l + w - 10;
        SelectObject(dc, (HGDIOBJ)g_font_small);
        line.top = t + h/2 - 145; line.bottom = t + h/2 - 80;
        DrawTextW(dc, L"EYE BREAK", -1, &line,
                  DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        SelectObject(dc, (HGDIOBJ)g_font_big);
        ULONGLONG now = GetTickCount64();
        unsigned int secs = g_break_ends > now
            ? (unsigned int)((g_break_ends - now + 999ULL) / 1000ULL) : 0u;
        if (secs > 99u) secs = 99u;
        WCHAR time_text[6] = {L'0', L'0', L':',
                              (WCHAR)(L'0' + (secs / 10u)),
                              (WCHAR)(L'0' + (secs % 10u)), 0};
        line.top = t + h/2 - 80; line.bottom = t + h/2 + 20;
        DrawTextW(dc, time_text, -1, &line,
                  DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        SelectObject(dc, (HGDIOBJ)g_font_small);
        line.top = t + h/2 + 30; line.bottom = t + h/2 + 90;
        DrawTextW(dc, L"Look at something at least 6 meters away", -1,
                  &line, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        SetTextColor(dc, 0x00B0B0B0u);
        line.top = t + h/2 + 100; line.bottom = t + h/2 + 155;
        DrawTextW(dc, L"Press Esc or click to end the break", -1,
                  &line, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProcW(hwnd, message, wp, lp);
}

static LRESULT WINAPI control_proc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp)
{
    if (g_taskbar_created && message == g_taskbar_created) {
        g_tray_added = 0; add_tray(); return 0;
    }
    if (message == WM_DISPLAYCHANGE) {
        if (g_in_break) {
            if (!reposition_overlay(1)) finish_break();
            else InvalidateRect(g_overlay, 0, 0);
        }
        return 0;
    }
    if (message == WM_QUERYENDSESSION) return 1;
    if (message == WM_ENDSESSION) {
        if (wp) DestroyWindow(hwnd);
        return 0;
    }
    if (message == WM_WTSSESSION_CHANGE) {
        UINT evt = (UINT)wp;
        if (evt == WTS_SESSION_LOCK || evt == WTS_REMOTE_DISCONNECT ||
            evt == WTS_CONSOLE_DISCONNECT) {
            g_session_available = 0;
            finish_break();
        } else if (evt == WTS_SESSION_UNLOCK || evt == WTS_REMOTE_CONNECT ||
                   evt == WTS_CONSOLE_CONNECT) {
            g_session_available = 1;
            g_next_break = GetTickCount64() + INTERVAL_MS;
        }
        return 0;
    }
    if (message == WM_POWERBROADCAST &&
        ((UINT)wp == PBT_APMRESUMESUSPEND ||
         (UINT)wp == PBT_APMRESUMEAUTOMATIC)) {
        finish_break();
        g_next_break = GetTickCount64() + INTERVAL_MS;
        return 1;
    }
    if (message == WM_TIMER && wp == TIMER_ID) {
        ULONGLONG now = GetTickCount64();
        if (g_in_break) {
            if (now >= g_break_ends) finish_break();
            else InvalidateRect(g_overlay, 0, 0);
        } else if (g_session_available && now >= g_next_break) {
            start_break();
        }
        return 0;
    }
    if (message == WM_HOTKEY && wp == HOTKEY_EXIT) {
        DestroyWindow(hwnd); return 0;
    }
    if (message == WM_COMMAND) {
        UINT cmd = (UINT)(wp & 0xffffu);
        if (cmd == MENU_BREAK) start_break();
        else if (cmd == MENU_EXIT) DestroyWindow(hwnd);
        return 0;
    }
    if (message == WM_TRAY) {
        if ((UINT)lp == WM_RBUTTONUP || (UINT)lp == WM_LBUTTONUP ||
            (UINT)lp == WM_CONTEXTMENU) show_tray_menu();
        return 0;
    }
    if (message == WM_DESTROY) {
        KillTimer(hwnd, TIMER_ID);
        remove_tray();
        if (g_hotkey_registered) UnregisterHotKey(hwnd, HOTKEY_EXIT);
        if (g_session_notification_registered) WTSUnRegisterSessionNotification(hwnd);
        if (g_overlay) { DestroyWindow(g_overlay); g_overlay = 0; }
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, message, wp, lp);
}


static void app_entry(void)
{
    SetProcessDPIAware();
    HINSTANCE instance = GetModuleHandleW(0);
    g_mutex = CreateMutexW(0, 1, L"Local\\Augenpause_202020_OneInstance_v1");
    if (!g_mutex || GetLastError() == ERROR_ALREADY_EXISTS) ExitProcess(0);

    g_class_control.cbSize = sizeof(g_class_control);
    g_class_control.lpfnWndProc = control_proc;
    g_class_control.hInstance = instance;
    g_class_control.lpszClassName = L"Augenpause_Control_v1";
    if (!RegisterClassExW(&g_class_control)) {
        MessageBoxW(0, L"Could not register the window class.",
                    L"Augenpause: Startup error", MB_ICONERROR);
        ExitProcess(1);
    }

    g_class_overlay.cbSize = sizeof(g_class_overlay);
    g_class_overlay.lpfnWndProc = overlay_proc;
    g_class_overlay.hInstance = instance;
    g_class_overlay.lpszClassName = L"Augenpause_Overlay_v1";
    if (!RegisterClassExW(&g_class_overlay)) {
        MessageBoxW(0, L"Could not register the overlay window class.",
                    L"Augenpause: Startup error", MB_ICONERROR);
        ExitProcess(1);
    }

    g_control = CreateWindowExW(0, g_class_control.lpszClassName, g_window_title,
                0, 0, 0, 0, 0, 0, 0, instance, 0);
    if (!g_control) {
        MessageBoxW(0, L"Could not create the control window.",
                    L"Augenpause: Startup error", MB_ICONERROR);
        ExitProcess(1);
    }
    g_overlay = CreateWindowExW(WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
                g_class_overlay.lpszClassName, g_window_title,
                WS_POPUP, 0, 0, 1, 1, 0, 0, instance, 0);
    if (!g_overlay) {
        MessageBoxW(0, L"Could not create the full-screen window.",
                    L"Augenpause: Startup error", MB_ICONERROR);
        DestroyWindow(g_control); ExitProcess(1);
    }

    g_background = CreateSolidBrush(0x00201810u);
    g_font_big = CreateFontW(-76, 0, 0, 0, FW_BOLD, 0, 0, 0,
                    DEFAULT_CHARSET, 0, 0, 0, 0, L"Segoe UI");
    g_font_small = CreateFontW(-26, 0, 0, 0, FW_NORMAL, 0, 0, 0,
                    DEFAULT_CHARSET, 0, 0, 0, 0, L"Segoe UI");
    if (!g_background || !g_font_big || !g_font_small) {
        MessageBoxW(0, L"Windows drawing resources are unavailable.",
                    L"Augenpause: Startup error", MB_ICONERROR);
        DestroyWindow(g_control); ExitProcess(1);
    }

    g_tray.cbSize = sizeof(g_tray);
    g_tray.hWnd = g_control;
    g_tray.uID = 1;
    g_tray.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    g_tray.uCallbackMessage = WM_TRAY;
    g_tray.hIcon = LoadIconW(instance, (LPCWSTR)(UINT_PTR)1u);
    if (!g_tray.hIcon) g_tray.hIcon = LoadIconW(0, (LPCWSTR)(UINT_PTR)IDI_APPLICATION);
    copy_tip(g_tray.szTip, L"Augenpause: 20 minutes / 20 seconds", 128);
    g_taskbar_created = RegisterWindowMessageW(L"TaskbarCreated");
    add_tray();


    g_hotkey_registered = RegisterHotKey(g_control, HOTKEY_EXIT,
                                        MOD_CONTROL | MOD_ALT | MOD_SHIFT, 'Q');

    if (!g_hotkey_registered || !g_tray_added) {
        MessageBoxW(0,
            L"Tray icon or emergency exit unavailable. The application will close.",
            L"Augenpause: Safety check", MB_ICONERROR);
        DestroyWindow(g_control);
        ExitProcess(1);
    }


    g_session_notification_registered =
        WTSRegisterSessionNotification(g_control, NOTIFY_FOR_THIS_SESSION);
    if (!g_session_notification_registered) {
        MessageBoxW(0,
            L"Windows session monitoring unavailable. The application will close.",
            L"Augenpause: Safety check", MB_ICONERROR);
        DestroyWindow(g_control);
        ExitProcess(1);
    }
    g_next_break = GetTickCount64() + INTERVAL_MS;
    if (!SetTimer(g_control, TIMER_ID, 1000u, 0)) {
        MessageBoxW(0, L"Could not start the Windows timer.",
                    L"Augenpause: Startup error", MB_ICONERROR);
        DestroyWindow(g_control); ExitProcess(1);
    }

    int r;
    while ((r = GetMessageW(&g_msg, 0, 0, 0)) > 0) {
        TranslateMessage(&g_msg);
        DispatchMessageW(&g_msg);
    }
    if (g_font_big) DeleteObject((HGDIOBJ)g_font_big);
    if (g_font_small) DeleteObject((HGDIOBJ)g_font_small);
    if (g_background) DeleteObject((HGDIOBJ)g_background);
    CloseHandle(g_mutex);
    ExitProcess(r < 0 ? 1u : 0u);
}

#if defined(AP_WITH_CRT)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   char *lpCmdLine, int nCmdShow)
{
    (void)hInstance; (void)hPrevInstance;
    (void)lpCmdLine; (void)nCmdShow;
    app_entry();
    return 0;
}
#else
void mainCRTStartup(void) { app_entry(); }
#endif
