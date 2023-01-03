#include "Hangman.h"
#include <fstream>
#include <iostream>

int main() {

	Hangman hangman1;

	int userChoice = 0;

	while (userChoice != 1) {
		hangman1.startGame();
		cout << "Wybierz opcje: ";
		cin >> userChoice;

		switch (userChoice) {
		case 1:
			break;
		case 2:
			hangman1.instruction();
			break;
		case 3:
			hangman1.credits();
			break;
		case 4:
			return 0;
		default: 
			cout << "Ups, w menu nie znjajduje sie podana pozycja. \n Wybierz inna opcje";
		}
	}

	int hearts = 5;
	hangman1.readFile();
	hangman1.pickRandomNumber();
	hangman1.setSecretWord();

	//while (hearts != 0) {
		hangman1.showUsedLetters();
		hangman1.showHearts();
		cout << "Slowo: " << hangman1.getSecretWord();
	//}

	return 0;
}