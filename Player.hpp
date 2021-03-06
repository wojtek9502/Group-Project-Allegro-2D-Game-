#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include<math.h>
#define ARROW_LENGHT 60.0
#define M_PI 3.14
using namespace std;

/**
 * Klasa player
 */
class Player{

public:
    string name;
    float x_position;
    float y_position;
    int hp;
    float x_rotate_point;
    float y_rotate_point;
    float x_arrow_point;
    float y_arrow_point;
    float arrow_angle;
    float Vo=100;


    /**
     * Konstruktor klasy Player
     * @param name
     * @param x_position
     * @param y_position
     * @param hp
     */
    Player(string name, int x_position, int y_position, int hp=100)
    {
        this->name=name;
        this->x_position=x_position;
        this->y_position=y_position;
        this->hp=hp;

        this->x_arrow_point=x_position;
        this->y_arrow_point=y_position;
        this->x_rotate_point=x_position;
        this->y_arrow_point=y_position;

        if(this->name=="dog"){
            this->arrow_angle=0;
        }
        else{
            this->arrow_angle=0;
        }
        this->Vo = 200.0;

    }

    /**
     * Ruch postaci w Lewo
     * @param pixels
     */
    void move_left(float pixels=0.5)
    {
        x_position = x_position-pixels;
    }

    /**
     * Ruch postaci w prawo
     * @param pixels
     */
    void move_right(float pixels=0.5)
    {
        x_position = x_position+pixels;
    }

    /**
     * Ruch kreski odpowiedzialnej za wybór kąta rzutu
     * @param angle
     * @param player
     */
    void move_arrow(double angle, Player player)
    {

            //add angle param to current arrow_angle in Player class
             arrow_angle += angle;

            //check angle restrict
             if(player.name.compare("dog")==0)
            {
                if(arrow_angle<0)
                    arrow_angle = 0;
                if(arrow_angle>90)
                    arrow_angle = 90;
            }
            else
            {
                if(arrow_angle>180)
                    arrow_angle = 180;
                if(arrow_angle<90)
                    arrow_angle =90;
            }

            //convert degrees to radians
             float arrow_angle_radians = conv_to_radian(arrow_angle);

             //init variables for formula
             float x1 = x_position+ARROW_LENGHT;   // x punktu obracanego (wartosc po + reguluje dlugosc strzalki)
             float x2 = x_position;                // x punktu srodka obrotu
             float y1 = y_position;   // y punktu obracanego (wartosc po + reguluje dlugosc strzalki)
             float y2 = y_position;                // y punktu srodka obrotu



            //caltulate new arrow_end coordinates, x3 and y3 are coordinates a new rotate point
            float x3 = ((x1-x2)*cos(arrow_angle_radians) + (y1-y2)*sin(arrow_angle_radians) + x2);
            float y3 = -((x1-x2)*sin(arrow_angle_radians) - (y1-y2)*cos(arrow_angle_radians) - y2);

            //set arrow position in Player class
            x_arrow_point = x3;
            y_arrow_point = y3;

            //cout << "arrow_end=(" << x_arrow_point << ", " << y_arrow_point << ")" << endl;
           // cout << "sin angle: " << sin(arrow_angle_radians) << endl;
           // cout << "cos angle: " << cos(arrow_angle_radians) << endl;
            //cout << "angle: " << arrow_angle << endl;

    }

/**
 * Konwersja stopni na radiany
 * @param degree_angle
 * @return
 */
double conv_to_radian(double degree_angle)
{
    return degree_angle * (M_PI/180);
}



};


#endif // PLAYER_HPP_INCLUDED
