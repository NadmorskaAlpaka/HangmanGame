#pragma once
#include <string>
#include <vector>
using namespace std;

class Hangman {

	string secretWord;
	vector<string> bankOfWords;
	vector<string> secretWordLetters;
	vector<char> usedLetters;
	int randomNumber = 0;
	int hearts = 0; 
	bool developerMode = false;

	public:
		// ==== GETTERY ====
		string getSecretWord();
		int getRandomNumber();
		int getHearts();
		bool getDeveloperMode();

		// ==== SETTERY ====
		void setSecretWord();
		void setUssedLetters(string userGuess);
		void setDeveloperMode(bool newDeveloperMode);
		void setHearts(int newHearts);

		// ==== FUNKCJE ====
		void menu(int userChoice);
		void pickRandomNumber();
		void setWordLetterAsUnderscore();
		void decrementHearts();
		void checkIfLetterWasUsed(string userGuess, int letterIsInWord);
		int readFile();
		int checkUserGuessByLetter(string userGuess);
		bool checkUserGuessByWord(string userGuess);
		bool checkIfUserWon();

		// ==== FUNKCJE INFORMACYJNE ====
		void showMenu();
		void gameOver();
		void gameWon();
		void showHearts();
		void showInstruction();
		void showCredits();
		void showHangman(int numberOfHearts);
		void showSecretWordLetters();
		void showUsedLetters();
		void showDeveloperMode();
		void clearScreen();
};