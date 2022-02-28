class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node *prev;
        Node *next;
        Node(int _val = -1, int _key = -1){
            val = _val;
            key = _key;
            prev = next = NULL;
        }
    };
    unordered_map<int, Node*>mp;
    int size;
    Node* head = new Node();
    Node* tail = new Node();
    void addNode(Node* temp){
        Node* curnt = head->next;
        temp->next = curnt;
        head->next = temp;
        temp->prev = head;
        curnt->prev = temp;
    }
    
    void deleteNode(Node* temp){
        Node* prev_node = temp->prev;
        Node* next_node = temp->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    
    LRUCache(int capacity) {
        mp.clear();
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            int res = temp->val;
            deleteNode(temp);
            mp.erase(key);
            addNode(temp);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            if(temp->val != value){
                temp->val = value;
            }
            deleteNode(temp);
            mp.erase(key);
            addNode(temp);
            mp[key] = head->next;
        }
        else{
            if(mp.size() == size){
                Node* delete_node = tail->prev;
                int dlete_key = delete_node->key;
                deleteNode(delete_node);
                mp.erase(dlete_key);
            }
            Node* temp = new Node(value, key);
            addNode(temp);
            mp[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */