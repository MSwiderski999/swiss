#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include "participant.cpp"

enum pref{left2, left1, right2, right1};

class Football : public Participant{
    public:
    float OVR = 0;
    unsigned int goals_scored = 0;
    unsigned int goals_lost = 0;
    pref seeking;

    int getGoalDifference(){
        return goals_scored - goals_lost;
    }
};

std::vector<Football> pair(std::vector<Football> table){
    std::vector<int> pointGroups;
    int groupSize = 1;
    int currPointGroup;
    for(Football i : table){
        
    }
}
int main(){
    std::setlocale(LC_ALL, "pl.utf-8");
    std::cout << "Set number of rounds:\n";
    
    unsigned short int numOfRounds;
    std::cin >> numOfRounds;
    unsigned short int round = 1;


}