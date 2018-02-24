//
// Created by Chris Lawrence on 2/19/18.
// This class represents a String object.  The class provides
// functions for assigning the char array value of another String object
// or a char array to an existing instance, replacing the previous value.
// The class also provides functions for obtaining a pointer to the character data,
// the length of the character data (omitting the null terminator), the position of an
// input character in the character data, and whether an input String object has the same
// character value as the instance.
//
// This class centralizes much of the character value assignment into
// the private setValue function

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
    // in this TString and if so, at what position first.  Returns -1
    // if char does not exist
    int indexOf(char pChar) const;
    
    
private:
    // length of char data (not including null char)
    int mLength;
    // pointer to dynamic char array in heap
    char *mpText;
    // private function to manage setting the char data to the instance
    void setValue(const char *pText);
    // private function to clear memory
    void resetMpText();
};

#endif   // _TSTRING_H
