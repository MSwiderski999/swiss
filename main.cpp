#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>

class Chess{
    public:
    std::string name = "";
    float ELO = 0;
    std::vector<float> prev_res;
    std::vector<Chess*> prev_op;

    Chess(){};

    void setName(std::string p_Name){
        name = p_Name;
    }
    void setELO(float p_ELO){
        ELO = p_ELO;
    }
    float calculatePoints(){
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
    float calcBuchholtz(){
        float buchholtz = 0;
        for(Chess* opponent : prev_op){
            buchholtz += opponent->calculatePoints();
        }
        return buchholtz * calculatePoints();
    }
    float calcS_B(Chess* opponent){
        float S_B = 0;
        for(int i = 0; i < prev_op.size(); i++){
            float raw_value = opponent->calculatePoints();
            if(prev_res[i] == 1){
                S_B += raw_value;
            }else if(prev_res[i] == 0.5){
                S_B += 0.5 * raw_value;
            }
        }
        return S_B;
    }
    bool ableToPair(Chess* comparing_to){
        if(std::count(prev_op.begin(), prev_op.end(), comparing_to)){
            return false;
        }
        return true;
    }
    bool canBye(Chess &checked){
        for(Chess* opp : prev_op){
            if(opp == &checked)return false;
        }
        return true;
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

int main(){
    //preparation
    setlocale(LC_CTYPE, "Polish");
    std::cout << "Set number of rounds:\n";
    unsigned short int numOfRounds;
    std::cin >> numOfRounds;
    unsigned short int round = 1;

    Chess players[29];
    players[0].setName("Banaś");
    players[1].setName("Dawid");
    players[2].setName("Bilski");
    players[3].setName("Duch");
    players[4].setName("Marcin");
    players[5].setName("Gogola");
    players[6].setName("Halke");
    players[7].setName("Tosiek");
    players[8].setName("Jezioro");
    players[9].setName("Konrad");
    players[10].setName("Fiziu");
    players[11].setName("Kolaj");
    players[12].setName("Szymon");
    players[13].setName("Akkra");
    players[14].setName("Michu");
    players[15].setName("Czompik");
    players[16].setName("Patryk");
    players[17].setName("Mikosz");
    players[18].setName("Maja");
    players[19].setName("Piątek");
    players[20].setName("Natalia");
    players[21].setName("Płonka");
    players[22].setName("Mati");
    players[23].setName("Ruszczka");
    players[24].setName("Świder");
    players[25].setName("Święcioch");
    players[26].setName("Rudi");
    players[27].setName("Wózek");
    players[28].setName("Rabenda");

    Chess bye;
    bye.setName("bye");
    int size = sizeof(players)/sizeof(players[0]);
    bool byeNeeded = size % 2 == 1;
    std::vector<Chess*>pairings;

    //main loop
    for(int i = 1; i <= numOfRounds; i++){
        //pairing
        
        //select bye
        if(byeNeeded){
            pairings.insert(pairings.begin(), &bye);
            for(int j = size - 1; j >= 0; j--){
                if(players[j].canBye(bye)){
                    std::cout<<players[j].name;
                    pairings.insert(pairings.begin(), &players[j]);
                    players[j].prev_op.push_back(&bye);
                    break;
                }
            }
        }
        std::cout<<pairings[0]->name<<"\n";
        pairings.clear();
    }
}