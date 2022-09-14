#include "SFML/Graphics.hpp"
#include <iostream>




int main()
{
    const int WIDTH = 1920;
    const int HEIGTH = 1080;

    const int MAX_OBJ = 20;
    const int LEN_OBJ = 15;
    const int MAX_REFLECT = 200;
    const int COUNT_LIGHTS = 1;
    const int ID_LIGHTS[COUNT_LIGHTS] = { 2 };

    sf::Vector3f player_pos;
    player_pos.x = -2;
    player_pos.y = 0;
    player_pos.z = 2;

    sf::Vector2f player_dir_angle;
    player_dir_angle.x = 0;
    player_dir_angle.y = 0;

    sf::Vector2f old_mouse = sf::Vector2f(WIDTH/2,HEIGTH/2);

    float objects[MAX_OBJ * LEN_OBJ]; // 0 - type  1 - x                 2 - y                  3- z   4 - radius( type-1 )        5 - r              6 - g                 7 - b

    for (int i = 0; i < MAX_OBJ*LEN_OBJ; i++) {
        objects[i] = 0.0;
    }

    /*
    objects[0] = 1.0;//type                          # 1 #  CIRCLE RED
    objects[1] = 10.0;//x
    objects[2] = 0.0;//y
    objects[3] = 0.0;//z
    objects[4] = 1.0;//ra

    objects[5] = 1.0;//r
    objects[6] = 0.0;//g
    objects[7] = 0.0;//b
    objects[8] = 1.0;// alpha k





    objects[LEN_OBJ *1 +0] = 1.0;//type              # 2 #   CIRCLE BLUE
    objects[LEN_OBJ * 1 + 1] = 0.0;//x
    objects[LEN_OBJ * 1 + 2] = 10.0;//y
    objects[LEN_OBJ * 1 + 3] = 0.0;//z
    objects[LEN_OBJ * 1 + 4] = 1.0;//ra

    objects[LEN_OBJ * 1 + 5] = 0.541;//r
    objects[LEN_OBJ * 1 + 6] = 0.95;//g
    objects[LEN_OBJ * 1 + 7] = 0.247;//b

    objects[LEN_OBJ * 1 + 8] = 1.0;// alpha k



    objects[LEN_OBJ * 2 + 0] = 1.0;//type            # 3 Light # CIRCLE LIGHT
    objects[LEN_OBJ * 2 + 1] = 0.0;//x
    objects[LEN_OBJ * 2 + 2] = 0.0;//y
    objects[LEN_OBJ * 2 + 3] = 10.0;//z
    objects[LEN_OBJ * 2 + 4] = 0.5;//ra

    objects[LEN_OBJ * 2 + 5] = 1.0;//r
    objects[LEN_OBJ * 2 + 6] = 1.0;//g
    objects[LEN_OBJ * 2 + 7] = 1.0;//b

    objects[LEN_OBJ * 2 + 8] = 1.0;// alpha k

    objects[LEN_OBJ * 3 + 0] = 1.0;//type            # 4 # CIRCLE YELLOW
    objects[LEN_OBJ * 3 + 1] = 5.0;//x
    objects[LEN_OBJ * 3 + 2] = 0.0;//y
    objects[LEN_OBJ * 3 + 3] = 5.0;//z
    objects[LEN_OBJ * 3 + 4] = 1.0;//ra


    objects[LEN_OBJ * 3 + 5] = 1.0;//r
    objects[LEN_OBJ * 3 + 6] = 1.0;//g
    objects[LEN_OBJ * 3 + 7] = 0.0;//b

    objects[LEN_OBJ * 3 + 8] = 1.0;// alpha k

    objects[LEN_OBJ * 4 + 0] = 2.0;//type            # 5 # TRIANGLE AREA

    objects[LEN_OBJ * 4 + 1] = +20.0;//point 1 x
    objects[LEN_OBJ * 4 + 2] = -20.0;//point 1 y
    objects[LEN_OBJ * 4 + 3] = -2.0; //point 1 z

    objects[LEN_OBJ * 4 + 4] = -20.0;//point 2 x
    objects[LEN_OBJ * 4 + 5] = +20.0;//point 2 y
    objects[LEN_OBJ * 4 + 6] = -2.0; //point 2 z

    objects[LEN_OBJ * 4 + 7] = -20.0;//point 3 x
    objects[LEN_OBJ * 4 + 8] = -20.0;//point 3 y
    objects[LEN_OBJ * 4 + 9] = -2.0; //point 3 z

    objects[LEN_OBJ * 4 + 10] = 0.5;//r
    objects[LEN_OBJ * 4 + 11] = 0.5;//g
    objects[LEN_OBJ * 4 + 12] = 0.5;//b

    objects[LEN_OBJ * 4 + 13] = 1.0;// alpha k


    objects[LEN_OBJ * 5 + 0] = 2.0;//type            # 6 # TRIANGLE2 AREA

    objects[LEN_OBJ * 5 + 1] = +20.0;//point 1 x
    objects[LEN_OBJ * 5 + 2] = +20.0;//point 1 y
    objects[LEN_OBJ * 5 + 3] = -2.0; //point 1 z

    objects[LEN_OBJ * 5 + 4] = -20.0;//point 2 x
    objects[LEN_OBJ * 5 + 5] = +20.0;//point 2 y
    objects[LEN_OBJ * 5 + 6] = -2.0; //point 2 z

    objects[LEN_OBJ * 5 + 7] = +20.0;//point 3 x
    objects[LEN_OBJ * 5 + 8] = -20.0;//point 3 y
    objects[LEN_OBJ * 5 + 9] = -2.0; //point 3 z

    objects[LEN_OBJ * 5 + 10] = 0.5;//r
    objects[LEN_OBJ * 5 + 11] = 0.5;//g
    objects[LEN_OBJ * 5 + 12] = 0.5;//b

    objects[LEN_OBJ * 5 + 13] = 1.0;// alpha k


    */
    /*
    int k_id=0;
    objects[0] = 1.0;//type                          # 1 #  CIRCLE RED
    objects[1] = 0.0;//x
    objects[2] = 0.0;//y
    objects[3] = 1.0;//z
    objects[4] = 1.0;//ra

    objects[5] = 1.0;//r
    objects[6] = 0.0;//g
    objects[7] = 0.0;//b

    objects[8] = 0.0;// mat
    objects[9] = 0.0;// prosrachnost


    k_id = 1;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 2 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 0.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.0;//r
    objects[LEN_OBJ * k_id + 11] = 0.0;//g
    objects[LEN_OBJ * k_id + 12] = 0.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// 




    k_id = 2;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 3 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 0.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.0;//r
    objects[LEN_OBJ * k_id + 11] = 0.0;//g
    objects[LEN_OBJ * k_id + 12] = 0.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo

    k_id = 3;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 5 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = +10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = +10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 0.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 4;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 4 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 0.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo


    k_id = 5;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 6 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 0.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.0;//r
    objects[LEN_OBJ * k_id + 11] = 0.0;//g
    objects[LEN_OBJ * k_id + 12] = 0.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 6;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 7 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.0;//r
    objects[LEN_OBJ * k_id + 11] = 0.0;//g
    objects[LEN_OBJ * k_id + 12] = 0.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo


    k_id = 7;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 8 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 0.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 8;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 9 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo

    k_id = 9;
    objects[LEN_OBJ * k_id + 0] = 1.0;//type                          # 10 #  CIRCLE LIGHT
    objects[LEN_OBJ * k_id + 1] = -10.0;//x
    objects[LEN_OBJ * k_id + 2] = 10.0;//y
    objects[LEN_OBJ * k_id + 3] = 20.0;//z
    objects[LEN_OBJ * k_id + 4] = 1.0;//ra

    objects[LEN_OBJ * k_id + 5] = 1.0;//r
    objects[LEN_OBJ * k_id + 6] = 1.0;//g
    objects[LEN_OBJ * k_id + 7] = 1.0;//b
    objects[LEN_OBJ * k_id + 8] = 1.0;// mat
    objects[LEN_OBJ * k_id + 9] = 0.0;// zerkalo









    k_id = 10;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 11 # TRIANGLE2 AREA                             ///STENA1

    objects[LEN_OBJ * k_id + 1] = -10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 11;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 12 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = -10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 10.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo










    k_id = 12;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 13 # TRIANGLE2 AREA                             ///STENA2

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 10.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo






    k_id = 13;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 14 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo




    k_id = 14;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 15 # TRIANGLE2 AREA                        ///STENA3

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo






    k_id = 15;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 16 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 10.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo
    */


    int k_id = 0;
    objects[0] = 1.0;//type                          # 1 #  CIRCLE RED
    objects[1] = 0.0;//x
    objects[2] = 0.0;//y
    objects[3] = 1.0;//z
    objects[4] = 1.0;//ra

    objects[5] = 1.0;//r
    objects[6] = 0.0;//g
    objects[7] = 0.0;//b

    objects[8] = 0.0;// mat
    objects[9] = 0.0;// prosrachnost


    k_id = 1;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 2 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 0.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.2;//r
    objects[LEN_OBJ * k_id + 11] = 0.2;//g
    objects[LEN_OBJ * k_id + 12] = 0.2;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// 




    k_id = 2;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 3 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 0.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.2;//r
    objects[LEN_OBJ * k_id + 11] = 0.2;//g
    objects[LEN_OBJ * k_id + 12] = 0.2;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo

    k_id = 3;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 5 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = +10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = +10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 0.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 4;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 4 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 0.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo


    k_id = 5;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 6 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 0.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.2;//r
    objects[LEN_OBJ * k_id + 11] = 0.2;//g
    objects[LEN_OBJ * k_id + 12] = 0.2;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 6;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 7 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 0.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 0.2;//r
    objects[LEN_OBJ * k_id + 11] = 0.2;//g
    objects[LEN_OBJ * k_id + 12] = 0.2;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo


    k_id = 7;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 8 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 0.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 0.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 8;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 9 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 0.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 0.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 0.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo

    k_id = 9;
    objects[LEN_OBJ * k_id + 0] = 1.0;//type                          # 10 #  CIRCLE LIGHT
    objects[LEN_OBJ * k_id + 1] = 8.0;//x
    objects[LEN_OBJ * k_id + 2] = 0.0;//y
    objects[LEN_OBJ * k_id + 3] = 10.0;//z
    objects[LEN_OBJ * k_id + 4] = 1.0;//ra

    objects[LEN_OBJ * k_id + 5] = 1.0;//r
    objects[LEN_OBJ * k_id + 6] = 1.0;//g
    objects[LEN_OBJ * k_id + 7] = 1.0;//b
    objects[LEN_OBJ * k_id + 8] = 1.0;// mat
    objects[LEN_OBJ * k_id + 9] = 0.0;// zerkalo





    k_id = 10;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 11 # TRIANGLE  wall 1 1

    objects[LEN_OBJ * k_id + 1] = -5.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -5.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -5.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -5.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 5.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -5.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 5.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo

    k_id = 11;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 12 # TRIANGLE  wall 1 2

    objects[LEN_OBJ * k_id + 1] = -5.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -5.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 5.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -5.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 5.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 5.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -5.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 5.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo




    k_id = 12;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 13 # TRIANGLE  wall 2 1

    objects[LEN_OBJ * k_id + 1] = 5.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -5.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 5.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -5.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 5.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 5.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 5.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo



    k_id = 13;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 14 # TRIANGLE  wall 2 2

    objects[LEN_OBJ * k_id + 1] = 5.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -5.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 5.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 5.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 5.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 5.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 5.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 5.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo

    



    k_id = 14;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 15 # TRIANGLE2 AREA                        ///STENA3

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo






    k_id = 15;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 16 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = 10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 10.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = -10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo
    


    k_id = 16;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 17 # TRIANGLE2 AREA                             ///STENA1

    objects[LEN_OBJ * k_id + 1] = -10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = -10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 1.0;// zerkalo



    k_id = 17;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 18 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = -10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 10.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = -10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 0.0;// mat
    objects[LEN_OBJ * k_id + 14] = 1.0;// zerkalo










    k_id = 18;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 19 # TRIANGLE2 AREA                             ///STENA2

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = -10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 10.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo






    k_id = 19;
    objects[LEN_OBJ * k_id + 0] = 2.0;//type            # 20 # TRIANGLE2 AREA

    objects[LEN_OBJ * k_id + 1] = 10.0;//point 1 x
    objects[LEN_OBJ * k_id + 2] = -10.0;//point 1 y
    objects[LEN_OBJ * k_id + 3] = 0.0; //point 1 z

    objects[LEN_OBJ * k_id + 4] = 10.0;//point 2 x
    objects[LEN_OBJ * k_id + 5] = 10.0;//point 2 y
    objects[LEN_OBJ * k_id + 6] = 10.0; //point 2 z

    objects[LEN_OBJ * k_id + 7] = 10.0;//point 3 x
    objects[LEN_OBJ * k_id + 8] = 10.0;//point 3 y
    objects[LEN_OBJ * k_id + 9] = 0.0; //point 3 z

    objects[LEN_OBJ * k_id + 10] = 1.0;//r
    objects[LEN_OBJ * k_id + 11] = 1.0;//g
    objects[LEN_OBJ * k_id + 12] = 1.0;//b

    objects[LEN_OBJ * k_id + 13] = 1.0;// mat
    objects[LEN_OBJ * k_id + 14] = 0.0;// zerkalo




    //objects[0][0] = 1.0; objects[0][1] = 6.0; objects[0][2] = 0.0; objects[0][3] = 0.0; objects[0][4] = 1.0; objects[0][5] = 1.0; objects[0][6] = 1.0; objects[0][7] = 1.0;


    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "SFML Shader Example");
    window.setMouseCursorVisible(false);
    sf::Texture tex;
    tex.create(WIDTH, HEIGTH);
    sf::Sprite spr(tex);
    sf::Shader shader;
    shader.loadFromFile("Raytrace.frag", sf::Shader::Fragment); 

    if (!shader.isAvailable()) {
        std::cout << "The shader is not available\n";
    }
    sf::Clock clk;
    clk.restart();
    shader.setUniform("resolution", sf::Vector2f(WIDTH, HEIGTH));
    float time_g=0;
    long long time_gint=0;

    //               w a s d space shift ctrl
    bool wasd[7] = { 0,0,0,0,  0  ,  0  , 0};
    sf::Vector2i mouse1;

    sf::Mouse::setPosition(sf::Vector2i(WIDTH / 2, HEIGTH / 2), window);
    while (window.isOpen()) {
        sf::Event event;
        time_g += 0.001;
        time_gint += 1;
        if (time_gint % 1000 == 0) {
            std::cout << player_pos.x <<" "<< player_pos.y <<" "<< (player_dir_angle.x) <<" "<< (player_dir_angle.y) << std::endl;
        }
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {


                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::W) {
                    wasd[0] = true;
                }
                if (event.key.code == sf::Keyboard::A) {
                    wasd[1] = true;
                }
                if (event.key.code == sf::Keyboard::S) {
                    wasd[2] = true;
                }
                if (event.key.code == sf::Keyboard::D) {
                    wasd[3] = true;
                }

                if (event.key.code == sf::Keyboard::Space) {
                    wasd[4] = true;
                }
                if (event.key.code == sf::Keyboard::LShift) {
                    wasd[5] = true;
                }
                if (event.key.code == sf::Keyboard::LControl) {
                    wasd[6] = true;
                }
               



            }

            if (event.type == sf::Event::KeyReleased)
            {


                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::W) {
                    wasd[0] = false;
                }
                if (event.key.code == sf::Keyboard::A) {
                    wasd[1] = false;
                }
                if (event.key.code == sf::Keyboard::S) {
                    wasd[2] = false;
                }
                if (event.key.code == sf::Keyboard::D) {
                    wasd[3] = false;
                }

                if (event.key.code == sf::Keyboard::Space) {
                    wasd[4] = false;
                }
                if (event.key.code == sf::Keyboard::LShift) {
                    wasd[5] = false;
                }
                if (event.key.code == sf::Keyboard::LControl) {
                    wasd[6] = false;
                }



            }


        }

        if (wasd[0] && !wasd[2]) {
            player_pos.x += 0.01*cos(player_dir_angle.x);
            player_pos.y += 0.01*sin(player_dir_angle.x);
        }

        if (wasd[1] && !wasd[3]) {
            player_pos.x += 0.01 * sin(player_dir_angle.x);
            player_pos.y -= 0.01 * cos(player_dir_angle.x);
        }

        if (wasd[2] && !wasd[0]) {
            player_pos.x -= 0.01 * cos(player_dir_angle.x);
            player_pos.y -= 0.01 * sin(player_dir_angle.x);
        }

        if (wasd[3] && !wasd[1]) {
            player_pos.x -= 0.01 * sin(player_dir_angle.x);
            player_pos.y += 0.01 * cos(player_dir_angle.x);
        }

        if (wasd[6] && !wasd[4]) {
            player_pos.z -= 0.01 ;
      
        }

        if (wasd[4] && !wasd[6]) {
            player_pos.z += 0.01;

        }

        objects[LEN_OBJ * 0 + 3] += 0.001*sin(time_g);
        objects[LEN_OBJ * 9 + 3] += 0.003 * sin(time_g);
        if (window.hasFocus()){
            mouse1 = sf::Mouse::getPosition(window);
            player_dir_angle.x += (mouse1.x - old_mouse.x) / 300;
            player_dir_angle.y += (old_mouse.y - mouse1.y) / 300;
            sf::Mouse::setPosition(sf::Vector2i(WIDTH / 2, HEIGTH / 2), window);

        }
        

        shader.setUniform("player_pos", player_pos);
        shader.setUniform("player_dir_angle", player_dir_angle);
        shader.setUniform("time", time_g);
        shader.setUniformArray("objects", objects, MAX_OBJ*LEN_OBJ);



        window.clear();
        window.draw(spr, &shader);
        window.display();
    }
    return 0;
}