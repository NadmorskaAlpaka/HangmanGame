#pragma once
#include <string>
#include <vector>
using namespace std;

class Hangman {
	string secretWord;
	int hearts = 2;
	vector<string> usedLetters{ "a", "b", "c", "d", "e", "f" };

	public:
		//gettery
		int getHearts();
		string getSecretWord();

		//settery
		void setSecretWord(string newSecretWord);
		void setHearts(int newHearts);
		void setUssedLetters(string newUsedLetter);

		//funkcje
		void showHearts();
		void showUsedLetters();
		void showHangman(int numberOfHearts);
		void gameOver();
};