#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include "participant.cpp"

class Football : public Participant{
    public:
    int OVR = 0;
    int goal_difference = 0;

    Football(std::string pName, int pOVR, float pElo) {
        name = pName;
        OVR = pOVR;
        elo = pElo;
    }

    float updatePoints(int goals_for, int goals_against) {
        if (goals_for > goals_against)points += 3;
        else if (goals_for == goals_against)points++;
        goal_difference += (goals_for - goals_against);
    }

    static std::vector<std::vector<Football>> getPairings(std::vector<Football> teams_vector, bool odd) {
        //declaration of necessary vectors
        std::vector<std::vector<Football>> all_groups;
        std::vector<Football> group, pairings;

        //eliminating the bye team
        if (odd) {
            for (int i = teams_vector.size() - 1; i >= 0; i--) {
                if (!teams_vector[i].didBye) {
                    teams_vector[i].didBye = true;
                    Football bye_team = teams_vector[i];
                    teams_vector.erase(teams_vector.begin() + i);
                }
            }
        }

        //splitting teams into point tiers
        float comparator = teams_vector[0].points;
        for (int i = 0; i < teams_vector.size(); i++) {
            if (teams_vector[i].points == comparator) {
            }
            else {
                if (i < teams_vector.size())comparator = teams_vector[i].points;
                all_groups.push_back(group);
                group.clear();
            }
            group.push_back(teams_vector[i]);
        }
        all_groups.push_back(group);

        //pairing
        for (auto i : all_groups) {//iterate through each group tier
            for (int j = 0; j < i.size(); j++) {//iterate through each team

            }
        }
    }
};