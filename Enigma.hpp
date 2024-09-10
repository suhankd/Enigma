#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <string>

#define NUM_ALPHAS 26

// Defining the different components of the enigma machine.

class KeyBoard
{

public:
    int forward(char letter);
    char backward(int signal);
};

class PlugBoard
{

public:
    std::string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string right = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    PlugBoard(char pairs[2][2], int numSwaps); // Constructor.

    int forwardProp(int signal);
    int backwardProp(int signal);
};

class Rotor
{

public:
    std::string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string right = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char notch;

    Rotor(std::string wiring, char notch); // Constructor.

    // Propogation

    int forwardProp(int signal);
    int backwardProp(int signal);

    void Rotate(int numTurns); // Rotor stepping.

};

class Reflector
{

public:

    std::string left = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string right = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    Reflector(std::string wiring);
    int reflectSignal(int signal);
};

#endif