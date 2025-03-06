#include <iostream>
#include <stdlib.h>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;


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

void clear_game(vector<vector<int>> &game_state){
    game_state = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
}

void add_move(vector<vector<int>> &game_state, int row, int col, int player){
    game_state[row][col] = player;
}

char convert(int player){
    if(player == 0){
        return ' ';
    }else if(player == 1){
        return 'x';
    }else{
        return 'o';
    }
}

int convert(char player){
    if(player == 'x'){
        return 1;
    }else if (player == 'o'){
        return 2;
    }else{
        return -1;
    }
}

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
        cout << "Enter Row, Col, x/o: " <<endl;
        cin >> row >> col >> marker;
        add_move(game_state, row-1, col-1, convert(marker));
    }

return 0; 
}