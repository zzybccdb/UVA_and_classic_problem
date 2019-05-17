/*
    题目描述：题目给定一个字串，希望你在添加最小字元的情况下，得到该字串的回文字串
    解题思路：
        - 对于一个给定的字符串，如：        ABAAACCB -> str1
        - 首先我们需要得到它的一个反转字符串 BCCAAABA -> str2
        - 目标想让这两个子串能够变成相互回文
        - 那么可以想象到的就是以 str1 的后缀和 str2 的前缀相同部分叠加的方式，将两个字串链接
        - 这里 str1 跟 str2 的相同前后缀是 B 
        - 那么最后的结果就是 ABAAACCBCCAAABA
        - 由于题目有时间的要求，所以传统的暴力法是不可行的， 因此这里有参考到 KMP
        - KMP 的 code 在这个 repository 中也有给出了。
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string myreverse(string str1,int len){
    string str2 = str1;
    for(int i=0; i<len;i++){
        str2[i] = str1[len-i-1];
    }
    return str2;
};
// 填入 prefix table，輔助計算。
void prefix_table(string pattern,int prefix[], int n){
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n){
        if(pattern[i] == pattern[len]){
            len++;
            prefix[i] = len;
            i++;
        }
        // 遇到不相等的情況時，我們需要將len指標移動到當前指標的前綴
        else{
            if(len>0)
                len = prefix[len-1];
            else{
                len = 0;
                prefix[i] = len;
                i++;
            }
        }
    }
}
void move_prefix_table(int prefix[], int n){
    for(int i =n-1; i>0; i--){
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;

}
void KMP(string str, string pattern){
    int ls = str.length();
    int lp = pattern.length();
    
    int prefix[ls];
    prefix_table(pattern,prefix,lp);
    move_prefix_table(prefix,lp);

    int i=0, j=0;
    while(i<ls){
        // 當 j 走到最後時，滿足str[i] == pattern[j]，就找到我們要的內容
        // 但是這並不能說明我們找到了全部的相同子子串
        // 因此需要繼續探索下去，此時只需要從 prefix【j】的位置繼續即可。
        if(j == lp-1 && str[i] == pattern[j]){
            cout << str << endl;
            break;
        }
        // 如果str[i] == pattern[j]，i，j個往後移動一位
        if(str[i] == pattern[j]){
            j++;
            i++;
            // 特意爲 ecc 這種 case 加的判斷
            if(i == ls && j == lp-1){
                cout << str+pattern.substr(j,lp)<<endl;
            }
        }
        // 否則，j就調到 prefix【j】的位置
        else{
            j=prefix[j];
            if(j==-1){
                i++;
                j++;
            }
        }
    }
    if(j!=lp-1)
        cout << str+pattern.substr(j,lp)<<endl;
}

int main(){
    string str1,pattern;
    while(cin>>str1){
        int len = str1.length();
        string str2 = myreverse(str1,len);
        KMP(str1,str2);
    }
    return 0;
}