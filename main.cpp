#include "Enigma.hpp"
#include <iostream>

#define NUM_SWAPS 3 // Number of letters we want to swap.

// File for testing code.

int main(void)
{

    char swaps[NUM_SWAPS][2] = {{'A', 'R'}, {'G', 'K'}, {'O', 'X'}}; // The swaps we want to initiate.

    // Rotors.

    Rotor I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');
    Rotor II("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');
    Rotor III("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');
    Rotor IV("ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');
    Rotor V("VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');

    // Reflectors.

    Reflector A("EJMZALYXVBWFCRQUONTSPIKHGD");
    Reflector B("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    Reflector C("FVPJIAOYEDRZXWGCTKUQSBNMHL");

    KeyBoard KB;
    PlugBoard PB(swaps, NUM_SWAPS);

    char letter = 'A';

    int signal = KB.forward(letter);
    signal = PB.forwardProp(signal);
    signal = III.forwardProp(signal);
    signal = II.forwardProp(signal);
    signal = I.forwardProp(signal);
    signal = A.reflectSignal(signal);
    signal = I.backwardProp(signal);
    signal = II.backwardProp(signal);
    signal = III.backwardProp(signal);
    signal = PB.backwardProp(signal);
    letter = KB.backward(signal);

}