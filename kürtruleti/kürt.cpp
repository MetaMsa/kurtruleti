#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class GAME{
    public:
    COORD crd={60,1};
    GAME()
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
        while(1)
        {
            if(_kbhit())
            {
                switch(_getch())
                {
                    case 13:
                    Shoot();
                    break;
                }
            }
        }
    }

    void Shoot()
    {
        while(crd.Y<29)
        {
        cout<<'x';
        Sleep(100);
        cout<<char(8)<<" ";
        crd.Y++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
        }
        if(crd.Y==29)
        {
            if(_kbhit())
            {
                switch(_getch())
                {
                    case 13:
                        Shoot2();
                        break;
                }
            }
        }
    }

    void Shoot2()
    {
        while(crd.Y>0)
        {
        cout<<'x';
        Sleep(100);
        cout<<char(8)<<" ";
        crd.Y--;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
        }

        play2=false;
}
};

class player2{
    public:
        player2()
        {
        COORD crd={60,29};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
        cout<<"O";
        }
};

class player1{
    public:
        player1()
        {
        COORD crd={60,0};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
        cout<<"O";
        }
};

int main()
{ 
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    player1 p1;
    player2 p2;
    GAME game;
    getch();
    getch();
}