
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "routine.h"
#include "bus.h"
#include "course.h"
#include "student.h"
#include "admin.h"
#include "advising.h"
#include "faculty.h"
#include "info.h"

///-------------------------------------------  Main Function-start ----------------------------------
int main()
{
    mainmenu();
}
///-------------------------------------------   Main Function-end  ----------------------------------


///----------------------------------------- Main Menu Function-start --------------------------------
void mainmenu()
{
    clrscr();
    char a[]="UNIVERSITY PORTAL SYSTEM";
    int i, n;
    gotoxy(10,3);
    for(i=0; i<40; i++)
    {
        Sleep(10);
        printf("\xB2");
    }
    gotoxy(10,3);
    for(i=3; i<18; i++)
    {
        gotoxy(10, i);
        printf("\xB2");
        Sleep(20);
    }
    gotoxy(50,3);
    for(i=3; i<18; i++)
    {
        gotoxy(50, i);
        printf("\xB2");
        Sleep(20);
    }
    gotoxy(10,17);
    for(i=0; i<40; i++)
    {
        Sleep(10);
        printf("\xB2");
    }
    gotoxy(10,7);
    for(i=0; i<40; i++)
    {
        Sleep(10);
        printf("\xB2");
    }
    gotoxy(18, 5);
    for(i=0; i<24; i++)
    {
        Sleep(50);
        printf("%c", a[i]);
    }
    gotoxy(20,10);
    printf("\xb3\xdb\xdb\xdb ADMIN    .1");
    gotoxy(20,12);
    printf("\xb3\xdb\xdb\xdb STUDENT  .2");
    gotoxy(20,14);
    printf("\xb3\xdb\xdb\xdb QUIT     .3");
    gotoxy(11,18);
    printf("Enter your choice: ");
    scanf("%d", &n);
xyz:
    switch(n)
    {
    case 1:
        printf("\n\n");
        password();
        break;
    case 2:
        studentLogin();
        break;
    case 3:
        clrscr();
        exit(0);
        break;
    default:
        printf("\n\n\t\t\t");
        printf("Invalid choice!!");
        getch();
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &n);
        goto xyz;

    }
}
///----------------------------------------- Main Menu Function-end -----------------------------------

void clrscr()
{
    system("cls");
}

void gotoxy (int x, int y)
{
    COORD coord = { 0,0 };
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
