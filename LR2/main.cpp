//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
// Синус
// LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
// WPARAM wParam, LPARAM lParam)
// {
//     PAINTSTRUCT ps;
//     HDC hdc;
//     static int sx, sy;
//     static HPEN hpen1, hpen2;
//     int a, b, x_scr, y_scr; //Экранные координаты
//     double x, h; //Физические координаты
//     //Обработчик сообщений
//     switch(message)
//     {
//         case WM_CREATE:
//             hpen1 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
//             hpen2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
//             break;
//         case WM_SIZE:
//             sx = LOWORD(lParam); //Ширина окна
//             sy = HIWORD(lParam); //Высота окна
//             break;
//         case WM_PAINT:
//             hdc = BeginPaint(hWnd, &ps);
//             a = sx/2; //Координаты
//             b = sy/2; //центра окна
//             SelectObject(hdc, hpen1); //Синее перо
//             MoveToEx(hdc, 0, b, NULL);
//             LineTo(hdc, sx, b);
//             MoveToEx(hdc, a, 0, NULL);
//             LineTo(hdc, a, sy);
//             MoveToEx(hdc, 0, b, NULL);
//             SelectObject(hdc, hpen2); //Красное перо
//             h = 3*M_PI/a; //Шаг по оси x
//             for(x = -M_PI, x_scr =0; x<M_PI; x += h)
//             {
//                 x_scr = (x + M_PI)*a/M_PI;
//                 y_scr = b - b*sin(x);
//                 LineTo(hdc, x_scr, y_scr);
//             }
//             EndPaint(hWnd, &ps);
//             break;
//         case WM_DESTROY :
//             DeleteObject(hpen1);
//             DeleteObject(hpen2);
//             PostQuitMessage(0);
//             break; // Завершение программы
//         // Обработка сообщения по умолчанию
//         default : return DefWindowProc(hWnd, message, wParam, lParam);
//     }
//     return 0;
// }
// Парабола
// LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
// WPARAM wParam, LPARAM lParam)
// {
//     PAINTSTRUCT ps;
//     HDC hdc;
//     static int sx, sy;
//     static HPEN hpen1, hpen2;
//     int a, b, x_scr, y_scr; //Экранные координаты
//     double x, h; //Физические координаты
//     //Обработчик сообщений
//     switch(message)
//     {
//         case WM_CREATE:
//             hpen1 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
//             hpen2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
//             break;
//         case WM_SIZE:
//             sx = LOWORD(lParam); //Ширина окна
//             sy = HIWORD(lParam); //Высота окна
//             break;
//         case WM_PAINT:
//             hdc = BeginPaint(hWnd, &ps);
//             a = sx/2; //Координаты
//             b = sy/2; //центра окна
//             SelectObject(hdc, hpen1); //Синее перо
//             MoveToEx(hdc, 0, b, NULL);
//             LineTo(hdc, sx, b);
//             MoveToEx(hdc, a, 0, NULL);
//             LineTo(hdc, a, sy);
//             MoveToEx(hdc, 0, b, NULL);
//             SelectObject(hdc, hpen2); //Красное перо
//             h = 3*M_PI/a; //Шаг по оси x
//             for(x = -M_PI, x_scr = 0; x < M_PI; x += h)
//             {
//                 x_scr = (x+M_PI)*a/M_PI;
//                 y_scr = b - b*(x*x);
//                 LineTo(hdc, x_scr, y_scr);
//             }
//             EndPaint(hWnd, &ps);
//             break;
//         case WM_DESTROY :
//             DeleteObject(hpen1);
//             DeleteObject(hpen2);
//             PostQuitMessage(0);
//             break; // Завершение программы
//         // Обработка сообщения по умолчанию
//         default : return DefWindowProc(hWnd, message, wParam, lParam);
//     }
//     return 0;
// }
// Поверхность
// LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
// WPARAM wParam, LPARAM lParam)
// {
//     PAINTSTRUCT ps;
//     HDC hdc;
//     static int sx, sy;
//     static HPEN hpen, hpen1;            //Тип структуры пера
//     int a, b, n, x_scr, y_scr, z_src;   //Экранные координаты
//     double x, y, z,                     //Физические координаты объекта
//            x_min, x_max, y_min, y_max,  //физические габариты объекта
//            Kx, Ky;                      //Коэффициенты масштабирования
//     //Обработчик сообщений
//     switch(message)
//     {
//         case WM_CREATE:
//             hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
//             break;
//         case WM_SIZE:
//             sx = LOWORD(lParam); //Ширина окна
//             sy = HIWORD(lParam); //Высота окна
//             break;
//         case WM_PAINT:
//             hdc = BeginPaint(hWnd, &ps);
//             a = sx/2; //Координаты
//             b = sy/2; //центра окна
//             // Задание области положения функции
//             x_min = -100;
//             x_max = 100;
//             y_min = -100;
//             y_max = 100;

