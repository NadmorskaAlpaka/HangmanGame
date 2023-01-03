#pragma once
#include <string>
#include <vector>
using namespace std;

class Hangman {
	vector<string> bankOfWords;
	string secretWord;
	vector<string> usedLetters{ "a", "b", "c", "d", "e", "f" };
	int hearts = 5;
	int randomNumber = 0;

	public:
		//gettery
		int getHearts();
		string getSecretWord();
		int getRandomNumber();

		//settery
		void setSecretWord();
		void setHearts(int newHearts);
		void setUssedLetters(string newUsedLetter);

		//funkcje
		void pickRandomNumber();
		int readFile();
		void showHearts();
		void showUsedLetters();

		void startGame();
		void instruction();
		void credits();
		void showHangman(int numberOfHearts);
		void gameOver();
};