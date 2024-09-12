#include "Enigma.hpp"
#include <iostream>

#define NUM_SWAPS 3 // Number of letters we want to swap.

// File for testing code.

int main(int argc, char **argv)
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

    if (sizeof(argv[1]) / sizeof(argv[1][0]) != 4)
    {
        std::cout << sizeof(argv[1]) / sizeof(argv[1][0]);
        std::cout << "Invalid key size. Restrict to 5 characters" << std::endl;
        return -1;
    }

    std::string plainText;
    std::getline(std::cin >> std::ws, plainText);

    Enigma Enigma_Instance(A, I, II, III, IV, V, PB, KB); // Initializing the Enigma

    // Key Encryption.

    for (int i = 0; i < 5; i++)
    {

        Enigma_Instance.r1.RotateLetter((char)argv[1][0]);
        Enigma_Instance.r2.RotateLetter((char)argv[1][1]);
        Enigma_Instance.r3.RotateLetter((char)argv[1][2]);
        Enigma_Instance.r4.RotateLetter((char)argv[1][3]);
        Enigma_Instance.r5.RotateLetter((char)argv[1][4]);
    }

    for (int i = 0; i < sizeof(plainText) / sizeof(plainText[0]); i++)
    {

        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                plainText[i] = (char)(Enigma_Instance.Encrypt(plainText[i]));
            }
            else
            {

                plainText[i] = (char)(Enigma_Instance.Encrypt(plainText[i] - 32));
            }
        }
    }

    std::cout << plainText << std::endl;
}