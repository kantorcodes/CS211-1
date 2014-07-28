#include <iostream>
#include <vector>
using namespace std;

void find_candidate(vector<int> *towers, int* previous_ring, int* candidate, int* ctower){
    //Find candidate; towers[j].back() is an available ring
    for(int j=0; j<3; j++){
        if(!towers[j].empty()){
            if(towers[j].back()!=*previous_ring && towers[j].back()<*candidate){
                *candidate = towers[j].back();
                *ctower = j;
                cout << *candidate;
                break;
            }
        }
    }
}

void solve(int rings){
    int previous_ring = -1, candidate = 2, ctower = 0, i, j;
    vector<int> a, b, c;
    vector<int> towers[3] = {a, b, c};

    //Populate tower a
    for(i=rings; i>0; i--) towers[0].push_back(i);

    //find_candidate(towers, &previous_ring, &candidate, &ctower);
    for(j=0; j<3; j++){
        if(!towers[j].empty()){
            if(towers[j].back()!=previous_ring && towers[j].back()<candidate){
                candidate = towers[j].back();
                ctower = j;
                cout << candidate;
                break;
            }
        }
    }

    //Move candidate
    //Even number of rings; move left
    if(rings%2==0){
        towers[ctower].pop_back();
        if(towers[(ctower+1)%3].back()>candidate) towers[(ctower+1)%3].push_back(candidate);
        else if(towers[(ctower+2)%3].back()>candidate) towers[(ctower+2)%3].push_back(candidate);
        else{
            for(j=0; j<3; j++){
                if(!towers[j].empty()){
                    if(towers[j].back()!=previous_ring && towers[j].back()<candidate){
                        candidate = towers[j].back();
                        ctower = j;
                        cout << candidate;
                        break;
                    }
                }
            }
        }
    }

    //Odd number of rings; move right
    else{

    }
''
}

int main(){
    solve(10);
    return 0;
}
