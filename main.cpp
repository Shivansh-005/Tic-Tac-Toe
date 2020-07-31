//
//  main.cpp
//  TicTacToe
//  Copyright © 2020 Shivansh. All rights reserved.
//
#include <bits/stdc++.h>
int turns=0;
using namespace std;
char player,pc;
char winner='n';
bool over=false;
char matrix[3][3]={'0','1','2','3','4','5','6','7','8'};
void drawBoard(){
    cout<<"\n";
    cout<<"\t\t\t\t\t\t";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
        cout<<"\t\t\t\t\t\t";
    }
    cout<<"\n";
}
void pcTurn(){
    int nPC,row,column;
    nPC=abs(rand()%9);
    row=nPC/3;
    column=nPC%3;
    if(matrix[row][column]=='O' || matrix[row][column]=='X')
        pcTurn();
    else
    {
        matrix[row][column]=pc;
        cout<<"CPU entered "<<pc<<" at "<<nPC<<"\n";
        return;
    }
}
void checkRow(){
    for(int i=0;i<3;i++){
        if(matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2]){
            over=true;
        matrix[i][0]==pc?winner=pc:winner=player;
        }
    }
}
void checkColumn(){
    for(int i=0;i<3;i++){
         if(matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i]){
             over=true;
            matrix[0][i]==pc?winner=pc:winner=player;
        }
    }
}
void checkDiagonal(){
        if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2]){
         {
             over=true;
             matrix[0][0]==pc?winner=pc:winner=player;
         }
       if(matrix[0][2]==matrix[1][1] && matrix[2][0]==matrix[1][1])
       {
           over=true;
           matrix[0][2]==pc?winner=pc:winner=player;
            return;
       }
    
}
}
void checkwin(){
    checkRow();
    checkColumn();
    checkDiagonal();
}
void play(){
    cout<<"Your turn, enter a number "<<"\n";
    int n;
    cin>>n;
    int row;
    int column;
    row=n/3;
    column=n%3;
     while(n<0 || n>8 || matrix[row][column]=='O' || matrix[row][column]=='X')
      {
            cout<<"Please enter a valid choice!\n";
            cin>>n;
            row=n/3;
            column=n%3;
          cin.get();
      }
    if(turns<9)
    matrix[row][column]=player;
    drawBoard();
    checkwin();
    turns++;
    if(turns<9)
    {
        cout<<"CPU's turn, please wait...\n";
        pcTurn();
        checkwin();
        drawBoard();
        turns++;
    }
    if(turns>=9)
    {
        over=true;
        return;
    }
}
int main(){
    cout<<"Welcome to the Game"<<"\n";
    cout<<"Choose 'X' or 'O' by entering 1 or 2 respectively"<<"\n";
    int choice;
    cin>>choice;
    if(choice<1 || choice>2)
        cout<<"Please enter a valid choice!";
    choice==1?player='X':player='O';
    player=='X'?pc='O':pc='X';
    while (!over) {
        drawBoard();
        play();
    }
    if(winner==pc)
     cout<<"CPU"<<" Won!\n";
    else if(winner==player)
     cout<<"You"<<" Won!\n";
    else
        cout<<"It's a draw!\n";
}
