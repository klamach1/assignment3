//
// Created by Chris Lawrence on 2/19/18.
//

// -- TString.cpp source file --

#include <cstring>
#include "TString.h"

TString::TString(const char *pText) {
    
    setValue(pText); //add the extra for the null terminator here
    
}

TString::~TString() {
    delete mpText;
    mpText = nullptr;
}
int TString::length() const  {
    return mLength;
}

char *TString::asChar() const {
    return mpText;
}

void TString::assign(const TString &pTString) {
    this->assign(pTString.asChar());
}

void TString::assign(const char *pText) {
    
    if (pText != mpText) {
        delete mpText;
        mpText = nullptr;
        setValue(pText);
    }
    
}

bool TString::equals(const TString &pTString) const {
    return strcmp(pTString.mpText, mpText) ? false :true;
    
}

int TString::indexOf(char pChar) const {
    
    int index = -1;
    
    int counter = 0;
    
    while (counter<=mLength) {
        
        mpText[counter] == pChar ? index = counter : index;
        counter++;
        
    }
    
    return index;
}

void TString::setValue(const char *pText) {
    
    if (pText == nullptr) {
        mLength = 0;
    } else {
        mLength = static_cast<int>(strlen(pText));
    }
    
    mpText = new char[mLength+1];
    
    mLength == 0 ? mpText = strcpy(mpText, "\0") : strcpy(mpText, pText);
    
}



