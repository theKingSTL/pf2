#include "config.h"
#include "lexicon.h"
#include <iostream>
#include <cstring>
#include <string>

using std::cout,std::string,std::endl;
Lexicon g_lex;
void destroy_lexicon(Lexicon& lex)
{
    int word_capacity=lex.size();
    string popped_word;
    for (int i=word_capacity;i>0;i--){
        popped_word=lex.back();
        cout << popped_word << endl;
        lex.pop_back();
    }
}
void fill_lexicon(Lexicon& lex) {

while(true)
{

    quiet("\n");
    quiet("Please enter another word\n");
    quiet("> ");
    string word;
    getline(std::cin,word);

    if (word.size() == 0)
    {
        break;
    }  
    else if (word.compare("-") == 0){
        lex.pop_back();
    }
    else{
        lex.push_back(word);
    }
    

    quiet( "So far, the words you have entered are:\n");
if(config.quiet==false){
    for (int i = 0; i < lex.size(); i++)
    {
        cout << i << ". " << lex.get(i) << endl;
    }
}
}}

int main(int argc, char** argv)
{
config.parse_flags(argc, argv);
log("---Running in debug mode---");
string option;

while (true)
{
    cout << "Dylan Stroud PF2 projects" << endl;
    cout << "Lexicon size: " << g_lex.size() << endl << endl;
    cout << "0. Quit" << endl;
    cout << "1. Fill lexicon" << endl;
    cout << "2. Tear Down Lexicon" << endl;
    cout << "> ";
    getline(std::cin,option);
     
    if (option.compare("0") == 0) {
        break;
    } else if ((option.compare("1") == 0)){
        fill_lexicon(g_lex);
    }
     else if (option.compare("2") == 0){
        destroy_lexicon(g_lex);
    } 
    else {
        cout << option << " Was not one of the options. Quitting." << endl;
        break;
    }
}
}


