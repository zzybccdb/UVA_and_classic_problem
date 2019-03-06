/*
    题目的意思大致上可以理解为:将数列排列到从小到大的顺序,要求是只能两两交换.求得最小的交换次数.
    *题目的解题想法是得到一个数列,比对中间两个数字大小.不符合条件就进行交换
    *将数列分成左右两组,递归做上一步
    *将左右两组数列合并,再一次递归做第二步骤
    *得到排序好的数列.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int answer=0;
void output(){
    cout << "Optimal train swapping takes " << answer << " swaps." << endl;
};
void swap(vector<int>::iterator a,vector<int>::iterator b){   
    int temp = *b;
    *b = *a;
    *a = temp;
};
void printVector(vector<int>temp){
    int size = temp.size();
    for(int i=0; i<size; i++){
        cout << temp[i];
    }
    cout << endl;
};
vector<int> sort(vector<int>temp){
    int total = temp.size();
    if(total == 1){
        return temp;
    }
    int l = temp[total/2-1];
    int r = temp[total/2];
    if(l>r){
        swap(temp[total/2-1],temp[total/2]);
        answer++;
        // cout << "answer" << answer << endl;
        // printVector(temp);
    };
    vector<int> left = vector<int>(temp.begin(),temp.begin()+total/2);
    left = sort(left);
    vector<int> right = vector<int>(temp.begin()+total/2,temp.end());
    right = sort(right);
    vector<int> newtemp;
    newtemp.insert(newtemp.end(),left.begin(),left.end());
    newtemp.insert(newtemp.end(),right.begin(),right.end());
    l = newtemp[total/2-1];
    r = newtemp[total/2];
    if(l>r){
        newtemp = sort(newtemp);
    }

    return newtemp;
};
int main(){ 
    int num_case,num_box;
    // 注释的代码写的是 vector 互换的功能测试
    // temp.push_back(1);
    // temp.push_back(2);
    // printVector(temp);
    // swap(temp[0],temp[1]);
    // printVector(temp);
    //test
    // vector<int> a,b;
    // a.push_back(1);
    // a.push_back(2);
    // b.push_back(3);
    // b.push_back(4);
    // b = a;
    // printVector(b);
    cin >> num_case;
    while(cin>>num_box){
        vector<int>temp;
        answer = 0 ;
        int index;
        for(int i=0; i<num_box; i++){
            cin >> index;
            temp.push_back(index);
        }  
        if(!temp.empty()){
            // printVector(temp);
            temp = sort(temp); 
            // printVector(temp);
        }
        output();
    }
}