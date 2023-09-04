#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row,column;
char turn = 'X';
bool draw = false;
string n1, n2;


void display_board(){

    //Game Board layout

    
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";
}



void player_turn(){
    if(turn == 'X'){
        cout<<n1<<" Please enter: ";
    }
    else if(turn == 'O'){
        cout<<n2<<" Please enter: ";
    }
    //Taking input from user

    cin>> choice;

    

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move"<<endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        
        board[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        
        cout<<"Box already filled. Please choose another box"<<endl;
        player_turn();
    }

    display_board();
}



bool gameover(){
    
    //checking win in rows and cols
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++) {
     for(int j=0; j<3; j++) {
      if(board[i][j] != 'X' && board[i][j] != 'O')
        return true;
     }
    } 
    //Checking the if game already draw
    draw = true;
    return true;
}



int main()
{
    //string n1,n2;
    
    cout<<"Tic Tac Toe Game"<<endl;
    cout<<"Enter the name of first player: ";
    getline(cin,n1);
    
    cout<<"Enter the name of second player: ";
    getline(cin,n2);
    
    while(gameover()){
        
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<n2<<" wins the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<n1<<" wins the game";
    }
    else
    cout<<"Its a draw";
} 
