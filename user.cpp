#include "user.h"
#include <iostream>

// ==== GETTERY ====
int User::getUserChoice() {
	return userChoice;
}

string User::getUserGuess() {
	return userGuess;
}

bool User::getIsWinner() {
	return isWinner;
}

//SETTERY
void User::setUserChoice(int newUserChoice) {
	userChoice = newUserChoice;
}

void User::setUserGuess(string newUserGuess) {
	userGuess = newUserGuess;
}

void User::setIsWinner(bool newIsWinner) {
	isWinner = newIsWinner;
}

// ==== FUNKCJE ====
void User::selectOptionInMenu() {
	int tmpUserChoice;
	cout << "Wybierz opcje z menu: ";
	cin >> tmpUserChoice;
	setUserChoice(tmpUserChoice);
}

void User::takeUserGuess() {
	string tmpUserAnswer;
	cout << "\nPodaj litere lub zgadnij haslo.\nTwoja odpowiedz: ";
	cin >> tmpUserAnswer;
	setUserGuess(tmpUserAnswer);

}