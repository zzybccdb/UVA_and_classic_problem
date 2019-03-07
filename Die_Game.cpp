/*
    本题的目标就是是做 die 的四个方向的转换.
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
void output(int number){
    // cout << "output is:";
    cout << number << endl;
};
vector<int> west(vector<int> die){
    // cout << "west" << endl;
    int temp = die[0];
    die[0] = 7 - die[2];
    die[2] = temp;
    return die;
};
vector<int> east(vector<int> die){
    // cout << "east" << endl;
    int temp = die[0];
    die[0] = die[2];
    die[2] = 7 - temp;
    return die;
}
vector<int> north(vector<int> die){
    // cout << "north" << endl;
    int temp = die[0];
    die[0] = 7 - die[1];
    die[1] = temp;
    return die;
}
vector<int> south(vector<int> die){
    // cout << "south" << endl;
    int temp = die[0];
    die[0] = die[1];
    die[1] = 7 - temp;
    return die;
};
void printVector(vector<int> temp){
    // cout << "vector is:";
    for(int i=0; i< temp.size(); i++){
        cout << temp[i];
    }
    // cout << endl ;
};
int main(){ 
    int overturn;
    char dirction[6];
    // die里面存着 top, north, west
    while(cin >> overturn){
        vector<int> die;
        die.push_back(1);
        die.push_back(2);
        die.push_back(3);
        // printVector(die);
        if(overturn == 0){
            return 0;
        }else{
            for(int i=0; i<overturn; i++){
                cin >> dirction;
                // cout << dirction;
                if(strcmp(dirction,"east") == 0){
                    die = east(die);
                    // printVector(die);
                }else if(strcmp(dirction,"west") == 0){
                    die = west(die);
                    // printVector(die);
                }else if(strcmp(dirction,"south") == 0){
                    die = south(die);
                    // printVector(die);
                }else if(strcmp(dirction,"north") == 0){
                    die = north(die);
                    // printVector(die);
                }
            }
            output(die[0]);
        }
    }
}  