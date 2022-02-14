// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    vector<long long> ans;
    for(int i=0; i<N; i++){
        if(A[i] < 0){
            pq.push({i, A[i]});
        }
    }
    long long int i = 0;
    long long int j = K-1;
    while(pq.size() > 0 && j < N){
        pair<long long, long long>temp = pq.top();
        if(temp.first >= i && temp.first <= j){
            ans.push_back(temp.second);
            i++;
            j++;
        }
        else if(temp.first < i){
            pq.pop();
        }
        else if(temp.first > j){
            ans.push_back(0);
            i++;
            j++;
        }
    }
    if(pq.size() == 0 && j<N){
        while(j<N){
            ans.push_back(0);
            j++;
        }
    }
    // for(int i=0; i<K; i++){
    //     if(pq.top().first >= (i-K-1) && pq.top().first <= i){
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }
    // }
    // for(int i=0; i<N; i++){
    //     if(i >= K-1){
    //         if(pq.top().first >= (i-K-1) && pq.top().first <= i){
    //             ans.push_back(pq.top().second);
    //             pq.pop();
    //         }
    //         else{
    //             ans.push_back(0);
    //         }
    //     }
    // }
    return ans;
 }