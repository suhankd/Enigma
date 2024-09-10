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

        for (int j = 0; j < 26; j++)
        {

            std::swap(this->left[j], this->left[(j + 1) % 26]);
        }
    }
}

/*

The following is the rotor wiring for the Enigma-1, introduced in 1930, and the M3 Army, introduced in 1938

1,EKMFLGDQVZNTOWYHXUSPAIBRCJ
2,AJDKSIRUXBLHWTMCQGZNPYFVOE
3,BDFHJLCPRTXVZNYEIWGAKMUSQO
4,ESOVPZJAYQUIRHXLNFTGKDCMWB
5,VZBRGITYUPSDNHLXAWMJQOFECK

*/