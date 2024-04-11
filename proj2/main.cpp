#include "config.h"
#include "lexicon.h"
#include <iostream>

int main(int argc, char** argv)
{

config.parse_flags(argc, argv);
log("---Running in debug mode---");
Lexicon lex;
int loop_it=lex.getCapacity();

for(int loop=0;loop<loop_it;loop++)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << std::endl;
    }
    std::cout << "Please enter another word" << std::endl;
    std::cout << "> ";
    std::string word;
    getline(std::cin, word);
    if (word.size() == 0)
    {
        break;
    }  
    lex.push_back(word);

    std::cout << "So far, the words you have entered are:" << std::endl;
    for (int i = 0; i < lex.size(); i++)
    {
        std::cout << i << ". " << lex.get(i) << std::endl;
    }
}
}
