#include <unordered_map>

class Node {
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int v) : val(v), key(-1), next(nullptr), prev(nullptr) {}
    Node(int v, int k) : val(v), key(k), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        head = new Node(-1, -1); 
        tail = new Node(-1, -1); 
        head->next = tail;
        tail->prev = head;
    }

    // ~LRUCache() {
    //     // free nodes (including sentinels)
    //     Node* cur = head;
    //     while (cur) {
    //         Node* nx = cur->next;
    //         delete cur;
    //         cur = nx;
    //     }
    // }

    int get(int key) {
        auto it = storage.find(key);
        if (it == storage.end()) {
            return -1;
        }
        Node* node = it->second;

        // move to tail
        if (node->next != tail) { 
            remove(node);
            appendToTail(node);
        }
        return node->val;
    }

    void put(int key, int value) {
        auto it = storage.find(key);
        if (it != storage.end()) {

            // update existing
            Node* node = it->second;
            node->val = value;
            if (node->next != tail) {
                remove(node);
                appendToTail(node);
            }
            return;
        }

        // new key
        if (size >= capacity) {
            // remove LRU 
            Node* lru = head->next;
            storage.erase(lru->key);
            remove(lru);
            
            //update new val
            lru->key = key;
            lru->val = value;
            storage[key] = lru;
            appendToTail(lru);
            
        } else {
            
            Node* node = new Node(value, key);
            storage[key] = node;
            appendToTail(node);
            ++size;
        }
    }

private:
    int capacity;
    int size;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> storage;

    void remove(Node* node) {
        // assumes node is not a sentinel
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = node->next = nullptr;
    }

    void appendToTail(Node* node) {
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }
};