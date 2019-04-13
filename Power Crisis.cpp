#include<iostream>
using namespace std;

int main(){
    int N = 0;
    while(cin>>N && N){
        for(int m=1; ; m++){
            int temp=0; 
            for(int n=1; n <= N-1; n++){
                temp=(temp+m)%n;
            }
            if(temp==11){
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}