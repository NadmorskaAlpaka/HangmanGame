#include "Hangman.h"
#include "user.h"
#include <fstream>
#include <iostream>

int main() {

	Hangman game;
	User user;

	while (user.getUserChoice() != 1 && user.getUserChoice() != 5) {
		game.showMenu();
		user.selectOptionInMenu();
		game.menu(user.getUserChoice());
	}

	game.readFile();
	game.pickRandomNumber();
	game.setSecretWord();
	game.setHearts(5);
	game.setWordLetterAsUnderscore();

	game.clearScreen();

	while (game.getHearts() != 0 && user.getIsWinner() != true) {
		
		if (game.getDeveloperMode() == 1) {
			game.showDeveloperMode();
		}

		game.showHearts();
		game.showUsedLetters();
		game.showHangman(game.getHearts());
		game.showSecretWordLetters();

		user.takeUserGuess();

		if (user.getUserGuess().size() > 1) {
			if (game.checkUserGuessByWord(user.getUserGuess())) {
				game.gameWon();
				return 0;
			} else {
				game.clearScreen();
				game.decrementHearts();
				continue;
			}
		}

		game.clearScreen();

		game.checkUserGuessByLetter(user.getUserGuess());
		game.checkIfLetterWasUsed(user.getUserGuess(), game.checkUserGuessByLetter(user.getUserGuess()));

		user.setIsWinner(game.checkIfUserWon());

	}

	if (user.getIsWinner() == true) {
		game.gameWon();
	} else {
		game.gameOver();
	}

	return 0;
}