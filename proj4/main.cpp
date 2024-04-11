#include "config.h"
#include "charmatrix.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> g_lex;
CharMatrix g_grid;
void print_char_matrix()
{
    for (int y = 0; y < g_grid.height(); y++)
    {
        for (int x = 0; x < g_grid.width(); x++)
        {
            cout << g_grid.get(x, y);
        }
        cout << endl;
    }
}

void fill(int x, int y, char c, int max_depth)
{
if (max_depth==0){
    return;}

    if (config.debug)
{
    usleep(100000);
    for (int i = 0; i < 20; i++)
        cout << endl;
    print_char_matrix();
    cout.flush();
}
    char bef = g_grid.get(x, y);
    if (bef == c)
        return;
    g_grid.put(x, y, c);
    if (x > 0 && g_grid.get(x - 1, y) == bef)
        fill (x - 1, y, c, max_depth - 1);
    if (y > 0 && g_grid.get(x, y - 1) == bef)
        fill (x, y - 1, c, max_depth - 1);
    if (x + 1 < g_grid.width() && g_grid.get(x + 1, y) == bef)
        fill (x + 1, y, c, max_depth - 1);
    if (y + 1 < g_grid.height() && g_grid.get(x, y + 1) == bef)
        fill (x, y + 1, c, max_depth - 1);
}

void flood_fill()
{
    string word;
    cout << "Please enter a starting column:" << endl;
    cout << "> ";
    getline(cin, word);
    int x = stoi(word);
    cout << "Please enter a starting row:" << endl;
    cout << "> ";
    getline(cin, word);
    int y = stoi(word);
    cout << "Please enter a fill character:" << endl;
    cout << "> ";
    getline(cin, word);
    int c = word[0];
    cout << "Please enter the max fill depth:" << endl;
    cout << "> ";
    getline(cin, word);
    int max_depth = stoi(word);
    fill(x, y, c, max_depth);
}

void load_char_matrix()
{
    if (!config.quiet)
    {
        cout << "Please enter a grid of characters." << endl;
        cout << "All rows should have the same length." << endl;
        cout << "When you are done, just press Enter." << endl;
    }
    vector<string> grid;
    while(true)
    {
        string row;
        getline(cin, row);
        if (row.compare("") == 0)
            break;
        else if (grid.size() > 0 && row.size() != grid[0].size())
            throw std::runtime_error("Rows in a CharMatrix must all have the same size!");
        else
            grid.push_back(row);
    }
    int height = grid.size();
    int width = 0;
    if (height > 0)
        width = grid[0].size();
    g_grid.resize(width, height);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            g_grid.put(x, y, grid[y][x]);
        }
    }
}
void destroy_lexicon(vector<string>& lex)
{
    int word_capacity=lex.size();
    string popped_word;
    for (int i=word_capacity;i>0;i--){
        popped_word=lex.back();
        cout << popped_word << endl;
        lex.pop_back();
    }
}
void fill_lexicon(vector<string>& lex) {

while(true)
{

    quiet("\n");
    quiet("Please enter another word\n");
    quiet("> ");
    string word;
    getline(cin,word);

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
    for (unsigned int i = 0; i < lex.size(); i++)
    {
        cout << i << ". " << lex[i] << endl;
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
    cout << "3. Load char matrix" << endl;
    cout << "4. Print char matrix" << endl;
    cout << "5. Flood fill" << endl;
    cout << "> ";
    getline(cin,option);
     
    if (option.compare("0") == 0) {
        break;
    } else if ((option.compare("1") == 0)){
        fill_lexicon(g_lex);
    }
     else if (option.compare("2") == 0){
        destroy_lexicon(g_lex);
    } 
     else if (option.compare("3") == 0){
        load_char_matrix();
    } 
     else if (option.compare("4") == 0){
        print_char_matrix();
    } 
     else if (option.compare("5") == 0){
        flood_fill();
    } 
    else {
        cout << option << " Was not one of the options. Quitting." << endl;
        break;
    }
}
}


