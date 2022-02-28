class Solution {
public:
    int getLeftMin(vector<int> &h, int num){
        int i = num;
        if(num == 0) return 0;
        for(; i>=0; i--){
            if(h[i] < h[num]) break;
        }
        return i+1;
    }
    
    int getRightMin(vector<int> &h, int num){
        int i = num;
        if(num == h.size()-1) return h.size()-1;
        for(; i<h.size(); i++){
            if(h[i] < h[num]) break;
        }
        return i-1;
    }
    
    int largestRectangleArea(vector<int>& h) {
        int ans = -1;
        vector<int>l(h.size());
        vector<int>r(h.size());
        stack<int>st_l;
        stack<int>st_r;
        for(int i=0; i<h.size(); i++){
            if(i == 0){
                l[i] = -1;
                st_l.push(0);
            }
            else{
                while(!st_l.empty() && h[st_l.top()] >= h[i]){
                    st_l.pop();
                }
                l[i] = st_l.empty() ? -1 : st_l.top();
                st_l.push(i);
            }
        }
        for(int i=h.size()-1; i>=0; i--){
            if(i == h.size()-1){
                r[i] = h.size();
                st_r.push(h.size()-1);
            }
            else{
                while(!st_r.empty() && h[st_r.top()] >= h[i]){
                    st_r.pop();
                }
                r[i] = st_r.empty() ? h.size() : st_r.top();
                st_r.push(i);
            }
        }
        for(int i=0; i<h.size(); i++){
            int area = 0;
            area = (r[i]-l[i]-1)*h[i];
            ans = max(area, ans);
        }
        return ans;
    }
};