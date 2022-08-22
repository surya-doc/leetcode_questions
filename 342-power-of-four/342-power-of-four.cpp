class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)return false;
        int no_of_one = 0,pos = 1,one_pos = 0;
        while(n){
            if(n&1)no_of_one+=1,one_pos = pos;
            n>>=1,pos+=1;
        }
        return no_of_one==1&&one_pos&1;
    }
};