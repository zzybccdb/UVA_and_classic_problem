#include <iostream>
using namespace std;
int lengthCircle(long long int);
int main(int argc, const char * argv[]) {
    // insert code here...
    long long int a, b, k, max, temp;
    int x, y;
    while(cin>>x>>y){
        a = x;b = y;
        max = 0;
        if( a > b ){
            temp = a ;
            a = b ;
            b = temp ;
        }
        for(int i = a; i <= b; i++){
            k = lengthCircle(i);
            if( max < k ){
                max = k;
            }
        }
        cout << x << " " << y << " " << max << endl;
    }


    return 0;
}

int lengthCircle(long long int num){
    int what=1;
    while(num != 1){
        if(num%2){
            num = num * 3 + 1;
        }
        else{
            num = num / 2;
        }
        what++;
    }
    return what;
}



