#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (!temp) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtPosition(int pos) {
        if (!head) return;
        Node* temp = head;
        if (pos == 0) {
            head = temp->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        for (int i = 0; temp != nullptr && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) return;
        prev->next = temp->next;
        delete temp;
    }

    void insertAtTail(int val) {

        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next!=nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << "Value: " << temp->data << " | Address: " << temp << " | Next: " << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 10; i++) {
        list.insertAtTail(i);
    }
    cout << "Initial List:\n";
    list.printList();
    
    list.insertAtPosition(99, 5);
    cout << "After inserting 99 at position 5:\n";
    list.printList();
    
    list.deleteAtPosition(3);
    cout << "After deleting node at position 3:\n";
    list.printList();
    
    return 0;
}