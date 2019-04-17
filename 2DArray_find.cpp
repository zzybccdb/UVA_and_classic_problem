/*
    经典算法例题。
    2維數組查：限制条件为左到右递增，上到下递增。
    两种方法可以解答，分别为
    1.利用限制条件，从左下角或者右上角开始遍历 array，找出需要的解。
    2.利用二分法处理。
*/
#include<iostream>
#include<vector>
using namespace std;
bool Find(int target, vector<vector<int> > array) {
    int r = array.size()-1;
    int c = 0; 
    int cols = array[0].size()-1;
    //这道题由于没有考虑到，array 是空的状况。
    while(r>=0 && c <= cols){
        if(target > array[r][c]){
            c++; //如果数字比当前数字大，只有可能在该数字的右边。
        }
        else if(target < array[r][c]){
            r--; //如果数字比当前数字小，只有可能在该数字的上方。
        }
        else{
            return true;
        }
    }
    return false;
}
bool Find2(int target, vector<vector<int> > array) {
    int r = array.size()-1;
    int c = array[0].size()-1;
    for(int i=0; i<=r; i++){
        int left=0;
        int right=c;
        while(left<=right){
            int mid = (left+right)/2;
            if(target > array[i][mid]){
                left = mid+1; //如果数字比当前数字大，只有可能在该数字的右边
            }
            else if(target < array[i][mid]){
                right = mid-1; //如果数字比当前数字小，只有可能在该数字的上方。
            }
            else{
                return true;
            }            
        }
    }
    return false;
}
int main(){
    int r=5, c=3;
    vector<vector<int> > array;
    for(int i=0; i<r; i++){
        vector<int>temp_arr;
        for(int j=0; j<c; j++){
            temp_arr.push_back(i+j);
        }
        array.push_back(temp_arr);
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << array[i][j] << ",";
        }
        cout << endl;
    }
    if(Find3(100,array)){
        cout << "find" <<endl;
    }
    else{
        cout << "no find" << endl;
    }
}