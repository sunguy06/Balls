#include "TXLib.h"
#define SIZE 1100


struct tBalls
    {
    double x, y;
    double Vx, Vy;
    double Radius;
    double Red, Green, Blue;
    };

void DrawBall (tBalls Shariki[]);
void MoveBall (tBalls Shariki[]);

int main ()
    {
    txCreateWindow(1500, 1000);

    srand(time(NULL));

    tBalls Shariki[SIZE];

    for(int i = 0; i < SIZE; i ++)
        {
        Shariki[i].Radius = random(30) + 5;
        Shariki[i].x =      random(1500 - Shariki[i].Radius) + Shariki[i].Radius;
        Shariki[i].y =      random(1000 - Shariki[i].Radius) + + Shariki[i].Radius;
        Shariki[i].Vx =     (random(2) - 1) ? random(2) + 1 : -1 * (random(2) + 1);
        Shariki[i].Vy =     (random(2) - 1) ? random(2) + 1 : -1 * (random(2) + 1);
        Shariki[i].Red =    random(155) + 100;
        Shariki[i].Green =  random(155) + 100;
        Shariki[i].Blue =   random(155) + 100;
        }

    while (!GetAsyncKeyState (VK_ESCAPE))
        {

      //  printf ("%f %f %f %f", Shariki[0].x, Shariki[0].y, Shariki[0].Vx, Shariki[0].Vy);
       // while (!GetAsyncKeyState (VK_SPACE)) {}

        DrawBall(Shariki);
        MoveBall(Shariki);
        }
    }

void DrawBall (tBalls Shariki[])
    {
    txBegin();
    txClear();
    for(int i = 0; i < SIZE; i ++)
        {
        txSetColor    (RGB(Shariki[i].Red, Shariki[i].Green, Shariki[i].Blue));
        txSetFillColor(RGB(Shariki[i].Red, Shariki[i].Green, Shariki[i].Blue));
        txCircle      (Shariki[i].x, Shariki[i].y, Shariki[i].Radius);
        txSetFillColor(TX_BLACK);
        //printf ("%f, %f", Shariki[i].x, Shariki[i].y);
        }
    txEnd();
    }

void MoveBall (tBalls Shariki[])
    {
    for(int i = 0; i < SIZE; i ++)
        {
        Shariki[i].x += Shariki[i].Vx;
        Shariki[i].y += Shariki[i].Vy;

        if (Shariki[i].x >= 1500 - Shariki[i].Radius) Shariki[i].Vx = -1 * Shariki[i].Vx;
        if (Shariki[i].y >= 1000 - Shariki[i].Radius) Shariki[i].Vy = -1 * Shariki[i].Vy;
        if (Shariki[i].x <= Shariki[i].Radius)        Shariki[i].Vx = -1 * Shariki[i].Vx;
        if (Shariki[i].y <= Shariki[i].Radius)        Shariki[i].Vy = -1 * Shariki[i].Vy;
        }
    }

