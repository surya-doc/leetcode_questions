class BrowserHistory {
public:
    class node{
        public:
        node* prev;
        node* next;
        string val;
        node(string _val){
            val = _val;
            next = prev = NULL;
        }
    };
    
    node* curnt;
    
    BrowserHistory(string homepage) {
        curnt = new node(homepage);
    }
    
    void visit(string url) {
        node* temp = new node(url);
        curnt->next = temp;
        temp->prev = curnt;
        curnt = curnt->next;
    }
    
    string back(int steps) {
        while(curnt->prev != nullptr && steps>0){
            curnt = curnt->prev;
            steps--;
        }
        return curnt->val;
    }
    
    string forward(int steps) {
        while(curnt->next != nullptr && steps>0){
            curnt = curnt->next;
            steps--;
        }
        return curnt->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */