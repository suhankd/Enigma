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
    void show();
};

class Reflector
{

public:
    std::string left = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::string right = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    Reflector(std::string wiring);
    int reflectSignal(int signal);
};

class Enigma
{

private:
    Reflector refl;
    Rotor r1;
    Rotor r2;
    Rotor r3;
    Rotor r4;
    Rotor r5;
    PlugBoard pb;
    KeyBoard kb;

public:
    Enigma(Reflector R, Rotor A, Rotor B, Rotor C, Rotor D, Rotor E, PlugBoard PB, KeyBoard KB)
        : refl(R), r1(A), r2(B), r3(C), r4(D), r5(E), pb(PB), kb(KB) {} // Constructor.

    char Encrypt(char plainChar);
};

#endif