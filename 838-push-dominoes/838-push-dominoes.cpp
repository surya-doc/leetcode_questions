class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int R[n];
        int L[n];
        int pointer = 0;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R'){
                pointer = 1;
                R[i] = pointer;
            }
            else if(dominoes[i] == '.'){
                if(pointer != 0){
                    pointer++;
                    R[i] = pointer;
                }
                else{
                    R[i] = pointer;
                }
            }
            else{
                pointer = 0;
                R[i] = pointer;
            }
        }
        pointer = 0;
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L'){
                pointer = 1;
                L[i] = pointer;
            }
            else if(dominoes[i] == '.'){
                if(pointer == 0){
                    L[i] = pointer;
                }
                else{
                    pointer++;
                    L[i] = pointer;
                }
            }
            else{
                pointer = 0;
                L[i] = pointer;
            }
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(R[i] == L[i]){
                ans += '.';
            }
            else if(R[i] == 0 && L[i] != 0){
                ans += 'L';
            }
            else if(R[i] != 0 && L[i] == 0){
                ans += 'R';
            }
            else{
                ans += (R[i] < L[i]) ? 'R' : 'L';
            }
        }
        return ans;
    }
};