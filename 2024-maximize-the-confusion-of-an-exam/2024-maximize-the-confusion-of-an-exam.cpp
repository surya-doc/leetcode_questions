class Solution {
public:
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        //find maximum length sub string of T containing k number of F
        int j=0, i=0;
        int count = 0;
        int temp_count = 0;
        int n = answerKey.length();
        int k1 = 0;
        
        for(; j<n; j++){
            if(answerKey[j] == 'F'){
                if(k1 < k){
                    k1++;
                }
                else{
                    while(k1>=k){
                        if(answerKey[i] == 'F') k1--;
                        i++;
                    }
                    k1++;
                }
            }
            count = max(count, j-i+1);
        }
        //find maximum length sub string of F containing k number of T
        i=0, j=0;
        int count_for_f = 0;
        int temp_count_f = 0;
        k1 = 0;
        
        for(; j<n; j++){
            if(answerKey[j] == 'T'){
                if(k1 < k){
                    k1++;
                }
                else{
                    while(k1>=k){
                        if(answerKey[i] == 'T') k1--;
                        i++;
                    }
                    k1++;
                }
            }
            count_for_f = max(count_for_f, j-i+1);
        }
        return max(count, count_for_f);
    }
};