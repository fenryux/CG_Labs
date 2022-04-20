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
// LRESULT CALLBACK WndProc(HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam){
//     PAINTSTRUCT ps;
//     HDC hdc;
//     static int sx,sy;
//     static HPEN hpen;
//     int a, b, x_scr, y_scr;
//     float x[4] = {6.0,6.0,5.9,6.1},
//           y[4] = {-0.25, 0.25, 0.0, 0.0};
//     float xMax = 6.5,
//           yMax = 6.5;
//     float Kx, Ky;

//     switch (message)
//     {
//     case WM_CREATE:
//         hpen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
//         break;
//     case WM_SIZE:
//         sx = LOWORD(lParam);
//         sy = HIWORD(lParam);
//         break;
//     case WM_PAINT:
//         hdc = BeginPaint(hWnd, &ps);
//         int i, j;
//         float pi, phi, cos_phi, sin_phi, xx, yy;

//         pi  = 4.0*atan(1.0);
//         phi = 6*pi/180;
//         cos_phi = cos(phi);
//         sin_phi = sin(phi);

//         SelectObject(hdc, hpen);
        
//         Kx = sx/xMax;
//         Ky = sy/yMax;

//         for(i = 1; i <= 14; i++){
//             for(j = 0; j <= 3; j++){
//                 xx = x[j]; yy = y[j];
//                 x[j] = xx*cos_phi - yy*sin_phi;
//                 y[j] = xx*sin_phi + yy*cos_phi;
//             }
//             MoveToEx(hdc, x[0]*Kx, sy - y[0]*Ky, NULL);
//             for(j = 1; j <= 3; j++)
//                 LineTo(hdc, x[j]*Kx, sy - y[j]*Ky);
//             LineTo(hdc, x[1]*Kx, sy-y[1]*Ky);
//         }
//         EndPaint(hWnd, &ps);
//         break;
//     case WM_DESTROY:
//         DeleteObject(hpen);
//         PostQuitMessage(0);
//         break;
//     default:
//         return DefWindowProc(hWnd, message, wParam, lParam);
//     }
// }
// ВОКРУГ ТОЧКИ
// LRESULT CALLBACK WndProc(HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam){
//     PAINTSTRUCT ps;
//     HDC hdc;
//     static int sx,sy;
//     static HPEN hpen;
//     int a, b, x_scr, y_scr;
//     float x[4] = {0.0,0.0,-0.08,0.08},
//           y[4] = {-0.25, 0.25, 0.0, 0.0};
//     float xMax = 8.5,
//           yMax = 8.5;
//     float x0 = 4.5,
//           y0 = 4.5,
//           r = 3.0;
//     float Kx, Ky;
//     float dx, dy;

//     switch (message)
//     {
//         case WM_CREATE:
//             hpen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
//             break;
//         case WM_SIZE:
//             sx = LOWORD(lParam);
//             sy = HIWORD(lParam);
//             break;
//         case WM_PAINT:
//             hdc = BeginPaint(hWnd, &ps);
//             int i, j;
//             float pi, phi, cos_phi, sin_phi, xx, yy;

//             pi  = 4.0*atan(1.0);
//             phi = 6*pi/180;
//             cos_phi = cos(phi);
//             sin_phi = sin(phi);

//             SelectObject(hdc, hpen);
            
//             Kx = sx/xMax;
//             Ky = sy/yMax;

//             for(j = 0; j < 4; j++){
//                 x[j] += x0 + r;
//                 y[j] += y0;
//             }
//             for(i = 0; i < 60;i++){
//                 for(j=0;j < 4; j++){
//                     dx = x[j]-x0;
//                     dy = y[j] - y0;
//                     x[j] = x0 + dx*cos_phi - dy*sin_phi;
//                     y[j] = y0 + dx*sin_phi + dy*cos_phi;
//                 }
//                 MoveToEx(hdc, x[0]*Kx, sy - y[0]*Ky, NULL);
//                 for(j=1; j <= 3; j++)
//                     LineTo(hdc, x[j]*Kx, sy - y[j]*Ky);
//                 LineTo(hdc, x[1]*Kx, sy - y[1]*Ky);
//             }
//             EndPaint(hWnd, &ps);
//             break;
//         case WM_DESTROY:
//             DeleteObject(hpen);
//             PostQuitMessage(0);
//             break;
//         default:
//             return DefWindowProc(hWnd, message, wParam, lParam);
//     }
// }
// ВРАЩАЮЩИЕСЯ КВАДРАТЫ
// LRESULT CALLBACK WndProc(HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam){
//     PAINTSTRUCT ps;
//     HDC hdc;

//     POINT pt[4] = {{-100,100},{-100,-100},{100,-100},{100,100}};
//     POINT pt1[4];

//     const int WIDTH = 400;
//     const int HEIGHT = 300;

//     int n = 8, i ,j;
//     double alpha = M_PI/n;

//     static int sx,sy;
//     static HBRUSH hBrush;
//     int a, b, x_scr, y_scr;
//     double x;

//     switch (message)
//     {
//         case WM_CREATE:
//             break;
//         case WM_SIZE:
//             sx = LOWORD(lParam);
//             sy = HIWORD(lParam);
//             break;
//         case WM_PAINT:
//             hdc = BeginPaint(hWnd, &ps);

//             for(i = 0; i <= n; i++){
//                 hBrush = CreateSolidBrush(RGB(255,255-255./n*i,255-255./n*i));
//                 SelectObject(hdc,hBrush);
//                 for(j = 0; j <= 3; j++){
//                     pt1[j].x = 500 + (pt[j].x*cos(alpha*i) - pt[j].y*sin(alpha*i)) + i*10;
//                     pt1[j].y = 300 + (pt[j].x*sin(alpha*i) + pt[j].y*cos(alpha*i));
//                 }
//                 Polygon(hdc, pt1, 4);
//             }

//             EndPaint(hWnd, &ps);
//             break;
//         case WM_DESTROY:
//             DeleteObject(hBrush);
//             PostQuitMessage(0);
//             break;
//         default:
//             return DefWindowProc(hWnd, message, wParam, lParam);
//     }
// }
LRESULT CALLBACK WndProc(HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam){
    PAINTSTRUCT ps;
    HDC hdc;

    POINT pt[3] = {{0,0},{-100,0},{0,100}};
    POINT pt1[3];

    const int WIDTH = 400;
    const int HEIGHT = 300;

    int n = 8, i ,j;
    double alpha = M_PI/n;

    static int sx,sy;
    static HBRUSH hBrush;
    int a, b, x_scr, y_scr;
    double x;

    switch (message)
    {
        case WM_CREATE:
            break;
        case WM_SIZE:
            sx = LOWORD(lParam);
            sy = HIWORD(lParam);
            break;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            for(i = 0; i <= n; i++){
                hBrush = CreateSolidBrush(RGB(255,255-255./n*i,255-255./n*i));
                SelectObject(hdc,hBrush);
                for(j = 0; j <= 3; j++){
                    pt1[j].x = 500 + (pt[j].x*cos(alpha*i) - pt[j].y*sin(alpha*i)) + i*10;
                    pt1[j].y = 300 + (pt[j].x*sin(alpha*i) + pt[j].y*cos(alpha*i));
                }
                BeginPath(hdc);
                Polyline(hdc, pt1, 3);
                CloseFigure(hdc);
                EndPath(hdc);

                SelectObject(hdc, hBrush);
                SetPolyFillMode(hdc, WINDING);
                FillPath(hdc);
            }


            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY:
            DeleteObject(hBrush);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
}