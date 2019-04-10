/*
    题目可以简化为，给定一串数组，数组和为 s，
    s 是否可以被数组中的某几个数字组合而成。
    这里使用 dp 的思想，在处理 dp 问题的时候，
    首先要研究的是如何思考递归的问题， 但是由于 递归的时间复杂度是O（2^n）,
    因此我们需要做的是，利用 dp arr 存储过程中计算的值，简化时间复杂度。
*/
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int lines;
    while(cin>>lines){
        while(lines--){
            string str;
            // 读取空白符，防止空白符的干扰
            cin >> ws;
            getline(cin,str);
            // 将上一行 getline 的内容再一次转为 I/O
            stringstream ss(str);
            int item, sum=0;
            vector<int>arr;
            while(ss >> item){
                arr.push_back(item);
                sum += item;    
            }
            // 保证能够整除2
            if(sum%2){
                cout << "NO" << endl;
            }else{
                sum /= 2;
                int size = arr.size();
                int dp[size][sum+1];
                for(int i=0; i<size; i++){
                    for(int s=0; s<= sum; s++){
                        if(i==0){
                            dp[i][s] = (s==arr[i])? 1:0;
                        }
                        else if(s==0){
                            dp[i][s] = 1;
                        }
                        else {
                            int a = dp[i-1][s-arr[i]];
                            // 需要判断是否有超出边界的问题
                            if((s-arr[i]) < 0){
                                a = 0;
                            }
                            int b = dp[i-1][s];
                            // || 是 or , | 是 bits 的 or（01，10->11）
                            dp[i][s] = a || b;
                        }
                    }
                }
                if(dp[size-1][sum]){
                    cout << "YES"<<endl;
                }
                else{
                    cout << "NO"<<endl;
                }
            }
        }
    }
    return 0;
}