/*
    题目可以简化为，给定一串数组，数组和为 s，
    s 是否可以被数组中的某几个数字组合而成。
    这里使用 dp 的思想，在处理 dp 问题的时候，
    首先要研究的是如何思考递归的问题， 但是由于 递归的时间复杂度是O（2^n）,
    因此我们需要做的是，利用 dp arr 存储过程中计算的值，简化时间复杂度。
*/
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    int lines = 0;
    while(cin>>lines){
        while(lines--){
            string str;
            // 输入空白符号,防止空白符干扰
            cin >> ws;
            vector<int> luggage;
            getline(cin,str);
            stringstream ss(str);
            int item,sum =0;
            while(ss>>item){
                sum += item;
                luggage.push_back(item);
            }
            int r = sum%2,target = sum/2;
            if(r!=0)
                cout << "NO"<<endl;
            else{
                int items = luggage.size();
                int arr[items+1][target+1];
                for(int item=0; item<=items; item++){
                    for(int value=0; value<=target;value++){
                        if(item==0){
                            arr[item][value]=0;
                        }
                        if(item==1){
                            arr[item][value]=(value == luggage[item-1])?1:0;
                        }
                        if(value==0){
                            arr[item][value]=1;
                        }else{
                            arr[item][value] = (arr[item-1][value]==1 || arr[item-1][value-luggage[item-1]]==1)?1:0;
                        }
                    }
                }
                if(arr[items][target]==1)
                    cout << "YES" << endl;
                else
                    cout << "NO"<<endl;
            }
        }
    }
}
