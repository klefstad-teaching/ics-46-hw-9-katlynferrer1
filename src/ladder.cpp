#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cout << word1 << " and " << word2 << ": " << msg << endl;
}


// compares words to see if they are neighbors
// bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
// {

// }

// examines ladders that are one step away from original word
// returns true if two words are neighbors (word differs by exactly one letter)
bool is_adjacent(const string& word1, const string& word2)
{
    return true;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited; 
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (string word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);

                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    error(begin_word, end_word, "no ladder found");
    return {};
}

// void load_words(set<string> & word_list, const string& file_name);

// void print_word_ladder(const vector<string>& ladder);
// void verify_word_ladder();
