#include "game.h"

void Game::handleMenu() {
	while (user.getUserChoice() != 1 && user.getUserChoice() != 5) {
		hangman.showMenu();
		user.selectOptionInMenu();
		hangman.menu(user.getUserChoice());
	}
}

void Game::setUpGame() {
	hangman.readFile();
	hangman.pickRandomNumber();
	hangman.setSecretWord();
	hangman.setHearts(5);
	hangman.setWordLetterAsUnderscore();

	hangman.clearScreen();
}

int Game::gameLogic() {
	while (hangman.getHearts() != 0 && user.getIsWinner() != true) {

		if (hangman.getDeveloperMode() == 1) {
			hangman.showDeveloperMode();
		}

		hangman.showHearts();
		hangman.showUsedLetters();
		hangman.showHangman(hangman.getHearts());
		hangman.showSecretWordLetters();

		user.takeUserGuess();

		if (user.getUserGuess().size() > 1) {
			if (hangman.checkUserGuessByWord(user.getUserGuess())) {
				user.setIsWinner(true);
				return 0;
			}
			else {
				hangman.clearScreen();
				hangman.decrementHearts();
				continue;
			}
		}

		hangman.clearScreen();

		hangman.checkUserGuessByLetter(user.getUserGuess());
		hangman.checkIfLetterWasUsed(user.getUserGuess(), hangman.checkUserGuessByLetter(user.getUserGuess()));

		user.setIsWinner(hangman.checkIfUserWon());

	}
}

void Game::endGame() {
	if (user.getIsWinner() == true) {
		hangman.gameWon();
	}
	else {
		hangman.gameOver();
	}
}