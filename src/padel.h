#pragma once

class Padel{

    public:
        float x, y;
        int speed;
        float width,height;

        Padel(float x,float y,float width,float height);
        void Draw();
        void Update();

    protected:
        void LimitMovement();    
};
