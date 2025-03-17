#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cout << word1 << " and " << word2 << ": " << msg << endl;
}


// compares words to see if they are neighbors
bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int l1 = str1.length();
    int l2 = str2.length();
    if (abs(l1 - l2)) return false;

    int i = 0, j = 0;
    int letter_dif = 0;

    while (i < l1 && j < l2) {
        if (str1[i] != str2[j]) {
            letter_dif++;
            
            if (letter_dif > d) return false;

            if (l1 > l2) i++;
            else if (l1 < l2) j++;
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
    if (i < l1 || j < l2) letter_dif++;
    return letter_dif <= d;
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
                        //print_word_ladder(new_ladder);
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
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
    else {
        cout << "Unable to open file" << endl;
    }
}

void print_word_ladder(const vector<string>& ladder)
{
    if (ladder.empty()) {
        cout << "No ladder found" << endl;
        return;
    }

    for (const auto w : ladder)
        cout << w << " ";
    cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? "passed": "failed") << endl;}
void verify_word_ladder()
{
    set<string> word_list;
    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}
