//
// Created by Chris Lawrence on 2/19/18.
//

// -- TString.h header file --

#ifndef _TSTRING_H    // only include once in a compilation unit
#define _TSTRING_H

class TString { // Prefix with 'T' for uniqueness
public:
    TString(const char *pText = 0); // default ctor
    
    // copy constructor using a delegating constructor
    explicit TString(const TString &pTString) : TString{pTString.asChar()} {};
    
    //dtor to free object
    ~TString();
    
    // function to get length of char
    int length() const;
    
    // function to return object's character data as character pointer
    char* asChar() const ;
    
    // function to assign a value of a TString object to this TString
    // replacing current contents
    void assign(const TString &pTString);
    
    // function to assign a value of a char pointer to this TString
    // replacing current contents
    void assign(const char *pText);
    
    // function to determine whether input TString is
    // "equal" to this TString
    bool equals(const TString &pTString) const;
    
    // function to check whether the input character exists
    // in this TString and if so, at what position.  Returns -1
    // if char does not exist
    int indexOf(char pChar) const;
    
    
private:
    int mLength;  // length of char data (not including null char)
    char *mpText; // pointer to dynamic char array in heap
    void setValue(const char *pText);
};

#endif   // _TSTRING_H
