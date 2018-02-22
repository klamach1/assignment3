//
// Created by Chris Lawrence on 2/19/18.
//

// -- TString.cpp source file --

#include <cstring>
#include "TString.h"

TString::TString(const char *pText) {
    
    setValue(pText);
    
}

// dtor
TString::~TString() {
    //clean up memory
    delete mpText;
    mpText = nullptr;
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
    this->assign(pTString.asChar());
}

// function to assign char data from char array pointer
void TString::assign(const char *pText) {
    
    if (pText != mpText) {
        delete mpText;
        mpText = nullptr;
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
    
    int index = -1;
    
    int counter = 0;
    
    while (counter<=mLength) {
        
        mpText[counter] == pChar ? index = counter : index;
        counter++;
        
    }
    
    return index;
}

// private function to manage the set of the char data
void TString::setValue(const char *pText) {
    
    if (pText == nullptr) {
        mLength = 0;
    } else {
        mLength = static_cast<int>(strlen(pText));
    }
    
    mpText = new char[mLength+1];
    
    mLength == 0 ? mpText = strcpy(mpText, "\0") : strcpy(mpText, pText);
    
}



