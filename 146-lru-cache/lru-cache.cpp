class LRUCache {
public:

    struct Node {

        int key;
        int val;

        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    int cap;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // delete node from DLL
    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // add node right after head
    void addNode(Node* node) {

        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {

        // key not present
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // move to front (MRU)
        deleteNode(node);
        addNode(node);

        return node->val;
    }

    void put(int key, int value) {

        // key already exists
        if(mp.find(key) != mp.end()) {

            Node* existingNode = mp[key];

            // remove old node
            deleteNode(existingNode);

            // update value
            existingNode->val = value;

            // move to front
            addNode(existingNode);

            return;
        }

        // create new node
        Node* newNode = new Node(key, value);

        // add to map
        mp[key] = newNode;

        // add to front
        addNode(newNode);

        // capacity exceeded
        if(mp.size() > cap) {

            Node* lru = tail->prev;

            // remove from map
            mp.erase(lru->key);

            // remove from DLL
            deleteNode(lru);
        }
    }
};