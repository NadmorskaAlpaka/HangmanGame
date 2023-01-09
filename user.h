#pragma once
#include <string>

using namespace std;

class User {

	string userGuess;
	int userChoice = 0;
	bool isWinner = false;

public:
	// ==== GETTERY ====
	string getUserGuess();
	int getUserChoice();
	bool getIsWinner();

	// ==== SETTERY ====
	void setUserGuess(string userGuess);
	void setUserChoice(int newUserChoice);
	void setIsWinner(bool newIsWinner);

	// ==== FUNKCJE ====
	void selectOptionInMenu();
	void takeUserGuess();
};