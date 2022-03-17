class Solution {
public:
    string getTheFinalAns(string num, int k){
        while(k--){
            int i = num.size()-1;
            while(i >= 0){
                if(num[i] > num[i-1]){
                    char temp = num[i-1];
                    char next_gr = num[i];
                    int pos = i;
                    for(int j=i; j<num.size(); j++){
                        if(num[j] < next_gr && num[j] > temp){
                            next_gr = num[j];
                            pos = j;
                        }
                    }
                    num[i-1] = next_gr;
                    num[pos] = temp;
                    sort(num.begin()+i, num.end());
                    break;
                }
                i--;
            }
        }
        return num;
    }
    
    int getMinSwaps(string num, int k) {
        int ans = 0;
        string updated = getTheFinalAns(num, k);
        int i = 0;
        while(i < num.size()){
            if(num[i] != updated[i]){
                int j = i+1;
                while(updated[j] != num[i]){
                    j++;
                }
                for(; j>i; j--){
                    swap(updated[j], updated[j-1]);
                    ans++;
                }
            }
            i++;
        }
        // cout << updated << " " << num;
        return ans;
    }
};