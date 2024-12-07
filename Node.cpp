#include <iostream>
using namespace std;
struct Node {
    string val;                             //значение узла
    Node *next;                             //адрес следующего узла
    Node (string _val): val(_val), next(nullptr) {}
};

struct list {
    Node *first;                           //адрес последнего узла
    list (): first(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void add(string _val) {
        Node* p = new Node(_val);           //новый узел, его адрес — p   
        if (is_empty()) {
            first = p;
            return;
        }
        Node* elem = first;
        while (elem->next){
            elem = elem->next;
        }
        elem->next = p;
    }

    void print() {
        if (is_empty()) return;
        Node *p = first;
        while (p) {                         // p != nullptr
            cout << (*p).val << " | ";      //распаковываем последний узел, печатаем значение
            p = (*p).next;
        }
        cout << endl;
    }

    int size() {
        int c = 0;
        Node *p = first;
        while (p) {
            c++;
            p = (*p).next;
        }
        return c;
    }

    Node* find(string _val) {               //возвращает адрес элемента по значению
        if (is_empty()) return nullptr;
        Node *p = first;
        while (p) {
            if ((*p).val == _val) {
                return p;
            }
            p = (*p).next;
        }
        return nullptr;
    }

    void remove(string _val) {
        if (is_empty()) return;
        Node *p = first;
        while (p) {
            Node *nextnode = (*p).next;
            if ((*nextnode).val == _val) {
                (*p).next = (*(nextnode)).next;
                delete nextnode;
                break;
            }
            p = (*p).next;

        }
        return;
    }

    void turn_back() {
        Node *_prev = nullptr;
        Node *p = first;
        while (p) {
            Node *_next = p->next;
            Node *k = _next;
            _next = _prev;
            _prev = k;  //_next

            p->next = _next;
            k = _prev;
            _prev = p;

            if (k == nullptr) {
                first = p;
            }

            p = k;
        }
        
    }

};


int main() {
    list test;
    test.is_empty();
    test.print();

    for (int i = 1; i <= 10; i++) {
        test.add(to_string(i));
    }
    test.print();
    cout << test.size() << endl;

    test.remove("9");
    test.remove("5");
    test.print();
    cout << test.size() << endl;

    Node *elem = test.find("3");
    cout << elem->val << " " << elem->next << endl;

    test.turn_back();
    test.print();
    return 0;
}