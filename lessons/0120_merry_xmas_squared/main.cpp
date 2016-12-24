#include <iostream>
#include <ctime>
#include <vector>
#include "../../vsgl2.h"

using namespace std;
using namespace vsgl2;
using namespace vsgl2::general;
using namespace vsgl2::video;
using namespace vsgl2::utils;
using namespace vsgl2::io;

const int N = 80;
const int DIM_FLAKE = 7;
const int SPEED = 20;

struct flake{
    int x;
    double y, v;
    Color c;
    flake(){}
};

vector <flake> flakes;

void init_flakes()
{
    for (int i = 0; i < N; i++){
        flake f;
        f.x = rand()%get_window_width();
        f.y = (double)rand()/RAND_MAX;
        f.v = 0.000001 + (100 + rand()%200)*0.000001;
        f.c = Color(255,255,255,100 + rand()%155);
        flakes.push_back(f);
    }
}

void update_flakes(){
    for (auto f = flakes.begin(); f!= flakes.end(); ++f){
        f->y += f->v;
        if (f->y >= 1)
            f->y = 0;
    }
}


int main(int argc, char* argv[]) {

    //init the library
    init();
    //create the window and show it
    set_window(512,512,"Vsgl2 Merry X-Mas");
    //main loop

    int w = get_window_width();
    int h = get_window_height();
    init_flakes();
    int alpha = 0;
    int dir = 1;
    while(!done())
    {
        alpha += dir;
        if (dir && alpha/SPEED > 250)
            dir = - dir;
        if (dir == -1 && alpha < 0)
            dir = - dir;
        draw_filled_rect(0,0,w,h,Color(0,0,100,255));
        draw_image("merry.jpg",32,100,440,221);
        draw_filled_rect(32,100,440,221,Color(0,0,100,255 - (alpha/SPEED)%255));
        update_flakes();
        for (auto f = flakes.begin(); f!= flakes.end(); ++f)
            draw_filled_rect(f->x,
                             f->y * get_window_height(),
                             DIM_FLAKE,DIM_FLAKE,f->c);

        update();
    }

    //close the library and clean up everything
    close();
    return 0;
}
