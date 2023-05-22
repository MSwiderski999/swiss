#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include "participant.cpp"

class Chess : public Participant{
    public:
    std::vector<Chess*> prev_op;
    std::vector<float> prev_res;

    Chess() {};

    float getPoints() {
        float points = 0;
        for (auto i : prev_res)points += i;
    }
    float calculateBuchholtz(){
        float buchholtz = 0;
        for(Chess* opponent : prev_op){
            buchholtz += opponent->getPoints();
        }
        return buchholtz * getPoints();
    }
    float calculateS_B(Chess* opponent){
        float S_B = 0;
        for(int i = 0; i < prev_op.size(); i++){
            float raw_value = opponent->getPoints();
            if(prev_res[i] == 1){
                S_B += raw_value;
            }else if(prev_res[i] == 0.5){
                S_B += 0.5 * raw_value;
            }
        }
        return S_B;
    }
};




/*template <size_t N>
std::vector<unsigned short int> getPointGroups(Chess (&pairedTable)[N]){
    std::vector<unsigned short int> new_group_coordinate;
    for(unsigned short int i: pairedTable){
        
    }
}

void pairings(Chess pairedTable[]){

}*/

