#include "Enigma.hpp"

Rotor::Rotor(std::string wiring, char notch)
{

    this->right = wiring;
    this->notch = notch;
}

int Rotor::backwardProp(int signal)
{

    char letter = this->left[signal];
    int newSignal = this->right.find(letter);
    return newSignal;
}

int Rotor::forwardProp(int signal)
{

    char letter = this->right[signal];
    int newSignal = this->left.find(letter);
    return newSignal;
}

// Rotor stepping

void Rotor::Rotate(int numTurns)
{

    for (int i = 0; i < numTurns; i++)
    {

        for (int j = 1; j < NUM_ALPHAS; j++)
        {
            std::swap(this->right[j], this->right[(j + 1) % NUM_ALPHAS]);
            std::swap(this->left[j], this->left[(j + 1) % NUM_ALPHAS]);
        }
    }
}

void Rotor::show()
{

    std::cout << this->left << std::endl
              << this->right << std::endl;
}

void Rotor::RotateLetter(char letter) {

    int index = this->left.find(letter);
    this->Rotate(index);
}

/*

The following is the rotor wiring for the Enigma-1, introduced in 1930, and the M3 Army, introduced in 1938

1,EKMFLGDQVZNTOWYHXUSPAIBRCJ
2,AJDKSIRUXBLHWTMCQGZNPYFVOE
3,BDFHJLCPRTXVZNYEIWGAKMUSQO
4,ESOVPZJAYQUIRHXLNFTGKDCMWB
5,VZBRGITYUPSDNHLXAWMJQOFECK

*/