#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void displayHangman(int mistakes) {
    vector<string> hangman = {
            "\n\n\n\n\n",
            "\n\n\n\n\n[]",
            "\n\n |\n |\n |\n[]",
            "\n  _____\n |     |\n |\n |\n[]",
            "\n  _____\n |     |\n |     O\n |\n[]",
            "\n  _____\n |     |\n |     O\n |     |\n[]",
            "\n  _____\n |     |\n |     O\n |    /|\n[]",
            "\n  _____\n |     |\n |     O\n |    /|\\ \n[]",
            "\n  _____\n |     |\n |     O\n |    /|\\ \n |    / ",
            "\n  _____\n |     |\n |     O\n |    /|\\ \n |    / \\",
    };
    cout << hangman[mistakes] << endl;
}

void playGame() {
    string secretWord, guessedWord;
    cout << "Introdu cuvantul de ghicit: ";
    cin >> secretWord;
    system("clear"); // Pentru a ascunde cuvântul introdus
    guessedWord = string(secretWord.length(), '_');

    int mistakes = 0;
    vector<char> guessedLetters;

    while (mistakes < 9 && guessedWord != secretWord) {
        displayHangman(mistakes);
        cout << "Cuvant: " << guessedWord << endl;
        cout << "Litere incercate: ";
        for (char c : guessedLetters) cout << c << ' ';
        cout << endl;

        cout << "Introdu o litera: ";
        char guess;
        cin >> guess;
        guessedLetters.push_back(guess);

        bool found = false;
        for (size_t i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (!found) {
            mistakes++;
        }
    }

    displayHangman(mistakes);
    if (guessedWord == secretWord) {
        cout << "Felicitari! Ai ghicit cuvantul: " << secretWord << "\n";
    } else {
        cout << "Ai pierdut! Cuvantul era: " << secretWord << "\n";
    }

    char choice;
    cout << "Vrei sa joci din nou? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        playGame();
    }
}

int main() {
    playGame();
    return 0;
}
