/*
    本题的关键点在于如何 filter 出字符串中特定的字符内容;
    - 本题所使用的技巧是引用 <string.h> 中的 strchr api
    - char* it;
    - it = strchr(str,'需要寻找的内容');
    - index = it-str;
    - 从头找到尾巴
    - while(it!=NULL){
        it = strchr(str,'需要寻找的内容');
    }
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
int field = 1;
void output(vector<vector<int> > temp){
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[i].size(); j++){
            if(temp[i][j] == -1){
                cout << '*';
            }else{
                cout << temp[i][j];
            }
        }
        cout<<endl;
    }
};
vector<vector<int> > create(vector<vector<int> >temp,int rows,int columns){
    for(int i=0; i<rows; i++){
        vector<int> row;
        for(int j=0; j<columns; j++){
            row.push_back(0);
        }
        temp.push_back(row);
    }
    return temp;
};
vector<vector<int> > adjust(vector<vector<int> >temp,int row,int column,int rows, int columns){
    for(int i=row-1; i<=row+1 ; i++){
        for(int j=column-1; j<=column+1; j++){
            if((i>=0 && j>=0) && (i<rows && j<columns)){
                if(i==row&&j==column){
                    temp[i][j] = -1;
                }else{
                    if(temp[i][j]!=-1){
                        temp[i][j]++;
                    }
                }
            }
        }
    }
    return temp;
};
int main(){
    int rows, columns;
    while(cin>>rows>>columns){
        if(rows==0 && columns==0){
            return 0;
        }
        if(field!=1){
            cout << endl;
        }
        cout << "Field #" << field++ << ":"<<endl;
        vector<vector<int> > matrix;
        matrix = create(matrix,rows,columns);
        for(int row=0; row<rows; row++){
            char sign[columns];
            char* star;
            int miner;
            cin >> sign;
            star = strchr(sign,'*');
            miner = star-sign;
            if(miner<columns){
                matrix = adjust(matrix,row,miner,rows,columns);
            }
            while(star!=NULL){
                star = strchr(star+1,'*');
                miner = star-sign;
                if(miner < columns){
                    matrix = adjust(matrix,row,miner,rows,columns);
                }
            }

        }
        output(matrix);
    }
}