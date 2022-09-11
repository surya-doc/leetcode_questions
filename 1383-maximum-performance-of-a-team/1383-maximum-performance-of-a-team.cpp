class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {efficiency[i], speed[i]};
        }
        sort(rbegin(arr), rend(arr));
        priority_queue<int, vector<int>, greater<int>> pq;
        long sum = 0;
        long ans = 0;
        for(auto &[a, b]:arr){
            pq.push(b);
            sum += b;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum*a);
        }
        return ans % (int)(1e9+7);
    }
};
// vector<pair<int, int>> ess(n);
//         for (int i = 0; i < n; ++i)
//             ess[i] = {efficiency[i], speed[i]};
//         sort(rbegin(ess), rend(ess));
//         long sumS = 0, res = 0;
//         priority_queue <int, vector<int>, greater<int>> pq; //min heap
//         for(auto& [e, s]: ess){
//             pq.emplace(s);
//             sumS += s;
//             if (pq.size() > k) {
//                 sumS -= pq.top();
//                 pq.pop();
//             }
//             res = max(res, sumS * e);
//         }
//         return res % (int)(1e9+7);