#include "clock.h"
#include<iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>

#define PI 3.1415

using namespace std;

Clock::Clock()
{
    initwindow(700,700,"SHAKIN'S ANALOG CLOCK");
}

void Clock::analogClock()
{
        while(1)
    {
         setactivepage(page);
         setvisualpage(1-page);
         cleardevice();

         setbkcolor(CYAN);

         setcolor(BLACK);
         circle(350,350,160);
         setfillstyle(SOLID_FILL,CYAN);
         floodfill(350,350,BLACK);

         setcolor(BLACK);
         circle(350,350,135);
         setfillstyle(XHATCH_FILL,LIGHTBLUE);
         floodfill(350,350,BLACK);

         setcolor(WHITE);
         circle(350,350,5);
         setfillstyle(SOLID_FILL,WHITE);
         floodfill(350,350,WHITE);

         setcolor(LIGHTRED);
         outtextxy(295,250,"SHAKIN'S CLOCK");

         outtextxy(350+150*sin(1*PI/6)-5 ,  350-150*cos(1*PI/6)-7 , "1");
         outtextxy(350+150*sin(2*PI/6)-5 ,  350-150*cos(2*PI/6)-7 , "2");
         outtextxy(350+150*sin(3*PI/6)-5 ,  350-150*cos(3*PI/6)-7 , "3");
         outtextxy(350+150*sin(4*PI/6)-5 ,  350-150*cos(4*PI/6)-7 , "4");
         outtextxy(350+150*sin(5*PI/6)-5 ,  350-150*cos(5*PI/6)-7 , "5");
         outtextxy(350+150*sin(6*PI/6)-5 ,  350-150*cos(6*PI/6)-7 , "6");
         outtextxy(350+150*sin(7*PI/6)-5 ,  350-150*cos(7*PI/6)-7 , "7");
         outtextxy(350+150*sin(8*PI/6)-5 ,  350-150*cos(8*PI/6)-7 , "8");
         outtextxy(350+150*sin(9*PI/6)-5 ,  350-150*cos(9*PI/6)-7 , "9");
         outtextxy(350+150*sin(10*PI/6)-5 , 350-150*cos(10*PI/6)-7 , "10");
         outtextxy(350+150*sin(11*PI/6)-5 , 350-150*cos(11*PI/6)-7 , "11");
         outtextxy(350+150*sin(12*PI/6)-5 , 350-150*cos(12*PI/6)-7 , "12");

         time_t now = time(0);
         tm *ltm = localtime(&now);
         system("cls");
         cout<<ltm->tm_hour-12<<"."<<ltm->tm_min;


         setcolor(WHITE);
         line(350,350,350+70*sin(ltm->tm_hour * PI/6),350-70*cos(ltm->tm_hour * PI/6));

         setcolor(RED);
         line(350,350,350+100*sin(ltm->tm_min * PI/30),350-100*cos(ltm->tm_min * PI/30));

         setcolor(BLACK);
         line(350,350,350+130*sin(ltm->tm_sec * PI/30),350-130*cos(ltm->tm_sec * PI/30));

         if(GetAsyncKeyState(VK_RETURN))
              break;
         delay(10);

         page = 1-page;
    }


}

Clock::~Clock()
{
    closegraph();

}
