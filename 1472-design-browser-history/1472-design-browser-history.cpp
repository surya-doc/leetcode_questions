class BrowserHistory {
public:
    stack<string>his;
    stack<string>ford;
    
    BrowserHistory(string homepage) {
        his.push(homepage);
        ford = stack<string>();
    }
    
    void visit(string url) {
        his.push(url);
        ford = stack<string>();
    }
    
    string back(int steps) {
        while(steps>0 && his.size()>1){
            ford.push(his.top());
            his.pop();
            steps--;
        }
        return his.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && ford.size()>0){
            his.push(ford.top());
            ford.pop();
            steps--;
        }
        return his.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */