#include <iostream>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;

        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* head = nullptr;

public:
    ~LinkedList() {
        clear();
    }

    void pushFront(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void pushBack(int value) {
        Node* node = new Node(value);

        if (head == nullptr) {
            head = node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }

    bool remove(int value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            return false;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        return true;
    }

    bool empty() const {
        return head == nullptr;
    }

    void display() const {
        const Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << " -> nullptr\n";
    }

    void clear() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
};

int main() {
    LinkedList list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(5);
    list.display(); // 5 -> 10 -> 20 -> nullptr

    list.remove(10);
    list.display(); // 5 -> 20 -> nullptr

    return 0;
}