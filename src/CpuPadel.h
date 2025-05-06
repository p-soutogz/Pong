#pragma once
#include "padel.h"

class CpuPadel: public Padel{
    public:
        CpuPadel(float x,float y,float width,float height);
        void Update(int ball_y);
};