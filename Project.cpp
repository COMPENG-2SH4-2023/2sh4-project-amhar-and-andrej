#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"



using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;
Food* myFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30, 15); //   30X15
    myPlayer = new Player(myGM);
    myFood = new Food();

    //generateFood() requires a player reference. you will need to provide it after player object is instantiated.
    objPos foodPos;
    objPos playerPos;


    myPlayer->getPlayerPos(playerPos);
    myFood->generateFood(playerPos);




}

void GetInput(void)
{
    myGM->getInput();
    
    int input = myGM->getInput();
    objPos playerPos;

    if (input == 32)
        myFood->generateFood(playerPos);
    
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    for(int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            
            if(i == 0 || i == 14 || j == 0 || j == 29)
            {   
                MacUILib_printf("#");
                
            }
            else 
            {   
                objPos playerPos;
                myPlayer->getPlayerPos(playerPos);
                if (i == playerPos.y && j == playerPos.x) 
                {
                    MacUILib_printf("%c", playerPos.symbol);
                } 
                else
                {
                    
                    objPos foodPos;
                    myFood->getFoodPos(foodPos);

                    if (i == foodPos.y && j == foodPos.x) 
                    {
                        MacUILib_printf("%c", foodPos.symbol);
                    } 
                    else
                        MacUILib_printf(" ");    

                }

            }
        }
        MacUILib_printf("\n");    
    }
}
    

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM;
    delete myPlayer;
    delete myFood;  
}