//             //Расчёт коэфициентов масштабирования
//             Kx = (sx-220)/(x_max-x_min);
//             Ky = (sy-220)/(y_max-y_min);

//             SelectObject(hdc, hpen); //Синее перо
//             MoveToEx(hdc, 0, b, NULL); //отрисовка оси Ох
//             LineTo(hdc, sx, b);
//             MoveToEx(hdc, a, 0, NULL); //отрисовка оси Оz
//             LineTo(hdc, a, sy);
//             MoveToEx(hdc, 20, sy-20, NULL); //отрисовка оси Оy
//             LineTo(hdc, sx-20, 20);

//             n = y_max-y_min; //максимальное поле по оси Оу
//             //Цикл смещения сечений вдоль оси Оу
//             for(y = y_min; y < y_max ; y +=5)
//             {
//                 //закраска красным оттенком сечения поверхности
//                 hpen1 = CreatePen(PS_SOLID, 2,RGB(255, 255-255./n*(y+y_min), 255-255./n*(y+y_min)));
//                 SelectObject(hdc, hpen1);
//                 //Определение значения функции в начальной точке сечения
//                 z = b-100*sin(M_PI/50*sqrt(x_min*x_min+y*y));
//                 MoveToEx(hdc,x_min*Kx+a+y,(z+y),NULL);
//                 //Отрисовка сечения вдоль оси Ох
//                 for(x = x_min; x < x_max; x += 5)
//                 { 
//                     z = b-100*sin(M_PI/50*sqrt(x*x+y*y));
//                     LineTo(hdc, x*Kx+a+y, z+y); 
//                 }
//             }

//             EndPaint(hWnd, &ps);
//             break; // Завершение программы
//         // Обработка сообщения по умолчанию
//         default : return DefWindowProc(hWnd, message, wParam, lParam);
//     }
//     return 0;
// }
// y = 5/x
LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    static int sx, sy;
    static HPEN hpen1, hpen2;
    int a, b, x_scr, y_scr;                 //Экранные координаты
    double x, h, y, z,                      //Физические координаты объекта
           x_min, x_max, y_min, y_max,      //физические габариты объекта
           Kx, Ky;                          //Коэффициенты масштабирования
    //Обработчик сообщений
    switch(message)
    {
        case WM_CREATE:
            hpen1 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
            hpen2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
            break;
        case WM_SIZE:
            sx = LOWORD(lParam); //Ширина окна
            sy = HIWORD(lParam); //Высота окна
            break;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            a = sx/2; //Координаты
            b = sy/2; //центра окна

            SelectObject(hdc, hpen1); //Синее перо
            MoveToEx(hdc, 0, b, NULL);
            LineTo(hdc, sx, b);
            MoveToEx(hdc, a, 0, NULL);
            LineTo(hdc, a, sy);
            MoveToEx(hdc, 0, b, NULL);

            SelectObject(hdc, hpen2); //Красное перо
            MoveToEx(hdc, 0, sy/2, NULL);
            h = 1; //Шаг по оси x
            for(x = -1000; x < 1000; x += h)
            {
                if(x == 0){
                    MoveToEx(hdc, sx/2, 0, NULL);
                    continue;
                }
                x_scr = (x + 1000)*a/1000;
                y_scr = b - b*(5/x);
                LineTo(hdc, x_scr, y_scr);
            }
            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY :
            DeleteObject(hpen1);
            DeleteObject(hpen2);
            PostQuitMessage(0);
            break; // Завершение программы
        // Обработка сообщения по умолчанию
        default : return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}