#include "Enigma.hpp"

Reflector::Reflector(std::string wiring)
{

    this->right = wiring;
}

int Reflector::reflectSignal(int signal)
{

    char letter = this->right[signal];
    int newSignal = this->left.find(letter);
    return newSignal;
}