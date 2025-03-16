#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cout << word1 << " and " << word2 << ": " << msg << endl;
}


// compares words to see if they are neighbors
bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    if (max(str1.length(), str2.length()) - min(str1.length(), str2.length()) > d) return false;

    int letter_dif = 0;
    int i = 0, j = 0;

    while ((i < str1.length()) && (j < str2.length())) {
        if (str1[i] != str2[j]) {
            letter_dif++;
            
            if (str1.length() > str2.length()) i++;
            else if (str1.length() < str2.length()) j++;
            else {
                i++;
                j++;
            }
        }
        else {
            i++;
            j++;
        }
    }
    return letter_dif == d;
}

// examines ladders that are one step away from original word
// returns true if two words are neighbors (word differs by exactly one letter)
bool is_adjacent(const string& word1, const string& word2)
{
    return edit_distance_within(word1, word2, 1);
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

void load_words(set<string> & word_list, const string& file_name)
{
    ifstream file(file_name);
    if (file.is_open()) {
        string line;
        while (getline(file, line))
            word_list.insert(line);
        file.close();
    }
    cout << "Unable to open file" << endl;
}

void print_word_ladder(const vector<string>& ladder)
{
    for (string w : ladder)
        cout << w << " -> ";
    cout << endl;
}

void verify_word_ladder();
