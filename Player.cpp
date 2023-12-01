#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@');
}


Player::~Player()
{
    // delete any heap members here
    // NO heap member right now 
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    char input = mainGameMechsRef->getInput(); //getting the current input

    switch(input)
        {           
            //UP
            case 119:  
                if(myDir != DOWN || myDir == STOP)
                    myDir = UP;
                break;

            //LEFT
            case 97:    
                if(myDir != RIGHT || myDir == STOP)
                    myDir = LEFT;
                break;

            //DOWN    
            case 115: 
                if(myDir != UP || myDir == STOP)
                    myDir = DOWN;
                break;

            //RIGHT
            case 100:   
                if(myDir != LEFT || myDir == STOP)
                    myDir = RIGHT;
                break;

            case 27: //Press escape to stop the game
                mainGameMechsRef->setExitTrue();
                break;

            default:
                break;
        }


}

void Player::movePlayer()
{

    // PPA3 Finite State Machine logic
    switch (myDir) 
    {
        case UP:
            playerPos.y--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        default:
            break;
    }

    if (playerPos.y == 0) {
        playerPos.y = mainGameMechsRef->getBoardSizeY() - 2; // Wrap to the bottom
    } else if (playerPos.y == mainGameMechsRef->getBoardSizeY() - 1) {
        playerPos.y = 1; // Wrap to the top
    }

    if (playerPos.x == 0) {
        playerPos.x = mainGameMechsRef->getBoardSizeX() - 2; // Wrap to the right
    } else if (playerPos.x == mainGameMechsRef->getBoardSizeX() - 1) {
        playerPos.x = 1; // Wrap to the left
    }
}

