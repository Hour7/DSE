#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    
    l.push_front(10);
    l.push_back(20);
    l.push_back(30);
    
    cout << "Front element: " << l.front() << endl;
    cout << "Back element: " << l.back() << endl;
    
    l.pop_front();
    cout << "Front element after pop_front: " << l.front() << endl;
    
    l.pop_back();
    cout << "Back element after pop_back: " << l.back() << endl;
    
    cout << "List size: " << l.size() << endl;
    
    
    cout << "Is list empty? " << (l.empty() ? "Yes" : "No") << endl;
    
    return 0;
}
