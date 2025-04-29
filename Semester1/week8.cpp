#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear;
    int arr[100];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == 100 - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        cout << x << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        int removedElement = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        cout << removedElement << " dequeued from queue." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Get Size of Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                value = q.peek();
                if (value != -1) {
                    cout << "Front element is: " << value << endl;
                }
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Size of the queue is: " << q.size() << endl;
                break;

            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
