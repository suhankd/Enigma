#include "Enigma.hpp"

char Enigma::Encrypt(char plainChar) {

    int signal = this->kb.forward(plainChar);
    signal = this->pb.forwardProp(signal);

    // Front Propogation

    signal = this->r5.forwardProp(signal);
    signal = this->r4.forwardProp(signal);
    signal = this->r3.forwardProp(signal);
    signal = this->r2.forwardProp(signal);
    signal = this->r1.forwardProp(signal);

    signal = this->refl.reflectSignal(signal); // Reflection.

    // Back Propogation.

    signal = this->r1.backwardProp(signal);
    signal = this->r2.backwardProp(signal);
    signal = this->r3.backwardProp(signal);
    signal = this->r2.backwardProp(signal);
    signal = this->r1.backwardProp(signal);

    signal = this->pb.backwardProp(signal);
    plainChar = this->kb.backward(signal);

    // Rotating the Rotors.

    if(this->)

    return plainChar;

}