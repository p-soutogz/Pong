#include <raylib.h>
#include "ball.h"
#include <iostream>
#include "padel.h"
#include "CpuPadel.h"

using namespace std;

int main()
{

    
    cout<<"hello";
    const int width =  1280;
    const int height = 800;
    InitWindow(width,height,"My pong game");

    SetTargetFPS(60);

    Ball ball(width/2,height/2);
    Padel padel1(10,height/2-60,25,120);
    CpuPadel padel2(width-35,height/2-60,25,120);

    while(WindowShouldClose() == false){

        BeginDrawing();

        DrawText(TextFormat("%i",ball.CPU_score),width/4-20 ,20,80,WHITE);
        DrawText(TextFormat("%i",ball.player_score),3*width/4-20,20,80,WHITE);
        
        ball.Update();
        padel1.Update();
        padel2.Update(ball.y);
        ClearBackground(BLACK);


        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{padel1.x,padel1.y,padel1.width,padel1.height})){
            ball.speedX *=-1;
        }
        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{padel2.x,padel2.y,padel2.width,padel2.height})){
            ball.speedX *=-1;
        }

        ball.Draw();

        padel1.Draw();
        padel2.Draw();


        DrawLine(width/2, 0, width/2, height, WHITE);

        EndDrawing();


    }

    CloseWindow();
    return 0;
}