#include<iostream>
#include<vector>
#include<stdlib.h>
#include <algorithm>
using namespace std;
void printVector(vector<int> temp){
    for(int i=0; i<temp.size();i++){
        cout << temp[i];
    }
    cout << endl;
};
void Jolly(){
    cout << "Jolly" << endl;
};
void NotJolly(){
    cout << "Not jolly" << endl;
};
int main(){
    int n = 0;
    while(cin>>n){
        int a,length=0;
        bool jolly=true;
        vector<int>temp;
        vector<int>diff;
        if(n==0){
            jolly=false;
        }
        for(int i = 0; i < n; i++){
            cin >> a ;
            temp.push_back(a);
        }
        length = temp.size();
        for(int i = 0; i < length-1; i++){
            int dis = abs(temp[i+1]-temp[i]);
            if(dis>length-1 || dis==0){
                jolly = false;
                break;
            }
            vector<int>::iterator it = find(diff.begin(),diff.end(),dis);
            if(it != diff.end()){
                jolly = false;
                break;
            }else{
                diff.push_back(dis);
            }
        }
        if(jolly){
            Jolly();
        }else{
            NotJolly();
        }
    }
}
