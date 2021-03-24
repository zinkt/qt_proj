#include "elevator.h"


Elevator::Elevator()
{
    curFloor = BOTTOM;
    floorBox = {0,0,0,0,0,0,0};
    eleBox = {false,false,false,false,false,false,false};
    direction = 0;
    pause_stat = false;
}
int Elevator::getFloor(){return curFloor;}

void Elevator::externalRequest(int floor, int req)
{
    if (floor == BOTTOM && req == 2)
        return;
    else if (floor == TOP && req == 1)
        return;
    else
    {
        floorBox[floor-1] = req;
    }
}

void Elevator::internalRequest(int req){eleBox[req-1] = true;}

bool Elevator::externalFinished(int direc)
{
    if(direc == 1)
    {
        for(int i = curFloor;i<TOP;i++)
            if(floorBox[i]>0)
                return false;
    }
    else
    {
        for(int i = curFloor-2;i>=0;i--)
            if(floorBox[i]>0)
                return  false;
    }
    return true;
}
bool Elevator::internalFinished(int direc)
{
    if(direc == 1)
    {
        for(int i = curFloor;i<TOP;i++)
            if(eleBox[i])
                return false;
    }
    else
    {
        for(int i = curFloor-2;i>=0;i--)
            if(eleBox[i])
                return  false;
    }
    return true;
}

void Elevator::check0()
{
    if(curFloor == BOTTOM)
    {
        if(externalFinished(1) && internalFinished(1))
            ;
        else
            direction = 1;
    }
    else if(curFloor == TOP)
    {
        if(externalFinished(2) && internalFinished(2))
            ;
        else
            direction = 2;
    }
    else
    {
        if(!externalFinished(1) || !internalFinished(1))
            direction = 1;
        else if(!externalFinished(2) || !internalFinished(2))
            direction = 2;
    }

}
void Elevator::check1()
{
    if(externalFinished(1) && internalFinished(1))
    {
        if(externalFinished(2) && internalFinished(2))
            direction = 0;
        else
            direction = 2;
    }
}
void Elevator::check2()
{
    if(direction == 2)
    {
        if(externalFinished(2) && internalFinished(2))
        {
            if(externalFinished(1) && internalFinished(1))
                direction = 0;
            else
                direction = 1;
        }
    }
}

void Elevator::go_on(){pause_stat = false;}
bool Elevator::get_pause_stat(){return pause_stat;}

void Elevator::runStep()
{
    if(direction == 1)
    {
        curFloor++;
        if(floorBox[curFloor-1] != 0)
        {
            pause_stat = true;
            floorBox[curFloor-1] = 0;
        }
        if(eleBox[curFloor-1] == true)
        {
            pause_stat = true;
            eleBox[curFloor-1] = false;
        }
        check1();

    }
    else if(direction == 2)
    {
        curFloor--;
        if(floorBox[curFloor-1] != 0)
        {
            pause_stat = true;
            floorBox[curFloor-1] = 0;
        }
        if(eleBox[curFloor-1] == true)
        {
            pause_stat = true;
            eleBox[curFloor-1] = false;
        }
        check2();

    }
    else
    {
        check0();
    }

}
