#ifndef lexicon_h
#define lexicon_h

#include <iostream>
using std::string;

// A data structure that holds words
class Lexicon
{
protected:
    string* words;
    int word_count;
    int capacity;

public:
    Lexicon();
    virtual ~Lexicon();
    void push_back(string& s);
    string& get(int index);
    string back();
    void pop_back();
    int size();
    int getCapacity();
};

void log(const string&);

#endif