#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#define BOTTOM 1
#define	TOP 7
using namespace std;

class Elevator
{
private:
    int curFloor;
    int direction;//1 up, 2 down
    bool pause_stat;
    vector<int> floorBox;//0 is null, 1 is up, 2 is down
    vector<bool> eleBox;
    bool externalFinished(int direc);
    bool internalFinished(int direc);
    void check0();
    void check1();
    void check2();

public:
    Elevator();
    void externalRequest(int floor, int req);
    void internalRequest(int req);
    void runStep();
    int getFloor();
    bool get_pause_stat();
    void go_on();
};

#endif // ELEVATOR_H
