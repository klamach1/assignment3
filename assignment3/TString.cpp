//
// Created by Chris Lawrence on 2/19/18.
//

// -- TString.cpp source file --

#include <cstring>
#include "TString.h"

//ctor
TString::TString(const char *pText) {
    
    //init the char pointer to nullptr
    mpText = nullptr;
    setValue(pText);
    
}

// dtor
TString::~TString() {
    //clean up memory

    resetMpText();
    
}

// function to return char data length
int TString::length() const  {
    return mLength;
}

//function to return char data pointer
char *TString::asChar() const {
    return mpText;
}

// function to assign char data from TString object
void TString::assign(const TString &pTString) {
    //check for self assignment
    if (this != &pTString) {
        setValue(pTString.mpText);
    }
    
}

// function to assign char data from char array pointer
void TString::assign(const char *pText) {
    //check for self assignment
    if (pText != mpText) {
        setValue(pText);
    }
    
}

// function to determine whether two Strings have the same
// character data
bool TString::equals(const TString &pTString) const {
    return strcmp(pTString.mpText, mpText) ? false :true;
    
}

// function to determine whether and where a character
// exists in the TString char data
int TString::indexOf(char pChar) const {
    
    // default to no match
    int index = -1;
    
    int counter = 0;
    
    //loop until the end or we find a match
    while (counter<=mLength && index == -1) {
        
        mpText[counter] == pChar ? index = counter : index;
        counter++;
        
    }
    
    return index;
}

// private function to manage the set of the char data
void TString::setValue(const char *pText) {
    
    //if there is a value set, clear it
    if (mpText != nullptr) {
        resetMpText();
    }

    //if the input is null, set the length to 0, otherwise use strlen to set
    if (pText == nullptr) {
        mLength = 0;
    } else {
        mLength = static_cast<int>(strlen(pText));
    }
    
    // make sure to add 1 for the null terminator
    mpText = new char[mLength+1];
    
    // a zero length string should be set to the null terminator
    mLength == 0 ? mpText = strcpy(mpText, "\0") : strcpy(mpText, pText);
    
}

// private function to clear memory
void TString::resetMpText() {
    delete mpText;
    mpText = nullptr;
}




