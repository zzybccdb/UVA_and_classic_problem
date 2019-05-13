/*
    UVa 10193 - All You Need Is Love
    题目大意就是给两个2进制的数字，问你他们是否有公约数。
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;
int binary2int(string str){
    int endidx = str.size()-1;
    int num = 0;
    for(int i=0; i<=endidx; i++){
        if(str[i] == '1'){
            num += pow(2,endidx-i);
        }
    }
    return num;
}
//辗转相除法
bool gcd(int n1, int n2){
    while(n2!=0){
        int temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    if(n1!=1 && n2==0){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n = 0 ;
    while(cin>>n){
        int step = 1;
        while(n--){
            string s1, s2;
            cin >> s1 >> s2;

            int num1,num2;
            bool love = false;
            num1 = binary2int(s1);
            num2 = binary2int(s2);
            //gcd求解最大公约数
            if(num1>num2)
                love = gcd(num1,num2);
            else
                love = gcd(num2,num1);
            if(love){
                cout << "Pair #" << step << ": All you need is love!" << endl;
            }else{
                cout << "Pair #" << step << ": Love is not all you need!" << endl;
            }
            step++;
        }
    }
    return 0;
}
