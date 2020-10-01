//
//  main.cpp
//  TicTacToe
//  Copyright © 2020 Shivansh. All rights reserved.
//
#include <bits/stdc++.h>
int turns=0;
int mode;
using namespace std;
char player,pc;
char winner='n';
bool over=false;
char matrix[3][3]={'0','1','2','3','4','5','6','7','8'}; //create 3X3 matrix for tic tac toe board
void drawBoard(){
    cout<<"\n";
    cout<<"\t\t\t\t\t\t";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<matrix[i][j]<<" "; //iteration for drawing the board after every move
        cout<<"\n";
        cout<<"\t\t\t\t\t\t";
    }
    cout<<"\n";
}
void pcTurn(){
    int nPC,row,column;
    nPC=abs(rand()%9); // CPU's random input for the position of marking O or X
    row=nPC/3;
    column=nPC%3;
    if(matrix[row][column]=='O' || matrix[row][column]=='X') //if the location already has O or X, repeat the function
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
        matrix[i][0]==pc?winner=pc:winner=player; //condition to decide the winner in a row
        }
    }
}
void checkColumn(){
    for(int i=0;i<3;i++){
         if(matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i]){
             over=true;
            matrix[0][i]==pc?winner=pc:winner=player; //condition to decide winner in a column
        }
    }
}
void checkDiagonal(){
        if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
         {
             over=true;
             matrix[0][0]==pc?winner=pc:winner=player; //condition to decide winner in left diagonal
         }
       else if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
       {
           over=true;
           matrix[0][2]==pc?winner=pc:winner=player; //condition to decide winner in right diagonal
            return;
       }

}
void checkwin(){
    checkRow();
    checkColumn();
    checkDiagonal();
}
void play(){
if(mode)
   {
    cout<<"Your turn, enter a number "<<"\n";
    int n;
    cin>>n;  // User's input for the position 
    int row;
    int column;
    row=n/3;
    column=n%3;
     while(n<0 || n>8 || matrix[row][column]=='O' || matrix[row][column]=='X') //Exception for invalid input
      {
            cout<<"Please enter a valid choice!\n";
            cin>>n;
            row=n/3;
            column=n%3;
          cin.get();
      }
       
    if(turns<9)
    {
       matrix[row][column]=player;
        turns++;
    }
       drawBoard();
       checkwin();
    if(turns<9 && !over)
    {
        cout<<"CPU's turn, please wait...\n";
        pcTurn();
        checkwin();
        turns++;
    }
    if(turns>=9)
    {
        over=true;
        return;
    }
   }
else
    {
        cout<<"Player 1's turn, please enter a choice\n";
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
           {
              matrix[row][column]=player;
               turns++;
          }
        checkwin();
        drawBoard();
       if(turns<9 && !over)
       {
           cout<<"Player 2's turn, enter a choice\n";
           int n2;
           cin>>n2;
           row=n2/3;
        column=n2%3;
        while(n2<0 || n2>8 || matrix[row][column]=='O' || matrix[row][column]=='X')
          {
                cout<<"Please enter a valid choice!\n";
                cin>>n;
                row=n2/3;
                column=n2%3;
                cin.get();
          }
            matrix[row][column]=pc;
            turns++;
            checkwin();
       }
        if(turns>=9)
        {
            over=true;
            return;
        }
    }
}
int main(){
    cout<<"Welcome to the Game"<<"\n";
    cout<<"Choose Multiplayer or CPU by entering 0 or 1\n";
    cin>>mode;
    while(mode<0 || mode>1)
    {
        cout<<"Please enter a valid choice!\n";
        cin>>mode;
        cin.get();
    }
    if(!mode)
        cout<<"Player 1:Choose 'X' or 'O' by entering 1 or 2 respectively"<<"\n";
    else
        cout<<"Choose 'X' or 'O' by entering 1 or 2 respectively\n";
    int choice;
    cin>>choice;
    while(choice<1 || choice>2)
       {
           cout<<"Please enter a valid choice!\n";
           cin>>choice;
           cin.get();
       }
    choice==1?player='X':player='O';
    player=='X'?pc='O':pc='X';
    while (!over) {
        drawBoard();
        play();
    }
    if(winner==pc && mode)
     cout<<"CPU"<<" Won!\n";
    else if(winner==player && mode)
     cout<<"You"<<" Won!\n";
    else if (winner==player && !mode)
     cout<<"Player 1"<<" Won!\n";
    else if(winner==pc && !mode)
     cout<<"Player 2"<<" Won!\n";
    else
     cout<<"It's a draw!\n";
}
