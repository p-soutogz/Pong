#pragma once


class Ball
{
public:

    Ball(float x, float y);
    void Update();
    void Draw();
    void resetBall();

    float x,y;
    float speedX;
    float speedY;
    int radius;
    int player_score;
    int CPU_score; 
};
