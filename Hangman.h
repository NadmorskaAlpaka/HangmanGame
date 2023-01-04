#pragma once
#include <string>
#include <vector>
using namespace std;

class Hangman {
	vector<string> bankOfWords;
	string secretWord;
	vector<string> secretWordLetters;
	vector<char> usedLetters;
	int hearts;
	int randomNumber;

	public:
		//gettery
		string getSecretWord();
		int getHearts();
		int getRandomNumber();

		//settery
		void setSecretWord();
		void setHearts(int newHearts);
		void setUssedLetters(string userGuess);

		//funkcje
		int readFile();
		void pickRandomNumber();
		void decrementHearts();
		void setStartSecretWordLetters();
		bool checkUserGuessByLetter(string userGuess);
		bool checkUserGuessByWord(string userGuess);
		bool checkIfLetterWasUsed(string userGuess);

		//funkcje informacyjne
		void startGame();
		void gameOver();
		void gameWon();
		void showHearts();
		void showInstruction();
		void showCredits();
		void showHangman(int numberOfHearts);
		void showSecretWordLetters();
		void showUsedLetters();
};