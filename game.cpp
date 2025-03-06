#include <iostream>
#include <stdlib.h>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

// Argument: Game state. Returns: 0 if no wins found, 1 if P1 win found, 2 if P2 win found
int check_win(vector<vector<int>> game_state){
    for(int i = 0; i < 3; i++){
        if(game_state[0][i] != 0 && game_state[i][0] == game_state[i][1] && game_state[i][1] == game_state[i][2]){
            return game_state[i][0];
        }    
    }
    for(int i = 0; i < 3; i++){
        if(game_state[0][i] != 0 && game_state[0][i] == game_state[1][i] && game_state[2][i] == game_state[0][i]){
            return game_state[0][i];
        }    
    }
    if(game_state[1][1] != 0 && game_state[0][0] == game_state[1][1] && game_state[1][1] == game_state[2][2]){
        return game_state[1][1];
    }
    if(game_state[1][1] != 0 && game_state[0][2] == game_state[1][1] && game_state[1][1] == game_state[2][0]){
        return game_state[1][1];
    }
    return 0;;
}

// Arguments: Game state (by refrence) Returns: Cleared game state (by refrence)
void clear_game(vector<vector<int>> &game_state){
    game_state = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
}

// Arguments: Game state (by refrence), position of move, 1 or 2 Returns: Updated game state (by refrence)
void add_move(vector<vector<int>> &game_state, int row, int col, int player){
    game_state[row][col] = player;
}

// Converts 0,1,2 into ' ', 'x', 'o'
char convert(int player){
    if(player == 0){
        return ' ';
    }else if(player == 1){
        return 'x';
    }else{
        return 'o';
    }
}

// Converts ' ', 'x', 'o' into 0,1,2
int convert(char player){
    if(player == 'x'){
        return 1;
    }else if (player == 'o'){
        return 2;
    }else{
        return -1;
    }
}

// Arguments: Game state | Outputs formatted game board to console
void print_game(vector<vector<int>> game_state){
    cout << " " << "  -----------" << endl;
    cout << "1" << " | " << convert(game_state[0][0]) << " | " << convert(game_state[0][1]) << " | " << convert(game_state[0][2]) << " | " << endl;
    cout << " " << " -----------" << endl; 
    cout << "2" << " | " << convert(game_state[1][0]) << " | " << convert(game_state[1][1]) << " | " << convert(game_state[1][2]) << " | " << endl;
    cout << " " << "  -----------" << endl; 
    cout << "3" << " | " << convert(game_state[2][0]) << " | " << convert(game_state[2][1]) << " | " << convert(game_state[2][2]) << " | " << endl;
    cout << " " << "  -----------" << endl;
    cout << " " << "   1   2   3" << endl;
}

// Arguments: Game state, Move position | Returns: True if move is valid, false otherwise. 
bool valid_move(vector<vector<int>>game_state, int row, int col){
    if(game_state[row][col] == 0){
        return true;
    }else{
        return false;
    }
}



int main(){
vector<vector<int>>game_state;
clear_game(game_state);
while(true){
        system("cls");
        int row = -1, col = -1;
        char marker;
        print_game(game_state);
        if(check_win(game_state) != 0){
            cout << endl << "Winner is: " << convert(check_win(game_state)) << endl << "(c) to reset, (q) to quit: ";
            char input;
            cin >> input;
            if(input == 'c'){
                clear_game(game_state);
                continue;
            }else{
                break;
            }
        }
        while(true){
            cout << "Enter Row, Col, x/o: " <<endl;
            cin >> row >> col >> marker;
            if((1 <= row && row <= 3) && (1 <= col && col <= 3) && (tolower(marker) == 'x' || tolower(marker) == 'o')){
                if(valid_move(game_state, row-1, col-1)){
                    add_move(game_state, row-1, col-1, convert(marker));
                }else{
                    cout << "invalid Move, Try Again\n";
                    continue;
                }
                break;
            }else{
                cout << "Invalid Input, Try Again\n";
                cin.clear();
                fflush(stdin);
                continue; 
            }
        }
}
return 0; 
}