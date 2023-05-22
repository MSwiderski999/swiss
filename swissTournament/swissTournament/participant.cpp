#include <iostream>
#include <vector>
#include <algorithm>

class Participant{
    public:
    std::string name = "";
    std::vector<Participant*> prev_op;
    bool didBye = false;
    short int seeking = 0;
    float elo;

    bool ableToPair(Participant* comparing_to) {
        if (std::count(prev_op.begin(), prev_op.end(), comparing_to)) {
            return false;
        }
        return true;
    }
    /*float calculatePoints() {
        float points = 0;
        for(float i : prev_res){
            points += i;
        }
        return points;
    }
    
    unsigned short int numOfWins(){
        unsigned short int wins = 0;
        for(float i : prev_res){
            if(i == 1)wins++;
        }
        return wins;
    }

    bool canBye(){
        if(didBye)return false;
        return true;
    }

    */
};


