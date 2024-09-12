#include "Enigma.hpp"

char Enigma::Encrypt(char plainChar)
{

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

    if ((this->r2.left[0] == this->r2.notch) &&
        (this->r3.left[0] == this->r3.notch) &&
        (this->r4.left[0] == this->r4.notch) &&
        (this->r5.left[0] == this->r5.notch))
    {

        this->r1.Rotate(1);
        this->r2.Rotate(1);
        this->r3.Rotate(1);
        this->r4.Rotate(1);
        this->r5.Rotate(1);
    }
    else if ((this->r3.left[0] == this->r3.notch) &&
             (this->r4.left[0] == this->r4.notch) &&
             (this->r5.left[0] == this->r5.notch))
    {

        this->r2.Rotate(1);
        this->r3.Rotate(1);
        this->r4.Rotate(1);
        this->r5.Rotate(1);
    }
    else if ((this->r4.left[0] == this->r4.notch) &&
             (this->r5.left[0] == this->r5.notch))
    {
        this->r3.Rotate(1);
        this->r4.Rotate(1);
        this->r5.Rotate(1);
    }
    else if ((this->r5.left[0] == this->r5.notch))
    {

        this->r4.Rotate(1);
        this->r5.Rotate(1);
    }
    else
    {

        this->r5.Rotate(1);
    }

    return plainChar;
}