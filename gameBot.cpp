#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>
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
    return 0;
}

// Arguments: Game state (by refrence) Returns: Cleared game state (by refrence)
void clear_game(vector<vector<int>> &game_state){
    game_state = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
}

// Arguments: Game state and Bot move (by refence) | Returns game state + bots move(by refrence)
void add_move(vector<vector<int>> &game_state, vector<int> &bot_move){
    game_state[bot_move[0]][bot_move[1]] = 2;
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

bool moves_left(vector<vector<int>> game_state){
    for (int i = 0; i< 3; i++){
        for (int j = 0; j<3; j++){
            if (game_state[i][j]==0){ 
                return true; 
            }
        }
    }
return false;
}

int minimax(vector<vector<int>>game_state, int depth, bool is_max_player){
    int state = check_win(game_state);
    if(state == 2){
        return 10 - depth;
    }
    if(state == 1){
        return -10 + depth;
    }
    if(moves_left(game_state) == false){
        return 0; 
    }

    if (is_max_player){
        int best = -100;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(game_state[i][j] == 0){
                    game_state[i][j] = 2; 
                    best = max(best, (minimax(game_state, depth+1, !is_max_player)));
                    game_state[i][j] = 0;
                }
            }
        }
        return best;
    }else{
        int best = 100;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(game_state[i][j] == 0){
                    game_state[i][j] = 1; 
                    best = min(best, (minimax(game_state, depth+1, !is_max_player)));
                    game_state[i][j] = 0;
                }
            }
        }
        return best;
    }
}

vector<int> find_best_move(vector<vector<int>> game_state){
    vector<int> best_move = {-1,-1};
    int best_move_val = -1000;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <3; j++){
            if(game_state[i][j] == 0){
                game_state[i][j] = 2;
                int move_val = minimax(game_state, 0, false);
                game_state[i][j] = 0;
                if(move_val > best_move_val){
                    best_move[0] = i;
                    best_move[1] = j;
                    best_move_val = move_val;
                }
            }
        }
    }
    return best_move;
}


int main(){
vector<vector<int>>game_state;
clear_game(game_state);
while(true){
        system("cls");
        int row = -1, col = -1;
        vector<int> bot_move= {2,2};
        print_game(game_state);
        if(check_win(game_state) != 0 || moves_left(game_state) == false){
            if(check_win(game_state) != 0){
                cout << endl << "Winner is: " << convert(check_win(game_state)) << endl << "(c) to reset, (q) to quit: ";
            }else{
                cout << endl << "Stalemate, Nobody wins :(" << endl << "(c) to reset, (q) to quit: ";
            }
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
            cout << "Enter Row, Col: " <<endl;
            cin >> row >> col;
            if((1 <= row && row <= 3) && (1 <= col && col <= 3)){
                if(valid_move(game_state, row-1, col-1)){
                    game_state[row-1][col-1] = 1;
                    break;
                }else{
                    cout << "invalid Move, Try Again\n";
                    continue;
                }
            }else{
                cout << "Invalid Input, Try Again\n";
                cin.clear();
                fflush(stdin);
                continue; 
            }
        }
        if(check_win(game_state) == 0 && moves_left(game_state)==true){
            bot_move = find_best_move(game_state);
            add_move(game_state, bot_move);
        }
}
return 0; 
}