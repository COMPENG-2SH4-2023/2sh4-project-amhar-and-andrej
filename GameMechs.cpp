#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    score = 0;
    loseflag = false;
    boardSizeX = 30;
    boardSizeY = 10;
}


GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    score = 0;
    loseflag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;

}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{

}


void GameMechs::setExitTrue()
{

}


bool getLoseFlagStatus::getLoseFlagStatus()
{

}


void setLoseFlag::setLoseFlag()
{

}


char GameMechs::getInput()
{

}


void GameMechs::setInput(char this_input)
{
    input = this_input;
}


void GameMechs::clearInput()
{

}



int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}


int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


int getScore::getScore()
{
    return score;
}


void incrementScore::incrementScore()
{
    score++;
}