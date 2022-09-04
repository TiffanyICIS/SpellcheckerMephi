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
    char* image = "dasndasd.png";
    BKTree* tree = new BKTree();
    char* filename = OCR(2, image);
    string line;

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
    while (word != "quit")
    {
        ifstream text(filename);
        if (text.is_open()) {
            while (getline(text, line)){
                word = line;
                tree->cleanString(word);

                start = clock();
                tree->search(word, 1);
                end = clock();

                elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
                cout << "Results found in " << elapsed_secs << "s" << endl << endl;
            }

        }
    }
    return 0;
}