#include <iostream>
#include <stdlib.h>
using namespace std;

// int print_game(int game_state[3][3]); 
// Prints the formatted board, input is the board as a 2D array
void print_game(char game_state[3][3]){
    cout << " " << "  -----------" << endl;
    cout << "1" << " | " << game_state[0][0] << " | " << game_state[0][1] << " | " << game_state[0][2] << " | " << endl;
    cout << " " << " -----------" << endl; 
    cout << "2" << " | " << game_state[1][0] << " | " << game_state[1][1] << " | " << game_state[1][2] << " | " << endl;
    cout << " " << "  -----------" << endl; 
    cout << "3" << " | " << game_state[2][0] << " | " << game_state[2][1] << " | " << game_state[2][2] << " | " << endl;
    cout << " " << "  -----------" << endl;
    cout << " " << "   1   2   3" << endl;
}

// Checks the board for any wins, Input is the board as a 2D array
// Returns: x = x win, o = o win, n = no winners, e = error. 
char check_win(char game_state[3][3]){
    for(int i = 0; i < 3; i++){
        if(game_state[0][i] != ' ' && game_state[i][0] == game_state[i][1] && game_state[i][1] == game_state[i][2]){
            return game_state[i][0];
        }    
    }
    for(int i = 0; i < 3; i++){
        if(game_state[0][i] != ' ' && game_state[0][i] == game_state[1][i] && game_state[2][i] == game_state[0][i]){
            return game_state[0][i];
        }    
    }
    if(game_state[1][1] != ' ' && game_state[0][0] == game_state[1][1] && game_state[1][1] == game_state[2][2]){
        return game_state[1][1];
    }
    if(game_state[1][1] != ' ' && game_state[0][2] == game_state[1][1] && game_state[1][1] == game_state[2][0]){
        return game_state[1][1];
    }
    return 'n';
}


int main() {
    system("cls");
    char game_state[3][3] = {
        { ' ',' ',' ' },
        { ' ',' ',' ' },
        { ' ',' ',' '}
    };

    while(true){
        system("cls");
        int row = -1, col = -1;
        char marker;
        print_game(game_state);
        if(check_win(game_state) != 'n'){
            cout << endl << "Winner is: " << check_win(game_state) << endl << "(c) to reset, (q) to quit: ";
            char input;
            cin >> input;
            if(input == 'c'){
                cout << "FIXME" << endl;
            }else{
                break;
            }
        }
        cout << "Enter Row, Col, x/o: " <<endl;
        cin >> row >> col >> marker;
        game_state[row-1][col-1] = marker;
    }
return 0;
}
       

