class Solution {
public:
    static bool reorder(vector<int> &a, vector<int> &b){
        if(a[1] < b[1] || (a[1] == b[1] && a[2] < b[2])){
            return true;
        }
        return false;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), reorder);
        int n = trips.size();
        int seat_occupy = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>minheap;
        for(int i=0; i<n; i++){
            while(minheap.size() > 0 && minheap.top()[0] <= trips[i][1]){
                seat_occupy -= minheap.top()[1];
                minheap.pop();
            }
            seat_occupy += trips[i][0];
            minheap.push({trips[i][2], trips[i][0]});
            if(seat_occupy > capacity) return false;
        }
        return true;
    }
};