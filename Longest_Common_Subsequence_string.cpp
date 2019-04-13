/*
    最长子字串问题 10405 - Longest Common Subsequence
    使用 string
*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>    // std::max
#include<sstream>
using namespace std;

int main(){ 
    cin >> ws;
    string str1;
    while(getline(cin,str1)){
        stringstream ss1(str1);
        ss1 >> str1;
        string str2;
        getline(cin,str2);
        stringstream ss2(str2);
        ss2 >> str2;
        int l1=str1.length(), l2=str2.length();
        int dp[l1+1][l2+1];
        if(l1==0 || l2==0){
            cout<< 0 <<endl;
        }
        else{
            for(int i=0; i<=l1; i++){
                for(int j=0; j<=l2; j++){
                    if(i==0){
                        dp[i][j]=0;
                    }
                    else if(j==0){
                        dp[i][j]=0;
                    }
                    else if(str1[i-1]==str2[j-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else if(str1[i-1]!=str2[j-1]){
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            cout << dp[l1][l2]<<endl;
        }
    }
}