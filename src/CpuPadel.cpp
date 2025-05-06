#include "CpuPadel.h"
#include <raylib.h>

CpuPadel::CpuPadel(float x,float y,float width,float height): Padel(x, y, width, height)
{

};

void CpuPadel::Update(int ball_y){
    if(y + height/2 > ball_y){
        y=y-speed;
    }
    if(y + height/2 <= ball_y){
        y=y+speed;
    }
    LimitMovement();
}