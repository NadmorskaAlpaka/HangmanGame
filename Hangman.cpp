#include "Hangman.h"
#include "color.h"
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

bool Hangman::getDeveloperMode() {
    return developerMode;
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

void Hangman::setDeveloperMode(bool newDeveloperMode) {
    developerMode = newDeveloperMode;
}

void Hangman::setHearts(int newHearts) {
    hearts = newHearts;
}

// ==== FUNKCJE ====
void Hangman::menu(int userChoice) {
    switch (userChoice) {
    case 1:
        break;
    case 2:
        showInstruction();
        break;
    case 3:
        showCredits();
        break;
    case 4:
        exit(0);
    case 5:
        setDeveloperMode(true);
        break;
    default:
        cout << "Ups, w menu nie znjajduje sie podana pozycja. \n Wybierz inna opcje";
    }
}

void Hangman::pickRandomNumber() {
    srand((unsigned int)time(NULL));
    randomNumber = rand() % bankOfWords.size();
}

void Hangman::setWordLetterAsUnderscore() {
    for (int i = 0; i < secretWord.size(); i++) {
        secretWordLetters.push_back("_");
    }
}

bool Hangman::checkIfUserWon() {
    string parsedSecretWord;

    for (int i = 0; i < secretWordLetters.size(); i++) {
        parsedSecretWord = parsedSecretWord + secretWordLetters[i];
    }

    return parsedSecretWord == secretWord;
}

int Hangman::readFile() {

    ifstream file;

    file.open("words.txt");
    if (file.fail()) {
        cout << "Nie udalo się odczytac pliku. \n";
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

void Hangman::decrementHearts() {
    cout << dye::red("\nTracisz jedno zycie");
    hearts--;
}

//funkcja sprawdza czy litera znajduje się w hasle i ją podmienia
int Hangman::checkUserGuessByLetter(string userGuess) {
    int letterIsInWord = 0;
    for (int i = 0; i < secretWord.size(); i++) {
        if (userGuess[0] == secretWord[i]) {
            secretWordLetters[i] = userGuess[0];
            letterIsInWord++;
        }
    }

    return letterIsInWord;
}

bool Hangman::checkUserGuessByWord(string userGuess) {
    if (userGuess == secretWord) {
        return true;
    } else {
        return false;
    }
}

void Hangman::checkIfLetterWasUsed(string userGuess, int letterIsInWord) {
    bool letterIsInBank = false;

    if (usedLetters.size() == 0) { //sprawdzenie czy bank słów jest pusty - jest
        setUssedLetters(userGuess);
        if (letterIsInWord <= 0) {
            decrementHearts();
        }
    } else { //sprawdzenie czy bank słów jest pusty - nie jest

        for (int i = 0; i < usedLetters.size(); i++) {
            if (userGuess[0] == usedLetters[i]) {
                cout << "Litera " << dye::red(usedLetters[i]) << " zostala juz uzyta.";
                letterIsInBank = true;
                continue;
            }
        }

        if (letterIsInWord > 0) {
            if (letterIsInBank == true) {
                decrementHearts();
            } else {
                setUssedLetters(userGuess);
            }

        } else { //litery nie ma w słowie
            if (letterIsInBank  == false) {
                setUssedLetters(userGuess);
            }
            decrementHearts();
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
    cout << "\nPozostalo zyc: " << getHearts();
}

void Hangman::showUsedLetters() {
    cout << "\nUzyte litery: ";
    for (int i = 0; i < usedLetters.size(); i++) {
        cout << usedLetters[i] << " ";
    }
    cout << "\n";
}

void Hangman::gameOver() {
    clearScreen();
    cout << "\n\t------------------------------------\n"
         << "\t|            "<<dye::red("GAME OVER")<<"             |\n"
         << "\t|        HASLEM BYLO SLOWO:        |\n"
         << "\t             " << getSecretWord() << "\n"
         << "\t------------------------------------\n";
}

void Hangman::gameWon() {
    clearScreen();
    cout << "\n\t------------------------------------\n"
         << "\t|             "<<dye::green("YOU WIN!") <<"             |\n"
         << "\t|        HASLEM BYLO SLOWO:        |\n"
         << "\t             " << getSecretWord() << "\n"
         << "\t------------------------------------\n";
}

void Hangman::showMenu() {
    cout << "\t-------------------------------------\n"
        << "\t|              WELCOME              |\n"
        << "\t|                 |                 |\n"
        << "\t|                 |                 |\n"
        << "\t|           "<<dye::aqua("HANGMAN GAME")<<"            |\n"
        << "\t|                                   |\n"
        << "\t|               MENU:               |\n"
        << "\t|          1.Rozpocznij gre         |\n"
        << "\t|          2.Instrukcja             |\n"
        << "\t|          3.Informacje             |\n"
        << "\t|          4.Zakoncz                |\n"
        << "\t-------------------------------------\n";
}

void Hangman::showCredits() {
    clearScreen();
    cout << "\t------------------------------------\n"
         << "\t|     PROGRAMOWANIE W JEZYKU C++    |\n"
         << "\t|       Temat: Gra Wisielec         |\n"
         << "\t|    Wyknoal: Grzegorz Szerszen     |\n"
         << "\t|       nr indeksu: 171678          |\n"
         << "\t------------------------------------\n";
}

void Hangman::showInstruction() {
    clearScreen();
    cout << "\t------------------------------------\n"
         << "\t|          Instrukcja gry           |\n"
         << "\t|  Gracz za zadanie ma odgadniecie  |\n"
         << "\t|  ukrytego hasla. Po rozpoczenciu  |\n"
         << "\t|  gry graczowi przyznawane jest 5  |\n"
         << "\t|  zyc. Haslo moze odgadnac litere  |\n"
         << "\t|  po literze albo wprowadzajac je  |\n"
         << "\t|  w calosci. Blad w nastepujacych  |\n"
         << "\t|  mozliwosciach skutkuje odjeciem  |\n"
         << "\t|        zycia. Powodzenia!!!       |\n"
         << "\t------------------------------------\n";
}

void Hangman::showDeveloperMode() {
     cout << dye::aqua("\n\t------------------------------------\n")
          << dye::aqua("\t|          DEVELOPER MODE          |\n")
          << dye::aqua("\t|             HASLO TO:            |\n")
          << "\t            "<< dye::aqua(getSecretWord()) << "\n"
          << dye::aqua("\t------------------------------------\n");
}

void Hangman::clearScreen() {
    system("CLS");
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