/*
    这题是 leetcode 的简单题
    题目很简单：假如你现在需要走楼梯，你一次可以走 1 步或者 2 步，
    输入是楼梯共有多少节台阶，输出是你有多少骚操作走完。
    比如：4 阶楼梯，你可以 
    1，1，1，1
    1，1，2
    2，1
    1，2，1
    2，2
    贴心小提示 int ~ 10^10
    long long ~ 10^19
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==0){
            cout << 0 << endl;    
        }
        else if(n==1){
            cout << 1 << endl;
        }
        else{
            long long temp[n+1];
            temp[1]=1;
            temp[2]=2;
            for(int i=3; i<= n; i++){
                temp[i] = temp[i-2]+temp[i-1];
            }
            cout << temp[n] << endl;        
        }
    }
    return 0;
}