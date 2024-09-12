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

    std::string plainText;
    std::getline(std::cin >> std::ws, plainText);

    Enigma Enigma_Instance(A, I, II, III, IV, V, PB, KB); // Initializing the Enigma
    std::cout << Enigma_Instance.Encrypt(letter) << std::endl;

}