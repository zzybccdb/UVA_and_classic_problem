/*
    这个题目就是一个求最长字字串长度的问题.这个 repository 中还会包含其他类似的题目.
    这里我们使用 DP 的方式来解决这个问题.
    需要特别注意的一点事是使用 char 的时候系统会自动补上结束符 \0
    因此在比较的时候如果没有注意的话会比较到 \0
    在使用 strlen 的时候并不会计算到 \0
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include <algorithm>    // std::max
using namespace std;
void output(vector<vector<int> >temp){
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[i].size(); j++){
            cout<<temp[i][j];
        }
        cout<<endl;
    }
}
int LCS(char* l1, char* l2){
    int l1l=strlen(l1),l2l=strlen(l2);
    vector<vector<int> > DP;
    for(int i=0; i<=l1l; i++){
        vector<int> temp;
        for(int j=0; j<=l2l; j++){
            temp.push_back(0);
        }
        DP.push_back(temp);
    }

    for(int i=0; i<l1l; i++){
        for(int j=0; j<l2l; j++){
            if(l1[i]==l2[j] && l1[i]!='\0'){
                DP[i+1][j+1] = DP[i+1-1][j+1-1]+1;
            }else{
                DP[i+1][j+1] = max(DP[i-1+1][j+1],DP[i+1][j-1+1]);
            }
        }
    }
    return DP[l1l][l2l];
};
int main(){
    char l1[1001],l2[1001];   
    int answer;
    while(cin>>l1){
        cin>>l2;
        if(strlen(l1)==0 && strlen(l2)==0){
            return 0;
        }else{
            cout<<LCS(l1,l2)<<endl;
        }
    }
    return 0;
}