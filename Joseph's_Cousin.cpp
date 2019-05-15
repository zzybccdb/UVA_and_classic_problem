/*  
    10607:Joseph's Cousin
    約瑟夫問題的變形：
    1. 首先要考虑的是 m 是一个质数的数组
    2. 因为 m 是变化的，所以对于公式来说，也就需要相对的做出改变
    3. 对于变化的 m， m 是 递推往上的。
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<int>m;
    m.push_back(2);
    for(int i=3; m.size()<3501; i+=2){
        for(int j=2; j<=i; j++){
            if(i%j==0 && j!=i){
                break;
            }
            if(j==i){
                m.push_back(i);
            }
        }
    }
    while(cin>>n && n){
        int saved = 0;
        int temp = 0 ;
        for(int i=1,j=n-2; i<n; i++,j--){
            temp = (temp+m[j])%(i+1);
        }
        cout << temp+1<< endl;
    }
}