#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, vector<int>> scores;

    // Add scores for each student
    scores["Dara"] = {85, 90, 88};
    scores["Sokha"] = {92, 95, 89};

    // Calculate and print average scores
    for (auto s : scores) {
        int total = 0;
        for (int num : s.second) total += num;
        cout << s.first << " average: " << total / s.second.size() << endl;
    }

    // Add one more score for Dara
    scores["Dara"].push_back(93);

    // Print how many scores each student has
    for (auto s : scores) {
        cout << s.first << " has " << s.second.size() << " scores.\n";
    }

    return 0;
}
