#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// Declare the contact book
unordered_map<string, string> contacts;

// Add or update a contact
void addContact(string name, string number) {
    contacts[name] = number;
}

// Delete a contact
void deleteContact(string name) {
    contacts.erase(name);
}

// Search and print a contact
void searchContact(string name) {
    if (contacts.count(name)) {
        cout << name << ": " << contacts[name] << endl;
    } else {
        cout << name << " not found.\n";
    }
}

// Show all contacts
void showAll() {
    for (auto c : contacts) {
        cout << c.first << ": " << c.second << endl;
    }
}

int main() {
    addContact("Dara", "012345678");
    addContact("Bopha", "023456789");
    addContact("Sokha", "034567890");

    searchContact("Dara");

    addContact("Bopha", "098765432"); // Update Bopha's number
    deleteContact("Sokha");

    showAll();

    return 0;
}
