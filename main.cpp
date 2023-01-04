#include "Hangman.h"
#include <fstream>
#include <iostream>

int main() {

	Hangman game;

	int userChoice = 0;
	string userGuess = "";

	while (userChoice != 1) {
		game.startGame();
		cout << "Wybierz opcje: ";
		cin >> userChoice;

		switch (userChoice) {
		case 1:
			break;
		case 2:
			game.showInstruction();
			break;
		case 3:
			game.showCredits();
			break;
		case 4:
			return 0;
		default: 
			cout << "Ups, w menu nie znjajduje sie podana pozycja. \n Wybierz inna opcje";
		}
	}

	system("CLS");
	game.readFile();
	game.pickRandomNumber();
	game.setSecretWord();
	game.setHearts(5);
	game.setStartSecretWordLetters();
	cout << game.getSecretWord() << "\n";

	while (game.getHearts() != 0) {

		game.showHearts();
		game.showUsedLetters();
		game.showHangman(game.getHearts());
		game.showSecretWordLetters();

		cout << "\nPodaj litere lub zgadnij haslo.\nTwoja odpowiedz: ";
		cin >> userGuess;

		if (userGuess.size() > 1) {
			if (game.checkUserGuessByWord(userGuess)) {
				game.gameWon();
				return 0;
			} else {
				game.gameOver();
				game.showHangman(0);
				return 0;
			}
		}

		game.checkUserGuessByLetter(userGuess);

		if (game.checkIfLetterWasUsed(userGuess)) {
			game.decrementHearts();
		} else {
			game.setUssedLetters(userGuess);
			if (!game.checkUserGuessByLetter(userGuess)) {
				game.decrementHearts();
			}
		}

	}

	game.gameOver();
	game.showHangman(game.getHearts());

	return 0;
}