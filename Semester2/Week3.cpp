#include <iostream>
using namespace std;

const int TABLE_SIZE = 200;
const int WORD_LEN = 3;

char hashTable[TABLE_SIZE][WORD_LEN];
bool occupied[TABLE_SIZE] = {false};

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
        if (!occupied[index]) {
            int i = 0;
            while (i < WORD_LEN) {
                hashTable[index][i] = word[i];
                if (word[i] == '\0') break;
                i++;
            }
            occupied[index] = true;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == original) break;
    }
    
    cout << "Table full. Can't insert: " << word << endl;
}

bool search(const char word[]) {
    int index = hashFunction(word);
    int original = index;
    
    while (true) {
        if (!occupied[index]) return false;
        
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
        
        index = (index + 1) % TABLE_SIZE;
        if (index == original) break;
    }
    
    return false;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!occupied[i]) continue;
        
        cout << "Index " << i << ": " << hashTable[i] << endl;
    }
}

int main() {
    insert("ka");
    insert("ak");
    insert("zk");
    insert("ab");
    insert("bc");
    insert("cd");

    cout << "Hash Table Contents:\n";
    display();

    cout << "\nSearch Results:\n";
    cout << "'ak': ";
    if (search("ak")){
        cout << "Found\n";
    } else cout << "Not found\n";
    
    cout << "'zz': ";
    if (search("zz")){
        cout << "Found\n";
    } else cout << "Not found\n"; 

    return 0;
}