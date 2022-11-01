#include "Library.h"

void setColor(int color)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void showInput(string s)
{
    cout << s;
}
void showInput(string s, int color)
{
    setColor(color);
    cout << s;
}
char* inputStringName(const int k)
{
    char* kq = new char[k + 1]; // tao mang
    int n, index = 0;
    do
    {
    loop:;
        n = _getch(); // lay ma ASCII
        // Neu thuoc 0-9, A-Z, a-z hoac dau '.' va chuoi đang co it hon k ky tu thi cho phep
        if (((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z') || n == '.') && index < k)
        {
            cout << char(n); // xuat ky tu do ra man hinh
            kq[index++] = n; // Luu vao mang
        }
        else if (n == '\b' && index > 0) // Neu nhan dau BackSpace ma chuoi khong rong
        {
            cout << "\b \b"; // Xoa 1 ky tu tren man hinh
            kq[--index] = 0; // Xoa 1 ky tu trong chuoi kq
        }
        if (n == 13 && index == 0) goto loop; // Neu nhan Enter ma chua nhap gi thi khong cho phep
    } while (n != 13); // Cu lap lai trong khi chua nhap Enter

    kq[index] = 0; // Ket thuc chuoi
    cout << '\n';
    return kq;
}