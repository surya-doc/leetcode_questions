class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        while(q.size() > 1){
            int num = k;
            while(num > 1){
                int tem_tp = q.front();
                q.pop();
                q.push(tem_tp);
                num--;
            }
            q.pop();
        }
        return q.front();
    }
};