class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int ans = 0;
        for(auto it:piles){
            ans += it;
            pq.push(it);
        }
        for(int i=0; i<k; i++){
            int temp = pq.top();
            pq.pop();
            ans -= temp;
            temp = (temp%2 == 0) ? temp/2 : (temp/2)+1;
            pq.push(temp);
            ans += temp;
        }
        // while(pq.size() > 0){
        //     ans += pq.top();
        //     pq.pop();
        // }
        return ans;
    }
};