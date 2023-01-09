#include "game.h"
#include <fstream>
#include <iostream>

int main() {

	Game game;

	game.handleMenu();
	game.setUpGame();
	game.gameLogic();
	game.endGame();

	return 0;
}