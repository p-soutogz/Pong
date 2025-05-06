#include "padel.h"
#include <raylib.h>


Padel::Padel(float x,float y, float width,float height){
    this->x=x;
    this->y=y;
    this->height=height;
    this->width=width;
    this->speed=7;
}

void Padel::Draw(){

    DrawRectangle(x,y,width,height,WHITE);

}

void Padel::LimitMovement(){
    
    if(y<0){
        y=0;
    }
    if(y+height>=GetScreenHeight()){
        y=GetScreenHeight()-height;
    }

}

void Padel::Update(){
    if(IsKeyDown(KEY_UP)){
        y=y-speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        y=y+speed;
    }
    if(y<0){
        y=0;
    }
    if(y+height>=GetScreenHeight()){
        y=GetScreenHeight()-height;
    }

    LimitMovement();

}

