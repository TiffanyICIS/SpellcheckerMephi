//
// Created by ilyakudryavtsev on 11/6/22.
//

#ifndef SPELLINGCHECKER_INTERFACE_HPP
#define SPELLINGCHECKER_INTERFACE_HPP


#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "BKTree.h"
#include "OCR.h"

using namespace std;
class interface {
private:
    char *file_link;
    string ocr_text;
    vector<string> words;

    char* IMAGE1 = "/home/ilyakudryavtsev/CLionProjects/SpellingChecker/TheGreedyFriend.jpg";
    char* IMAGE2 = "/home/ilyakudryavtsev/CLionProjects/SpellingChecker/TheGreedyFriendComp.jpg";
    char* IMAGE3 = "111";

    void getText(){
        this->ocr_text = OCR(file_link);
    }

    void my_parse() {
        ocr_text += " ";
        string s_item;
        for (int i = 0; i < ocr_text.length(); i++) {
            if (ocr_text[i] != ' ') {
                s_item += ocr_text[i];
            } else {
                this->words.push_back(s_item);
                s_item = "";
            }
        }
    }

    static string correct_one(const string &word, const vector<string> &posible) {
        int i = 0;
        int selected = 0;

        cout << "0. Do nothing\n";
        for (const auto &item: posible) {
            i++;
            cout << i << ". " << item << endl;
        }

        cout << "Select: ";
        cin >> selected;
        if (selected == 0) {
            return word;
        }
        return posible[selected - 1];
    }
public:
    BKTree* initialize_BK_tree(){
        BKTree* tree = new BKTree();
        ifstream myFile("/home/ilyakudryavtsev/CLionProjects/SpellingChecker/words.txt");
        string line;
        if (myFile.is_open())
        {
            cout << "Building structure... " << endl;

            while (getline(myFile, line))
                tree->add(line);

            myFile.close();
        }
        cout << "Done." << endl << endl;
        return tree;
    }

    void set_file_link() {
        string s;
        cout << "Enter file name: \n";
        this->file_link = new char[255];
        cin >> this->file_link;

    }

    void print_link() {
        cout << this->file_link;
    }

    void print_arr() {
        for (auto i: this->words) {
            cout << i << " ";
        }
    }

    void spell_check() {
        cout << "This is OCR Spelling Checking Program\n" << "What image do you want to use?\n" << "1. I want to use my image\n" << "2. I want to use program image\nSelect: ";
        int p;
        cin >> p;
        if (p == 1){
            set_file_link();
        }else{
            int pp;
            cout << "What type of predownloaded image do you wanna use??\n" << "1. Handwritten text \"The Greedy Friend\"\n" << "2. Computer text \"The Greedy Friend\"\nSelect: ";
            cin >> pp;
            if (pp == 1) {
                this->file_link = IMAGE1;
            } else if (pp == 2){
                this->file_link = IMAGE2;
            }

        }
        getText();
        BKTree tree = *initialize_BK_tree();
        my_parse();
        print_arr();
        cout << '\n';
        vector<string> tmp;
        int k = 0;
        for (auto i: words) {
            cout << "Now we are working with: " << i << endl;
            tree.cleanString(i);
            tmp = tree.search(i, 1);
            words[k] = correct_one(i, tmp);
            k++;
            cout << endl;
        }
        outPut();
    }

    void outPut() {
        int selected = 0;
        cout << "Ok. How should I write your text?\n(0)-stdout\n(1)-file.txt\nSelect: ";
        cin >> selected;

        if (selected == 0)
            print_arr();
        else {
            string file_name;
            cout << "Enter the file name: ";
            cin >> file_name;

            ofstream file;
            file.open(file_name);
            if (file.is_open()) {
                for (auto item: words) {
                    file << item << " ";
                }
            }

        }
    }
};



#endif //SPELLINGCHECKER_INTERFACE_HPP
