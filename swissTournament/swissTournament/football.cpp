#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include "participant.cpp"

class Football : public Participant{
    public:
    int OVR = 0;
    std::vector<unsigned short int> goals_for;
    std::vector<unsigned short int> goals_against;

    Football(std::string pName, int pOVR, float pElo) {
        name = pName;
        OVR = pOVR;
        elo = pElo;
    }
    int getGoalDifference(){
        int res = 0;
        for (auto i : goals_for) {
            res += i;
        }
        for (auto i : goals_against) {
            res -= i;
        }
        return res;
    }
    float getPoints() {
        float points = 0;
        for (unsigned short int i = 0; i < goals_for.size(); i++) {
            if (goals_for[i] > goals_against[i]) {
                points += 3;
            }else if (goals_for[i] == goals_against[i]){ points++; }
        }
        return points;
    }
    static std::vector<std::vector<Football>> getPointGroups(std::vector<Football> teams_vector) {
        std::vector<std::vector<Football>> all_groups;
        std::vector<Football> group;
        float comparator = teams_vector[0].getPoints();
        for (int i = 0; i < teams_vector.size(); i++) {
            if (teams_vector[i].getPoints() == comparator) {
            }
            else {
                if(i < teams_vector.size())comparator = teams_vector[i].getPoints();
                all_groups.push_back(group);
                group.clear();
            }
            group.push_back(teams_vector[i]);
        }
        all_groups.push_back(group);
        return all_groups;
    }
};