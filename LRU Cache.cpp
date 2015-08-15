#include <iostream>
#include <map>
#include <string.h>
using namespace std;

struct Node {
    int value;
    int key;
    Node *next;
    Node *prev;
    Node() {
        next = NULL;
        prev = NULL;
    }
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = new Node;
        this->tail = new Node;
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->key_map.clear();
    }

    int get(int key) {
        if (key_map.find(key) == key_map.end()) {
            return -1;
        }
        else {
            Node *node = key_map[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;

            return node->value;
        }
    }

    void set(int key, int value) {
        if (key_map.find(key) == key_map.end()) {
            Node *new_node = new Node;
            new_node->value = value;
            new_node->key = key;

            new_node->next = head->next;
            head->next->prev = new_node;
            head->next = new_node;
            new_node->prev = head;

            key_map[key] = new_node;

            if (size < capacity) {
                size += 1;
            } else {
                Node *del_node = tail->prev;
                tail->prev = del_node->prev;
                del_node->prev->next = tail;

                int key_tmp = del_node->key;
                key_map.erase(key_tmp);
                delete del_node;
            }
        } else {
            Node *node = key_map[key];
            node->value = value;

            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;
        }
    }
private:
    int size;
    int capacity;
    Node *head;
    Node *tail;
    map<int, Node *> key_map;
};

int main() {
    LRUCache lru(3);
    lru.set(1, 1);
    lru.set(2, 2);
    lru.set(3, 3);

    cout << lru.get(1) << endl;
    lru.set(4, 4);
    cout << lru.get(4) << endl;
}
