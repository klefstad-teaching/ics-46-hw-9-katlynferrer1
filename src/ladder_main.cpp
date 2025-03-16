#include "ladder.h"

int main() 
{
    string word1, word2;
    cout << "Enter word 1: ";
    cin >> word1;
    cout << "Enter word 2: ";
    cin >> word2;
    if (word1 == word2) {
        error(word1, word2, "words are the same");
        return 0;
    }
    //generate_word_ladder(word1, word2);
}