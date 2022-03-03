class MinStack {
public:
    class node{
        public:
        node* next;
        node* prev;
        int val;
        node(int _val=-1){
            val = _val;
            next = prev = NULL;
        }
    };
    
    node *head = new node();
    node *tail = new node();
    
    void addElement(int val){
        node *temp = new node(val);
        node *a = head->next;
        head->next = temp;
        temp->next = a;
        a->prev = temp;
        temp->prev = head;
    }
    
    void deleteElement(){
        node *temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
    }
    
    MinStack() {
        head->next = tail;
        tail->prev = head;
    }
    
    void push(int val) {
        addElement(val);
    }
    
    void pop() {
        deleteElement();
    }
    
    int top() {
        return head->next->val;
    }
    
    int getMin() {
        node *temp = head->next;
        int minEle = INT_MAX;
        while(temp->next != NULL){
            minEle = min(temp->val, minEle);
            temp = temp->next;
        }
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */