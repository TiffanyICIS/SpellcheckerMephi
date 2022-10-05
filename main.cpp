#include <iostream>
#include <fstream>
#include <ctime>
#include "BKTree.h"
#include "OCR.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

int main(int argc, const char * argv[]) {
    cout << "Hello, this is a spelling checker!\nPlease enter full address of your image:\n";
    char* image = new char[100];
    cin >> image;
    BKTree* tree = new BKTree();
    string text = OCR(image);
    cout << "Your image was read successfully!" << endl;
    string line;
    cout << "This is your text:" << endl << "____________________________\n"<< text << "____________________________" << endl;
    ifstream myFile("/home/ilyakudryavtsev/CLionProjects/SpellingChecker/words.txt");
    clock_t start;
    clock_t end;
    double elapsed_secs;

    if (myFile.is_open())
    {
        cout << "Building structure... " << endl;

        while (getline(myFile, line))
            tree->add(line);

        myFile.close();
    }
    cout << "Done." << endl << endl;
    string word;
    string ntxt;
    for (char i : text){
        if (((int)i > 64 and (int)i < 90) or ((int)i > 96 and (int)i < 122)){
            word.push_back(i);
        }
        else{
            cout << word << endl;
            tree->cleanString(word);
            tree->search(word, 1);
            word.clear();
        }
    }
    return 0;
}
// /home/ilyakudryavtsev/CLionProjects/SpellingChecker/TMP_RichTextLineIndent.png