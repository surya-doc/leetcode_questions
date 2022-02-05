class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int siz = deck.size();
        deque<int>dq;
        vector<int>ans(siz);
        sort(deck.begin(), deck.end());
        for(int i=0; i<siz; i++){
            dq.push_back(i);
        }
        int i = 0;
        while(dq.size() > 0){
            ans[dq.front()] = deck[i++];
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};