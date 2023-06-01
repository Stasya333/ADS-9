// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);

    std::string word;
    BST<std::string> tree;

    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }

    while (file >> word) {
        int i = 0;

        while (i < word.length()) {
            if (word[i] == '\'')
                word.erase(i);
            else if (!isalpha(word[i]))
                word.erase(i, 1);
            else
                i++;
        }
        for (i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }
        if (!word.empty())
            tree.insert(word);
    }

    file.close();

    return tree;
}
