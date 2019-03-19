/*
    该题目的思路是 BFS, 需要使用到 queue
    值得注意的一些小技巧:
    * 我们可以简单的通过 layers+rows+cols == 0 来判断 3者是否同时为0
    * 另外 struct 的建构子在新版本中可以直接写 
    * struct A {
    *   int a;
    *   int b;
    * }
    * A{1,2};
    * 想要直接传递共同的位置,可以直接使用 &
    * 特别强调,每一次将点放入 queue 中的时候,就需要标记它,以免其再一次的进入 queue 中g
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;
int layers,rows,cols;
struct Nodes{
    int layer;
    int row; 
    int col;
    int step;
    bool walk;
    Nodes(int l=0, int r=0, int c=0, int S=0, bool W=false){
        layer = l;
        row = r;
        col = c;
        walk = W, step = S;
    };
};
void output(Nodes node){
    cout << node.layer << "," << node.row <<"," << node.col << endl;
    cout << "Step" << node.step <<endl;
};
void check(char point, queue<Nodes>& path, Nodes& End, int l, int r, int c, int step){
    if(point=='.'){
        path.push(Nodes(l,r,c,++step,false));
    }else if(point=='E'){
        End.walk = true;
        End.step = step+1;
    }     
}
int main(){
    while(cin>>layers>>rows>>cols && layers+rows+cols){
        queue<Nodes>path;
        char Map[layers+1][rows+1][cols+1];
        // 记录起终点
        Nodes Start,End;
        if(layers==0 && rows==0 && cols==0){
            return 0;
        }
        for(int layer=0; layer<layers; layer++){
            for(int row=0; row<rows; row++){
                cin >>Map[layer][row];
                for(int col=0; col<cols; col++){
                    if(Map[layer][row][col]=='S'){
                        Start = Nodes(layer,row,col,0,false);
                        path.push(Start);
                        Map[layer][row][col] = '#';
                    }     
                    if(Map[layer][row][col]=='E'){
                        End = Nodes(layer,row,col,0,false);
                    }         
                }
            }
        }
        while(!path.empty() && End.walk==false){
            Nodes cur = path.front(); 
            path.pop();
            int l=cur.layer, r=cur.row, c=cur.col;
            if(l-1>=0 && l-1<layers){
                check(Map[l-1][r][c],path,End,l-1,r,c,cur.step);
                Map[l-1][r][c] = '#';
            }
            if(l+1>=0 && l+1<layers){
                check(Map[l+1][r][c],path,End,l+1,r,c,cur.step);
                Map[l+1][r][c] = '#';            
            }
            if(r-1>=0 && r-1<rows){
                check(Map[l][r-1][c],path,End,l,r-1,c,cur.step);
                Map[l][r-1][c] = '#'; 
            }
            if(r+1 >=0 && r+1<rows){
                check(Map[l][r+1][c],path,End,l,r+1,c,cur.step); 
                Map[l][r+1][c] = '#';              
            }
            if(c-1 >=0 && c-1<cols){
                check(Map[l][r][c-1],path,End,l,r,c-1,cur.step);
                Map[l][r][c-1] = '#'; 
            }
            if(c+1 >=0 && c+1<cols){
                check(Map[l][r][c+1],path,End,l,r,c+1,cur.step);        
                Map[l][r][c+1] = '#';         
            }
        };
        if(End.walk==false){
            cout << "Trapped!" << endl;
        }else{
            cout<< "Escaped in " << End.step << " minute(s)." << endl;
        }
    }
}