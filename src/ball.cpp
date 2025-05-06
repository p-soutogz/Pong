#include "ball.h"
#include <raylib.h>


Ball::Ball(float x, float y){
    this->x=x;
    this->y=y;
    speedX = 5;
    speedY = 5;
    radius = 15;
    int player_score = 0;
    int CPU_score = 0;
}

void Ball::resetBall(){
    this->x=GetScreenWidth()/2;
    this->y=GetScreenHeight()/2;
    int speed_choices[2] = {1,-1};
    this->speedX *=speed_choices[GetRandomValue(0,1)];
    this->speedY *=speed_choices[GetRandomValue(0,1)];
}

void Ball::Update()
{
    x += speedX;
    y += speedY;

    if (x + radius >= GetScreenWidth()){
        
        player_score +=1;
        resetBall();
    }
    if ( x - radius <= 0){
        resetBall();
        CPU_score +=1;
    }
    if (y + radius >= GetScreenHeight() || y - radius <= 0){
        speedY *= -1;
       
    }
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}