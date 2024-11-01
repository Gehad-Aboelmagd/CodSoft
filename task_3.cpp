// Tic Tac Toe Game

#include <iostream>

using namespace std;

const int board_rows = 3;
const int board_size = 9;

char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char explanatory_board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void board_initialization();
void gameLoop(char first_player);
void displayBoard(char* board);
void updateBoard(char player, int move);
bool checkForWinner(char current_player);
void switchPlayer(char* current_player);


int main () {    
    char first_player;
    char replay = 'n';

    do{
        board_initialization();

        cout << "First player (x or o): ";
        cin >> first_player;

        if (first_player=='x' || first_player=='o') {
            cout << "To place a symbol, enter a number corresponding to square:" << endl;
            displayBoard(explanatory_board);

            gameLoop(first_player);
        }
        else{
            cout << "Invalid Symbol !" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> replay;

    }
    while(replay == 'y');
    
    return 0;
}

void board_initialization() {
    for(int i=0; i<board_size; i++) {
        board[i] = ' ';
    }
}

void gameLoop(char first_player) {
    char current_player = first_player;
    int move;

    int counter = 0;
    while(counter < board_size) {
        if(current_player == first_player) {
            cout << "First player: ";
        }
        else {
            cout << "Second player: ";
        }
        
        cin >> move;
        
        if(move>=1 && move<=board_size && board[move - 1]==' ') {
            updateBoard(current_player, move);
            displayBoard(board);

            bool is_winner = checkForWinner(current_player);
            if(is_winner) {
                (current_player == first_player)? cout << "Winner is first player" << endl
                                                : cout << "Winner is second player" << endl;
                return;
            }

            counter ++;            
            switchPlayer(&current_player);
        }
        else {
            cout << "Invalid move! Try Again." << endl;
        }

    }

    cout << "Oops! You reach tie !" << endl;
}

void displayBoard(char* board) {

    for(int i=0; i<board_rows; i++) {
        cout << "-------------" << endl;

        for(int j=0; j<board_rows; j++) {
            cout << "| " << board[board_rows*i+j] << " ";
        }

        cout << "|" << endl;
    }

        cout << "-------------" << endl;
}

void updateBoard(char player, int move) {
    board [move - 1] = player;
}

bool checkForWinner(char current_player) {
    int row_hit = 0;
    int col_hit = 0;
    int left_diagonal_hit = 0;
    int right_diagonal_hit = 0;

    for(int i=0; i<board_rows; i++) {
        row_hit = 0;
        col_hit = 0;

        for(int j=0; j<board_rows; j++) {
            if(board[board_rows*i + j] == current_player) {
                row_hit ++;
            }

            if(board[board_rows*j + i] == current_player) {
                col_hit ++;
            }
        }

        if((row_hit == board_rows) || (col_hit == board_rows)) {
            return true;
        }
    }

    for(int i=0; i<board_rows; i++) {
        if(board[board_rows*i + i] == current_player) {
            left_diagonal_hit ++;
        }

        if(board[board_rows*i + (board_rows-1-i)] == current_player){
            right_diagonal_hit ++;
        }
    }

    if((left_diagonal_hit == board_rows) || (right_diagonal_hit == board_rows)) {
        return true;
    }

    return false;
}


void switchPlayer(char* current_player) {
    if(*current_player == 'x') {
        *current_player = 'o';
    }
    else {
        *current_player = 'x';
    }
}
