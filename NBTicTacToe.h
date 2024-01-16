#pragma once

#include "TicTacToe.h"
#include "Player.h"

class NBTicTacToe {
	public:
	    NBTicTacToe(){
	        currentBoard.x = rand() % 3;
	        currentBoard.y = rand() % 3;
	    }
	    void play();
	    void displayBoard(int x , int y);
	    void drawLine(int x, int y, bool star);
	    void drawMiddleLine(int x, int y, bool star);
	    void NewBoard(int x, int y);
	    void isTie();
	private:
		Human human;
		Bot bot;
	    TicTacToe grid[3][3];
	    Coordinate currentBoard;
};

void NBTicTacToe::displayBoard(int new_x, int new_y) {//Where to get the board data?
    bool star = false;
    for (int x = 0; x < 3; x++){
        cout << " ";
        if (x == new_x){
            star = true;
        }
        drawLine(new_x, new_y, star);
		cout << "\n";
		for (int y = 0; y < 3; y++){
			for (int i = 0; i < 3; i++){
                if(star == true && i == new_y)
                {
                    cout << "* ";
                } else {
                    cout << "| ";
                }	
				for (int j = 0; j < 3; j++){
                    char symbol;
                    int square = grid[x][i].board[y][j];
                    if (square == 1){
                        symbol = 'X';
                    }else if (square == -1){
                        symbol = 'O';
                    }else {
                        symbol = ' ';
                    }
                    cout << symbol;
                    if (j < 2) {
                        cout << " | ";
                    }
				}
                if(star == true && i == new_y){
                    cout << " * ";
                } else {
                    cout << " | ";
                }
			}
            cout << "\n";
            if (y < 2){
            	drawMiddleLine(new_x, new_y, star);
            }
		}
		cout << " ";
		drawLine(new_x, new_y, star);
        star = false;
        cout << "\n";
	}
}

void NBTicTacToe::drawLine(int x, int y, bool star) {
	for (int k = 0; k < 3; k++){				
        if (k == y && star == true){
            cout << " * * * * * ";
            cout << "   ";
        } else {
            cout << " - - - - - ";
            cout << "   ";
        }
	}
}

void NBTicTacToe::drawMiddleLine(int x, int y, bool star) {
    for (int k = 0; k < 3; k++){
        if (k == y && star == true)
        {
            cout << "* -   -   - *";
		    cout << " ";	
        }else{
		    cout << "| -   -   - |";
		    cout << " ";	
        }			
	}
	cout << "\n";	
}

void NBTicTacToe::play() {
    int done = 0;
	bot.symbol = 'X';
	human.symbol = 'O';
    char playerTurn = bot.symbol;
    displayBoard(currentBoard.x, currentBoard.y);
	
    while (done == 0) {
        int x, y;
        if (playerTurn == bot.symbol) {
        	do {
        		x, y = bot.getMove(x, y);	// get bot input
        	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(x, y));
        } else {
        	do {
        		x, y = human.getMove(x, y);	// get player input
        	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(x - 1, y - 1)); //validate input
        	//because the board array starts from 0, we have to subtract 1 from both x and y
        	x = x - 1;
        	y = y - 1;
        }
        grid[currentBoard.x][currentBoard.y].addMoveToBoard(x, y, (playerTurn == 'X') ? 1 : -1);
        displayBoard(x, y);
        done = grid[currentBoard.x][currentBoard.y].gameStatus();
        if (done == 1) {
            std::cout << "Player X wins!" << std::endl;
            return;
        } else if (done == -1) {
            std::cout << "Player O wins!" << std::endl;
            return;
        } else {
            isTie();
        }
        playerTurn = (playerTurn == bot.symbol) ? human.symbol : bot.symbol;
    	NewBoard(x, y);
    }
}

void NBTicTacToe::isTie(){
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (grid[currentBoard.x][currentBoard.y].gameStatus() == 2){
                std::cout << "Draw!" << std::endl;
            }
        }
    }
}

void NBTicTacToe::NewBoard(int x, int y){
    currentBoard.x = x;
    currentBoard.y = y;
    while (grid[currentBoard.x][currentBoard.y].gameStatus() == 2){
        currentBoard.x = rand() % 3;
        currentBoard.y = rand() % 3;
    }
}