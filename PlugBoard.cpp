#include "Enigma.hpp"

PlugBoard::PlugBoard(char pairs[2][2], int numSwaps)
{
    for (int i = 0; i < numSwaps; i++)
    {

        int pos1 = left.find(pairs[i][0]);
        int pos2 = left.find(pairs[i][1]);

        std::swap(left[pos1], left[pos2]);
    }
}

int PlugBoard::forwardProp(int signal)
{

    char letter = this->right[signal];
    int newSignal = this->left.find(letter);
    return newSignal;
}

int PlugBoard::backwardProp(int signal)
{

    char letter = this->left[signal];
    int newSignal = this->right.find(letter);
    return newSignal;
}