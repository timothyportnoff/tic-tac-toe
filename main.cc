#include <iostream>
#include <string>

//Our players are X and O
char player[2] = {'X','O'};

char board[3][3] = {'1','2','3', '4','5','6', '7','8','9'};

void print_board() {
	//Saving the layout of the board in case I do something extremely catastrophic
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "-------+-------+-------" << std::endl;
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "-------+-------+-------" << std::endl;
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "       |       |       " << std::endl;
	//std::cout << "       |       |       " << std::endl;
	system("clear");
	std::cout << "       |       |       " << std::endl;
	std::cout << "   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "   " << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "-------+-------+-------" << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "   " << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "-------+-------+-------" << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "   " << std::endl;
	std::cout << "       |       |       " << std::endl;
	return;
}

void win(char c) {
	print_board();
	std::cout << "Player " << c << " wins!" << std::endl;
	exit(0);
}

void die(std::string msg = "") {
	std::cout << "ERROR: " << msg << std::endl;
	exit(1);
}

//This technically shouldn't take any arguments... 
int main(int argc, char *argv[]) {
	size_t i = 0, row = 0, col = 0, choice;
	bool turn = 0;
	while(i++ < 9) { //A funny new way to do a for loop hehe
		print_board();
		while(true) {
			std::cout << "\nPlayer [" << player[turn] << "]: Move: ";
			std::cin >> choice;//TODO need to vet this
			switch (choice) {
				case 1: row = 0; col = 0; break;
				case 2: row = 0; col = 1; break;
				case 3: row = 0; col = 2; break;
				case 4: row = 1; col = 0; break;
				case 5: row = 1; col = 1; break;
				case 6: row = 1; col = 2; break;
				case 7: row = 2; col = 0; break;
				case 8: row = 2; col = 1; break;
				case 9: row = 2; col = 2; break;
				default: die(); break;
			}
			if (board[row][col] == player[0] || board[row][col] == player[1]) {
				std::cout << "Spot is already taken!";
				continue;
			}
			break;
		}
		//Set the board location to X or O
		board[row][col] = player[turn];
		//row win check
		if (board[0][0] == board[0][1] and board[0][1] == board[0][2] ) win(player[turn]);
		if (board[1][0] == board[1][1] and board[1][1] == board[1][2] ) win(player[turn]);
		if (board[2][0] == board[2][1] and board[2][1] == board[2][2] ) win(player[turn]);
		//col win check
		if (board[0][0] == board[1][0] and board[1][0] == board[2][0] ) win(player[turn]);
		if (board[0][1] == board[1][1] and board[1][1] == board[2][1] ) win(player[turn]);
		if (board[0][2] == board[1][2] and board[1][2] == board[2][2] ) win(player[turn]);
		//Diagonal win check
		if (board[0][0] == board[1][1] and board[1][1] == board[2][2] ) win(player[turn]);
		if (board[0][2] == board[1][1] and board[1][1] == board[2][0] ) win(player[turn]);
		//If not win, negate turn for next player
		turn = !turn;
	}
	return 0;
}

