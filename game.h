#pragma once
#include "user.h"
#include "hangman.h"

class User;
class Hangman;

class Game {
public:
	void handleMenu();
	void setUpGame();
	int gameLogic();
	void endGame();
	User user;
	Hangman hangman;
};