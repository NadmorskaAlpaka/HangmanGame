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

// ==== SETTERY ====

// funkcja dodaje zuzyta litere
void Hangman::setUssedLetters(string newUsedLetter) {
    usedLetters.push_back(newUsedLetter);
}

void Hangman::setSecretWord() {
    secretWord = bankOfWords[randomNumber];
}

// ==== FUNKCJE ====
void Hangman::pickRandomNumber() {
    srand(time(NULL));
    randomNumber = rand() % bankOfWords.size();
}

// funkcja odczytująca dane z pliku
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

void Hangman::showHearts() {
    cout << "\nPozotalo zyc: " << hearts << "\n";
}

void Hangman::showUsedLetters() {
    cout << "\nUzyte litery: ";
    for (int i = 0; i < usedLetters.size(); i++) {
        cout << usedLetters[i] << " ";
    }
}

void Hangman::gameOver() {
    cout << "\t------------------------------------\n"
         << "\t|            GAME OVER             |\n"
         << "\t------------------------------------\n";
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

void Hangman::credits() {
    cout << "\t------------------------------------\n"
        << "\t|     PROGRAMOWANIE W JEZYKU C++    |\n"
        << "\t|       Temat: Gra Wisielec         |\n"
        << "\t|    Wyknoal: Grzegorz Szerszen     |\n"
        << "\t|       nr indeksu: 171678          |\n"
        << "\t------------------------------------\n";
}

void Hangman::instruction() {
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