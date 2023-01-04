#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

// ==== GETTERY ====

int Hangman::getRandomNumber() {
    return randomNumber;
}

string Hangman::getSecretWord() {
    return secretWord;
}

int Hangman::getHearts() {
    return hearts;
}

// ==== SETTERY ====

// funkcja dodaje zuzyta litere
void Hangman::setUssedLetters(string userGuess) {
    usedLetters.push_back(userGuess[0]);
}

void Hangman::setSecretWord() {
    secretWord = bankOfWords[randomNumber];
}

void Hangman::setHearts(int newHearts) {
    hearts = newHearts;
};

// ==== FUNKCJE ====
void Hangman::pickRandomNumber() {
    srand(time(NULL));
    randomNumber = rand() % bankOfWords.size();
}

void Hangman::decrementHearts() {
    hearts--;
}

void Hangman::setStartSecretWordLetters() {
    for (int i = 0; i < secretWord.size(); i++) {
        secretWordLetters.push_back("_");
    }
}

int Hangman::readFile() {

    ifstream file;

    file.open("words.txt");
    if (file.fail()) {
        cout << "Nie udało się odczytac pliku. \n";
        return 1;
    }

    string fileLine; //zmienna pomocnicza chwilowo przechowuje poszczególne linijki z pliku

    while (!file.eof()) {
        getline(file, fileLine); //pobiera linie z pliku i zapisuje ją do zmiennej
        bankOfWords.push_back(fileLine); //dodaje wcześniej zapisana linie do tablicy
    }

    file.close();

    return 0;
}

bool Hangman::checkUserGuessByLetter(string userGuess) {
    int goodGuess = 0;
    for (int i = 0; i < secretWord.size(); i++) {
        if (userGuess[0] == secretWord[i]) {
            secretWordLetters[i] = userGuess[0];
            goodGuess++;
        }
    }

    if (goodGuess >= 1) {
        return true;
    } else {
        return false;
    }
}

bool Hangman::checkUserGuessByWord(string userGuess) {
    if (userGuess == secretWord) {
        return true;
    } else {
        return false;
    }
}

bool Hangman::checkIfLetterWasUsed(string userGuess) {
    for (int i = 0; i < usedLetters.size(); i++) {
        if (userGuess[0] == usedLetters[i]) {
            cout << "Ups, juz uzyles tej litery. Tracisz jedno zycie";
            return true;
        } else {
            return false;
        }
    }
}

// ==== FUNKCJE INFORMACYJNE ====
void Hangman::showSecretWordLetters() {
    cout << "\n\t Haslo: ";
    for (int i = 0; i < secretWordLetters.size(); i++) {
        cout << secretWordLetters[i] << " ";
    }
    cout << "\n";
}

void Hangman::showHearts() {
    cout << "\nPozotalo zyc: " << hearts;
}

void Hangman::showUsedLetters() {
    cout << "\nUzyte litery: ";
    for (int i = 0; i < usedLetters.size(); i++) {
        cout << usedLetters[i] << " ";
    }
    cout << "\n";
}

void Hangman::gameOver() {
    system("CLS");
    cout << "\n\t------------------------------------\n"
         << "\t|            GAME OVER             |\n"
         << "\t|       HASLEM BYLO SLOWO:         |\n"
         << "\t             " << secretWord << "\n"
         << "\t------------------------------------\n";
}

void Hangman::gameWon() {
    system("CLS");
    cout << "\n\t------------------------------------\n"
         << "\t|             YOU WIN!              |\n"
         << "\t------------------------------------\n"
        << "\tHASLEM BYLO SLOWO: " << secretWord << "\n";
}

void Hangman::startGame() {
    cout << "\t------------------------------------\n"
        << "\t|              WELCOME              |\n"
        << "\t|                 |                 |\n"
        << "\t|                 |                 |\n"
        << "\t|           HANGMAN GAME            |\n"
        << "\t|                                   |\n"
        << "\t|               MENU:               |\n"
        << "\t|           1.Start Game            |\n"
        << "\t|           2.Instruction           |\n"
        << "\t|           3.Credits               |\n"
        << "\t|           4.Zakoncz               |\n"
        << "\t------------------------------------\n";
}

void Hangman::showCredits() {
    system("CLS");
    cout << "\t------------------------------------\n"
        << "\t|     PROGRAMOWANIE W JEZYKU C++    |\n"
        << "\t|       Temat: Gra Wisielec         |\n"
        << "\t|    Wyknoal: Grzegorz Szerszen     |\n"
        << "\t|       nr indeksu: 171678          |\n"
        << "\t------------------------------------\n";
}

void Hangman::showInstruction() {
    system("CLS");
    cout << "\t------------------------------------\n"
        << "\t|          Instrukcja gry           |\n"
        << "\t------------------------------------\n";
}

void Hangman::showHangman(int numberOfHearts) {
	switch (numberOfHearts) {
		case 0:
            cout << "\t------------------------------------\n"
                 << "\t|                                  |\n"
                 << "\t|   |______________                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |            ( )               |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |          \\  |  /             |\n"
                 << "\t|   |           \\ | /              |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |            / \\               |\n"
                 << "\t|   |           /   \\              |\n"
                 << "\t|   |                              |\n"
                 << "\t------------------------------------\n";
            break;
        case 1:
            cout << "\t------------------------------------\n"
                 << "\t|                                  |\n"
                 << "\t|   |______________                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |            ( )               |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |          \\  |  /             |\n"
                 << "\t|   |           \\ | /              |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |              \\               |\n"
                 << "\t|   |               \\              |\n"
                 << "\t|   |                              |\n"
                 << "\t------------------------------------\n";
            break;
        case 2:
            cout << "\t___________________________________ \n"
                 << "\t|                                  |\n"
                 << "\t|   |______________                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |            ( )               |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |          \\  |  /             |\n"
                 << "\t|   |           \\ | /              |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t------------------------------------\n";
            break;
        case 3:
            cout << "\t------------------------------------\n"
                 << "\t|                                  |\n"
                 << "\t|   |______________                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |            ( )               |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |  /             |\n"
                 << "\t|   |             | /              |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t------------------------------------\n";
            break;
        case 4:
            cout << "\t------------------------------------\n"
                 << "\t|                                  |\n"
                 << "\t|   |______________                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |            ( )               |\n"
                 << "\t|   |             |                |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t------------------------------------ \n";
            break;
        case 5:
            cout << "\t------------------------------------\n"
                 << "\t|                                  |\n"
                 << "\t|   |______________                |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t|   |                              |\n"
                 << "\t------------------------------------ \n";
            break;
	}
};