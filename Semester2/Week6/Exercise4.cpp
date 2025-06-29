#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string text = "the quick brown fox jumps over the lazy dog the fox";
    unordered_map<string, int> freq;
    string word = "";

    // Go through each character in the text
    for (int i = 0; i <= text.length(); i++) {
        // When a space or end of text is found, count the word
        if (i == text.length() || text[i] == ' ') {
            if (word != "") {
                freq[word]++;
                word = "";
            }
        } else {
            word += text[i];
        }
    }

    // Print words that appear more than once
    cout << "Words that appear more than once:\n";
    for (auto w : freq) {
        if (w.second > 1)
            cout << w.first << ": " << w.second << endl;
    }

    // Find the word with the highest frequency
    string mostWord = "";
    int maxCount = 0;
    for (auto w : freq) {
        if (w.second > maxCount) {
            maxCount = w.second;
            mostWord = w.first;
        }
    }
    cout << "Most frequent word: " << mostWord << " (" << maxCount << " times)" << endl;

    return 0;
}
