class Solution {
public:
    int minPartitions(string n) {
        int max_val = 0;
        int i = n.size()-1;
        while(i >= 0){
            string a = "";
            a += n[i];
            max_val = max(max_val, stoi(a));
            i--;
        }
        return max_val;
    }
};