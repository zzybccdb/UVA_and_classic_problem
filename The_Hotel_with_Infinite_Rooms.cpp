/*废题
    10417:The Hotel with Infinite Rooms
    觉得这题的唯一核心考点就是 input 的范围是在 10^15次方，因此需要使用到 long long int
    并且 S 需要使用到 long int
*/
#include<iostream>
using namespace std;

int main(){
    long long int n=0;
    long int d=0;
    while(cin>>d>>n){
        while(n>0){
            n -= d;
            if(n>0){
                d++;
            }
        }
        cout << d << endl;
    }
}