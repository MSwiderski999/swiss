#include <iostream>
#include <vector>
#include <algorithm>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class Participant{
    public:
    std::string name = "";
    std::vector < std::string > prev_op;
    bool didBye = false;
    float elo, points = 0;

    bool ableToPair(Participant* comparing_to) {
        if (std::count(prev_op.begin(), prev_op.end(), comparing_to->name)) {
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


