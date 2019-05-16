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
            cout << "Found pattern at" << i-j << endl;
            i++;
            j = prefix[j];
        }
        // 如果str[i] == pattern[j]，i，j個往後移動一位
        if(str[i] == pattern[j]){
            i++;
            j++;
        }
        // 否則，j就調到 prefix【j】的位置。
        else{
            j=prefix[j];
            if(j==-1){
                i++;
                j++;
            }
        }
    }

    for(int i=0; i<lp; i++)
        cout << prefix[i] << ",";
    cout << endl;
}

int main(){
    string str1,pattern;
    while(cin>>str1){
        int len = str1.length();
        // string str2 = myreverse(str1,len);
        string str2 = "ababcabaa";
        KMP(str1,str2);
    }
    return 0;
}