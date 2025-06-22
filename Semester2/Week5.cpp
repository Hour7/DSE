#include <iostream>

using namespace std;

const int TABLE_SIZE = 200;
const int R = 197;  // A prime less than TABLE_SIZE
const int P = 31;   // Base for Multiply Powers method

// Function to convert a 2-character word to a number
int multiplyPowers(const char* word, int modulus = 10007) {
    int num = 0;
    int power = 1;
    for (int i = 1; i >= 0; --i) {
        num += word[i] * power;
        power *= P;
    }
    return num % modulus;
}

// Hash functions
int h1(int key) {
    return key % TABLE_SIZE;
}

int h2(int key) {
    return R - (key % R);
}

int doubleHash(int key, int i) {
    return (h1(key) + i * h2(key)) % TABLE_SIZE;
}

// Function to copy one C-string to another (manual strcpy)
void myStrcpy(char* dest, const char* src) {
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = '\0';
}

// Function to check if a C-string is empty
bool isEmpty(const char* str) {
    return str[0] == '\0';
}

// Insert word into the hash table
bool insertWord(char hashTable[][3], const char* word) {
    int key = multiplyPowers(word);
    for (int i = 0; i < TABLE_SIZE; ++i) {
        int index = doubleHash(key, i);
        if (isEmpty(hashTable[index])) {
            myStrcpy(hashTable[index], word);
            return true;
        }
    }
    return false; // Table full
}  

int main() {
    // Initialize hash table
    char hashTable[TABLE_SIZE][3];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable[i][0] = '\0';
    }

    // Sample words (you can expand this list up to 80)
    const char* words[10] = {
        "ak", "ck", "ck", "ck", "ek",
        "fk", "gk", "hk", "ik", "jk"
    };

    // Insert words into the table
    for (int i = 0; i < 10; ++i) {
        if (!insertWord(hashTable, words[i])) {
            cout << "Failed to insert: " << words[i] << endl;
        }
    }

    // Display the hash table
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (!isEmpty(hashTable[i])) {
            cout << i << ": " << hashTable[i] << endl;
        }
    }

    return 0;
}
