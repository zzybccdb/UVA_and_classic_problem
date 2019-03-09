/*
    本题的目标就是是做 die 的四个方向的转换.
    - 需要注意的是,使用 strcmp(char a, char b)完全相等 return 0
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
void output(int number){
    cout << number << endl;
};
vector<int> west(vector<int> die){
    int temp = die[0];
    die[0] = 7 - die[2];
    die[2] = temp;
    return die;
};
vector<int> east(vector<int> die){
    int temp = die[0];
    die[0] = die[2];
    die[2] = 7 - temp;
    return die;
}
vector<int> north(vector<int> die){
    int temp = die[0];
    die[0] = 7 - die[1];
    die[1] = temp;
    return die;
}
vector<int> south(vector<int> die){
    int temp = die[0];
    die[0] = die[1];
    die[1] = 7 - temp;
    return die;
};
void printVector(vector<int> temp){
    for(int i=0; i< temp.size(); i++){
        cout << temp[i];
    }
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
        if(overturn == 0){
            return 0;
        }else{
            for(int i=0; i<overturn; i++){
                cin >> dirction;
                if(strcmp(dirction,"east") == 0){
                    die = east(die);
                }else if(strcmp(dirction,"west") == 0){
                    die = west(die);
                }else if(strcmp(dirction,"south") == 0){
                    die = south(die);
                }else if(strcmp(dirction,"north") == 0){
                    die = north(die);
                }
            }
            output(die[0]);
        }
    }
}  