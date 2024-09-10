#include "Enigma.hpp"

int KeyBoard::forward(char letter)
{

    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return alphabet.find(letter);
}

char KeyBoard::backward(int signal)
{

    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return alphabet[signal];
}
