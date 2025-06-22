#include <iostream>
using namespace std;

const int TABLE_SIZE = 200;
const int WORD_LEN = 3; // 2 chars + null terminator

char hashTable[TABLE_SIZE][WORD_LEN];
int status[TABLE_SIZE]; // 0=empty, 1=occupied, 2=tombstone

int hashFunction(const char word[]) {
    int hash = 0;
    int p = 31;
    int power = 1;
    
    for (int i = 0; word[i] != '\0'; i++) {
        hash = (hash + word[i] * power) % TABLE_SIZE;
        power = (power * p) % TABLE_SIZE;
    }
    return hash;
}

void insert(const char word[]) {
    int index = hashFunction(word);
    int original = index;
    
    while (true) {
        if (status[index] != 1) { 
            int i = 0;
            while (i < WORD_LEN) {
                hashTable[index][i] = word[i];
                if (word[i] == '\0') break;
                i++;
            }
            status[index] = 1; 
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == original) break;
    }
    cout << "Table full. Cannot insert: " << word << endl;
}

bool search(const char word[]) {
    int index = hashFunction(word);
    int original = index;
    
    while (true) {
        if (status[index] == 0) return false; 
        
        if (status[index] == 1) { 
            bool match = true;
            int i = 0;
            while (i < WORD_LEN) {
                if (hashTable[index][i] != word[i]) {
                    match = false;
                    break;
                }
                if (word[i] == '\0') break;
                i++;
            }
            if (match) return true;
        }
        
        index = (index + 1) % TABLE_SIZE;
        if (index == original) break;
    }
    return false;
}

void deleteWord(const char word[]) {
    int index = hashFunction(word);
    int original = index;
    
    while (true) {
        if (status[index] == 0) return;
        
        if (status[index] == 1) { // Occupied slot
            bool match = true;
            int i = 0;
            while (i < WORD_LEN) {
                if (hashTable[index][i] != word[i]) {
                    match = false;
                    break;
                }
                if (word[i] == '\0') break;
                i++;
            }
            if (match) {
                status[index] = 2; // Mark as tombstone
                return;
            }
        }
        
        index = (index + 1) % TABLE_SIZE;
        if (index == original) break;
    }
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (status[i] == 1) {
            cout << "Index " << i << ": " << hashTable[i] << endl;
        } else if (status[i] == 2) {
            cout << "Index " << i << ": " << "<tombstone>" << endl;
        }
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        status[i] = 0;
    }

    insert("ab");
    insert("bc");
    insert("cd");
    insert("de");
    
        cout << "After insertion:\n";
    display();
    
        cout << "\nSearch 'bc': " << (search("bc") ? "Found" : "Not found") << endl;
        cout << "Search 'xy': " << (search("xy") ? "Found" : "Not found") << endl;
        
    deleteWord("bc");
        cout << "\nAfter deleting 'bc':\n";
    display();

    insert("zz");
        cout << "\nAfter inserting 'ef':\n";
    display();
    
    return 0;
}