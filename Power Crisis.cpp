/*
    题目简述：为了保护环境需要省电，城市街区都要轮流停电，为了能够公平起见
    假定有 N 个街区，每隔 m-1 需要停电，例如当 N = 17， m = 5时候，
    停电顺序如下：
    1,6,11,16,5,12,2,9,17,10,4,15,14,3,8,13,7.
    问从1开始13结束，最小的 m 是多少？
    这个题目是约瑟夫问题的变形。
    约瑟夫公式： f（n）= [f（n-1）+ m]%n
    f（n）得到的是，当总人数为 n，每隔 m-1 下最终能够留下的序号
    f（1）= 0，

    因为这道题起始就扣除了1，所以结束13的编号应该为11.
*/

#include<iostream>
using namespace std;

int main(){
    int N = 0;
    while(cin>>N && N){
        for(int m=1; ; m++){
            int temp=0; 
            for(int n=1; n < N; n++){
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