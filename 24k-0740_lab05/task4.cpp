#include<iostream>
using namespace std;


void print(char board[4][4],int n){
     cout<<"Positions of Queen"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool safe(int n,char board[4][4],int row,int col){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int j=0;j<col;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void Nqueens(int n,char board[4][4],int row){
    if(row==n){
        print(board,n);
        return;
    }

    for(int col=0;col<n;col++){
        if(safe(n,board,row,col)){
            board[row][col]='Q';
            Nqueens(n,board,row+1);
            board[row][col]='.';
        }
    }
}



int main(){
    const int n=4;
    char board[n][n]={{'.','.','.','.'},
                      {'.','.','.','.'},
                      {'.','.','.','.'},
                      {'.','.','.','.'},
                    };
    Nqueens(n,board,0);
}