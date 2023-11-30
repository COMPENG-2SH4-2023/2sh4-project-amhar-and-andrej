#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; //200 elements on the heap
    sizeList = 0;                      //no valid element in the list upon startup
    sizeArray = ARRAY_MAX_CAP;     // array capacity should be set to the max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // delete[] calls destructors of all instances in the array
}                   //Otherwise only the first element is properly deleted

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // check if listSize=arrayCapacity, if yes don't insert
    if (sizeList == sizeArray) 
    {
        return;
    }

    for (int i = sizeList - 1; i >= 0; i--) 
    {
        aList[i].setObjPos(aList[i - 1]); // Shifts all the elements towards the tail(each element will be the one before)
    }

    aList[0].setObjPos(thisPos); // inserting the head based on what the next current position is

    sizeList++; // incrementing the list by 1 since the head is added
}

void objPosArrayList::insertTail(objPos thisPos)
{
    // Check if listSize equals arrayCapacity; if yes, don't insert
    if (sizeList == sizeArray)
    {
        return;
    }

    // Insert the new tail position at the end, no need to shuffle elements
    aList[sizeList].setObjPos(thisPos);

    // Increment the list size since the tail is added
    sizeList++;
}

void objPosArrayList::removeHead()
{
    // If list is empty, don't remove anything
    if (sizeList == 0)
    {
        return;
    }

    // Shift elements towards the head to remove the head
    for (int i = 0; i < sizeList - 1; i++) 
    {
        aList[i].setObjPos(aList[i + 1]);
    }

    // Decrement the list size since the head is removed
    sizeList--;
}

void objPosArrayList::removeTail()
{
    // Check if the list is empty, if yes don't remove
    if (sizeList == 0) 
    {
        return;
    }
    
    sizeList--; // Decrement the list size by one which removes the tail 
}

char objPosArrayList::getHeadElement(objPos &returnPos)
{
    return aList[0].getSymbol(); //returning the symbol of head (head index on the list is 0 always)
}

char objPosArrayList::getTailElement(objPos &returnPos)
{
    return aList[sizeList - 1].getSymbol(); //returnin the tail element
}

char objPosArrayList::getElement(objPos &returnPos, int index)
{
    if (index >= 0 && index < sizeList) 
    {
        return aList[index].getSymbol(); // Return the symbol at the given index if it's in bound 
    }
    else 
    {
        return 0;
    }
}