#include <iostream>
#include <string>

char player[2] = {'X','O'};
char board[3][3] = {'1','2','3', '4','5','6', '7','8','9'};

void die(std::string msg = "") {
	std::cout << "ERROR: " << msg << std::endl;
	exit(1);
}
void print_grid() {
	//Saving the layout of the grid in case I do something extremely catastrophic
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

int main(int argc, char *argv[]) {
	size_t i = 0;
	bool turn = 0;
	std::string choice;
	while(i++ < 9) { //A funny new way to do a for loop hehe
		print_grid();
		std::cout << "\nPlayer [" << player[turn] << "]: Move: " << std::endl;
		std::cin >> choice;
		turn = !turn;
	}
	return 0;
}

