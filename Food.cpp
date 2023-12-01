#include "Food.h"
#include "MacUILib.h"



Food::Food()
{
    foodPos.setObjPos(-1, -1, '$'); //initializing the food position outside of the game board (so to not be displayed)
    srand(time(NULL));
}


Food::~Food()
{

}


void Food::generateFood(objPos blockOff)
{
    //generate random x and y(not border and block off position)
    //check x and y against 0 and boardSizeX or boardSizeY
    
    // in objPos you have an isPosEqual() method, use this to compare instead of doing element-by-element

    int xCand, yCand; 

    
    do
    {
        xCand = 1 + rand() % 28;
        yCand = 1 + rand() % 13;

        foodPos.setObjPos(xCand, yCand, '$');


    } while (blockOff.isPosEqual(&foodPos));
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}