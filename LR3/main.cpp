#include <windows.h>
#include <tchar.h>
#include <math.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
//---------------------------------------------------------------------------
int APIENTRY WinMain(HINSTANCE This, HINSTANCE Prev, LPSTR cmd,
int mode)
{
    HWND hWnd; //Дескриптор главного окна программы
    MSG msg; // Структура для хранения сообщений
    WNDCLASS wc; // Класс окна
    // Определение класса окна
    wc.hInstance = This;
    wc.lpszClassName = WinName; // Имя класса окна
    wc.lpfnWndProc = WndProc; // Функция окна
    wc.style = CS_HREDRAW | CS_VREDRAW; // Стиль окна
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Стандартная иконка
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); //Стандартный курсор
    wc.lpszMenuName = NULL; //Нет меню
    wc.cbClsExtra = 0; //Нет дополнительных данных класса
    wc.cbWndExtra = 0; //Нет дополнительных данных окна
    // Заполнение окна белым цветом
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); //установка цвета фона
    if(!RegisterClass(&wc)) return 0; // Регистрация класса окна
    // Создание окна
    hWnd = CreateWindow(WinName, //Имя класса окна
                        _T("Каркас Windows-приложения"), // Заголовок окна
                        WS_OVERLAPPEDWINDOW, // Стиль окна
                        CW_USEDEFAULT, // X
                        CW_USEDEFAULT, // Y
                        CW_USEDEFAULT, // Width
                        CW_USEDEFAULT, // Height
                        HWND_DESKTOP, // Дескриптор родительского окна
                        NULL, // Нет меню
                        This, // Дескриптор приложения
                        NULL); // Дополнительной информации нет
    ShowWindow(hWnd, mode); // Показать окно
    // Цикл обработки сообщений
    while(GetMessage(&msg, NULL, 0, 0)) //цикл получения сообщений
    { 
        TranslateMessage(&msg); // Функция трансляции кодов нажатой клавиши
        DispatchMessage(&msg); // Посылает сообщение функции WndProc()
    }
    return 0; // при положительном завершении программы в главную функцию
    //возвращается «0»
}
// Red Faction
// LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
// WPARAM wParam, LPARAM lParam)
// {
//     PAINTSTRUCT ps;
//     HDC hdc;

//     POINT pt[5] = {{0,100}, {-59, -81}, {95,31},{-95,31},{59,-81}};
//     const int WIDTH = 400;
//     const int HEIGHT = 300;
//     static int sx,sy, i, k;
//     static HBRUSH hBrush;
//     HRGN hRgn;
//     int a,b,x_scr,y_scr;
//     double x,h;
//     //Обработчик сообщений
//     switch(message)
//     {
//         case WM_CREATE:
//             i =  MessageBox(hWnd, _T("Will we draw a red star?"),
//                             _T("Political question"), MB_YESNO|MB_ICONQUESTION);
//             k = (i == IDYES) ? 1 : 0;
//             hBrush = CreateSolidBrush(RGB(255,0,0));
//             break;
//         case WM_SIZE:
//             sx = LOWORD(lParam); //Ширина окна
//             sy = HIWORD(lParam); //Высота окна
//             break;
//         case WM_PAINT:
//             hdc = BeginPaint(hWnd, &ps);

//             SetMapMode(hdc,MM_ANISOTROPIC);
//             SetWindowExtEx(hdc, WIDTH, -HEIGHT, NULL);
//             SetViewportExtEx(hdc,sx,sy,NULL);
//             SetViewportOrgEx(hdc,sx/2,sy/2,NULL);

//             BeginPath(hdc);
//             Polyline(hdc,pt,5);
//             CloseFigure(hdc);
//             EndPath(hdc);

//             SelectObject(hdc,hBrush);
//             SetPolyFillMode(hdc,WINDING);
//             FillPath(hdc);
            
//             EndPaint(hWnd, &ps);
//             break;
//         case WM_DESTROY :
//             DeleteObject(hBrush);
//             PostQuitMessage(0);
//             break; // Завершение программы
//         // Обработка сообщения по умолчанию
//         default : return DefWindowProc(hWnd, message, wParam, lParam);
//     }
//     return 0;
// }
LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    POINT pt[3] = {{0,0}, {-100, 0}, {0,100}};
    const int WIDTH = 400;
    const int HEIGHT = 400;
    static int sx,sy, i, k;
    static HBRUSH hBrush;
    HRGN hRgn;
    int a,b,с;
    double x,h;
    //Обработчик сообщений
    switch(message)
    {
        case WM_CREATE:
            hBrush = CreateSolidBrush(RGB(255,0,0));
            break;
        case WM_SIZE:
            sx = LOWORD(lParam); //Ширина окна
            sy = HIWORD(lParam); //Высота окна
            break;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            SetMapMode(hdc,MM_ANISOTROPIC);
            SetWindowExtEx(hdc, WIDTH, -HEIGHT, NULL);
            SetViewportExtEx(hdc,sx,sy,NULL);
            SetViewportOrgEx(hdc,sx/2,sy/2,NULL);

            BeginPath(hdc);
            Polyline(hdc,pt,3);
            CloseFigure(hdc);
            EndPath(hdc);

            SelectObject(hdc,hBrush);
            SetPolyFillMode(hdc,WINDING);
            FillPath(hdc);
            
            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY :
            DeleteObject(hBrush);
            PostQuitMessage(0);
            break; // Завершение программы
        // Обработка сообщения по умолчанию
        default : return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}