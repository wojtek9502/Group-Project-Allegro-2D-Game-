#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include "player.hpp"
using namespace std;

bool run_menu_start(ALLEGRO_MOUSE_STATE mouse, ALLEGRO_DISPLAY* display, ALLEGRO_MOUSE_CURSOR* cursor, bool end_menu_start)
{

     if((mouse.x >=300 && mouse.x <=500) && (mouse.y >= 150 && mouse.y <=201))
        {

            printf("one player: (%d, %d)\n", mouse.x, mouse.y);
            al_set_mouse_cursor(display, cursor);
            al_rest(0.1);
            if(mouse.buttons & 1){
                cout<<"clicked one player: x:"<<mouse.x<<"y: "<<mouse.y<<endl;
                end_menu_start = true;
            }
        }

        if((mouse.x >=300 && mouse.x <=500) && (mouse.y >=230 && mouse.y <=281))
        {
            printf("two player: (%d, %d)\n", mouse.x, mouse.y);
            al_set_mouse_cursor(display, cursor);
            al_rest(0.1);
            if(mouse.buttons & 1){
                cout<<"clicked one player: x:"<<mouse.x<<"y: "<<mouse.y<<endl;
                end_menu_start = true;
            }
        }

    return end_menu_start;
}

Player check_dog_move(ALLEGRO_KEYBOARD_STATE keyboard, Player dog){

    if(al_key_down(&keyboard, ALLEGRO_KEY_A))
    {
       //cout << "pies w lewo" << endl;
       dog.move_left();
    }

    if(al_key_down(&keyboard, ALLEGRO_KEY_D))
    {
        //cout << "pies w prawo" << endl;
        dog.move_right();
    }

    return dog;
}

Player check_cat_move(ALLEGRO_KEYBOARD_STATE keyboard, Player cat)
{
 if(al_key_down(&keyboard, ALLEGRO_KEY_J))
    {
        //cout << "kot w lewo" << endl;
        cat.move_left();
    }

    if(al_key_down(&keyboard, ALLEGRO_KEY_L))
    {
        //cout << "kot w prawo" << endl;
        cat.move_right();
    }
    return cat;
}


#endif // GAME_HPP_INCLUDED
