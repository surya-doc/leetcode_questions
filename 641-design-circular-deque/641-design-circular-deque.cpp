class MyCircularDeque {
public:
    class node{
        public:
            node *next;
            node *prev;
            int val;
            node(int _val=-1){
                val = _val;
                next = prev = NULL;
            }
    };
    
    int size;
    int cSize = 0;
    node *head = new node();
    node *tail = new node();
    MyCircularDeque(int k) {
        size = k;
        head->next = tail;
        tail->prev = head;
    }
    
    bool insertFront(int value) {
        if(cSize < size){
            node *temp = head->next;
            head->next = new node(value);
            head->next->prev = head;
            head->next->next = temp;
            temp->prev = head->next;
            cSize++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(cSize < size){
            node *temp = tail->prev;
            temp->next = new node(value);
            temp->next->prev = temp;
            temp->next->next = tail;
            tail->prev = temp->next;
            cSize++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(cSize > 0){
            node *temp = head->next;
            head->next = temp->next;
            temp->next->prev = head;
            cSize--;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(cSize > 0){
            node *temp = tail->prev;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            cSize--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(cSize > 0){
            return head->next->val;
        }
        return -1;
    }
    
    int getRear() {
        if(cSize > 0){
            return tail->prev->val;
        }
        return -1;
    }
    
    bool isEmpty() {
        if(cSize == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(cSize == size) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */