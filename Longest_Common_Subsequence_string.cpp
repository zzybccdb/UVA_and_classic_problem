/*
    最长子字串问题 10405 - Longest Common Subsequence
    使用 string
    題目大意：從給定的兩個字串中找出它們中最大的公共子子串的長度。
    解答思考：利用dp的方法解答，建立2維的dp表。
    首先對於長度爲i，j的兩個子子串，我們會有一個dp【i+1】【j+1】的array
    如果str1【i】 == str2【j】，那麼dp【i】【j】 = dp【i-1】【j-1】
    如果str1【i】！= str2【j】，那麼dp【i】【j】 = max（dp【i-1】【j】，dp【i】【j-1】）
*/ 
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main(){
    string str1,str2;
    cin >> ws;
    // while(getline(cin,str1,'分隔符')){
    while(getline(cin,str1)){
        cin>>ws;
        getline(cin,str2);
        int size1 = str1.length(), size2 = str2.length();
        if(size1 == 0 || size2 == 0)
            return 0;
        int dp[size1+1][size2+1];
        for(int i=0; i <= size1; i++){
            for(int j=0; j<= size2; j++){
                if(i==0){
                    dp[i][j] = 0;
                }
                else if(j==0){
                    dp[i][j] = 0;
                }
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout << dp[size1][size2] << endl;
    }
}