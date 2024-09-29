class AllOne {
private:
    struct ListNode {
        int count;  
        unordered_set<string> keys; 
        ListNode *prev, *next;  
        ListNode(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    unordered_map<string, int> keyCount;  
    unordered_map<int, ListNode*> countNode; 
    ListNode* head; 
    ListNode* tail; 

    ListNode* addNodeAfter(ListNode* node, int count) {
        ListNode* newNode = new ListNode(count);
        newNode->next = node->next;
        newNode->prev = node;
        if (node->next) {
            node->next->prev = newNode;
        } else {
            tail = newNode;
        }
        node->next = newNode;
        countNode[count] = newNode;
        return newNode;
    }

    void removeNode(ListNode* node) {
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        countNode.erase(node->count);
        delete node;
    }

public:
    AllOne() {
        head = new ListNode(0); 
        tail = head;  
    }
    void inc(string key) {
        int currentCount = keyCount[key];
        int newCount = currentCount + 1;
        keyCount[key] = newCount;

        ListNode* currentNode = countNode[currentCount];
        ListNode* newNode;

        if (countNode.count(newCount)) {
            newNode = countNode[newCount];
        } else {
            if (currentNode) {
                newNode = addNodeAfter(currentNode, newCount);
            } else {
                newNode = addNodeAfter(head, newCount);
            }
        }

        newNode->keys.insert(key);
        if (currentNode) {
            currentNode->keys.erase(key);
            if (currentNode->keys.empty()) {
                removeNode(currentNode);
            }
        }
    }

    void dec(string key) {
        int currentCount = keyCount[key];
        if (currentCount == 0) return;

        int newCount = currentCount - 1;
        keyCount[key] = newCount;

        ListNode* currentNode = countNode[currentCount];
        ListNode* newNode = nullptr;

        if (newCount == 0) {
            keyCount.erase(key);
        } else if (countNode.count(newCount)) {
            newNode = countNode[newCount];
        } else {
            newNode = addNodeAfter(currentNode->prev, newCount);
        }

        if (newNode) {
            newNode->keys.insert(key);
        }
        currentNode->keys.erase(key);
        if (currentNode->keys.empty()) {
            removeNode(currentNode);
        }
    }

    string getMaxKey() {
        if (tail == head) return ""; 
        return *(tail->keys.begin());  
    }

    string getMinKey() {
        if (head->next == nullptr) return "";  
        return *(head->next->keys.begin()); 
    }
};
