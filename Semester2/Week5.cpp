#include <iostream>
using namespace std;

const int TABLE_SIZE = 200;
const int R = 197;  // prime less than TABLE_SIZE
const int P = 31;   // base for multiply powers

// Convert 2-char word to a number using simple polynomial hash
int multiplyPowers(const char* word) {
    int num = 0;
    int power = 1;
    for (int i = 1; i >= 0; --i) {
        num += word[i] * power;
        power *= P;
    }
    return num % 10007;  // modulus to keep number small
}

// First hash function: simple modulo
int h1(int key) {
    return key % TABLE_SIZE;
}

// Second hash function for double hashing
int h2(int key) {
    return R - (key % R);
}

// Double hashing: combines h1 and h2 with iteration i
int doubleHash(int key, int i) {
    return (h1(key) + i * h2(key)) % TABLE_SIZE;
}

// Check if the slot is empty (empty string means first char is '\0')
bool isEmpty(const char* str) {
    return str[0] == '\0';
}

// Copy 2-character word manually to hash table slot
void copyWord(char* dest, const char* src) {
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = '\0';  // null terminator
}

// Insert a word into the hash table using double hashing
bool insertWord(char hashTable[][3], const char* word) {
    int key = multiplyPowers(word);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = doubleHash(key, i);
        if (isEmpty(hashTable[idx])) {
            copyWord(hashTable[idx], word);
            return true;  // inserted successfully
        }
    }
    return false; // table is full
}

int main() {
    // Initialize hash table with empty strings
    char hashTable[TABLE_SIZE][3];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i][0] = '\0';  // mark as empty
    }

    // Example 2-letter words to insert
    const char* words[] = { "ak", "ck", "ck", "ek", "fk", "gk", "hk", "ik", "jk" };

    // Insert each word into the table
    for (int i = 0; i < 9; i++) {
        if (!insertWord(hashTable, words[i])) {
            cout << "Failed to insert: " << words[i] << endl;
        }
    }

    // Print all filled slots in the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!isEmpty(hashTable[i])) {
            cout << i << ": " << hashTable[i] << endl;
        }
    }

    return 0;
}
