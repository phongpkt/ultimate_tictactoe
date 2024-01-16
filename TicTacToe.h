#ifndef TICTACTOE_H_
#define TICTACTOE_H_

const int BOARDSIZE = 3;

struct Coordinate {
    int x;
    int y;
};

class TicTacToe {
private:
	int noOfMoves;
public:
	int board[BOARDSIZE][BOARDSIZE];
	TicTacToe();
	bool isValidMove(int, int);
	bool getXOMove(int&, int&);
	void addMoveToBoard(int, int, int);
	int gameStatus();
};

TicTacToe::TicTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

bool TicTacToe::isValidMove(int x, int y) {
	if (x < 0 || x >= 3 || y < 0 || y >= 3) {
		cout << "Invalid move! Row and column values must be between 1 and 3." << endl;
		return false;
	}
	if (board[x][y] != 0) {
		cout << "Invalid move! Cell is already occupied." << endl;
		return false;
	}
	return true;
}

bool TicTacToe::getXOMove(int &x, int &y) {

	if (noOfMoves >= 9)
		return false;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
	return true;
}

void TicTacToe::addMoveToBoard(int x, int y, int player) {
	board[x][y] = player;
}

int TicTacToe::gameStatus() {
    // check row
    for (int i = 0; i < 3; i++){
    if (board[i][0]==board[i][1] && board[i][1] == board [i][2]){
        return board[i][2];
    }
    }
    
    //check column
    for (int i = 0; i < 3; i++){
    if (board[0][i]==board[1][i] && board[1][i] == board [2][i]){
        return board[2][i];
    }
    }
    
    //check diagonal
    for (int i = 0; i < 3; i++){
    if (board[0][0]==board[1][1] && board[1][1] == board [2][2]){
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]){
        return board[0][2];
    }
    }
    
	if (noOfMoves >= 9)
		return 2;

	return 0;
}


#endif /* TICTACTOE_H_ */