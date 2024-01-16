class Player {
	public:
		char symbol;
		virtual int getMove(int &x, int &y) = 0;
};

class Human : public Player{
	public:
		int getMove(int &x, int &y)
		{
			std::cout << "Player " << symbol << " enter move (row and column): ";
    		std::cin >> x >> y;
    		std::cout << std::endl;
    		return x, y;
		}
};

class Bot : public Player{
	public:
		int getMove(int &x, int &y)
		{
			std::cout << "Player " << symbol << " enter move (randomly generated)\n";
		    x = rand() % BOARDSIZE;
		    y = rand() % BOARDSIZE;
		    return x, y;
		}
};
