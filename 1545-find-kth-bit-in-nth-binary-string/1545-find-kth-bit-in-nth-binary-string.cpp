class Solution {
public:
    string invert(string s){
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {
        // char ans = '';
        string s = "0";
        for(int i=0; i<n-1; i++){
            string temp = s;
            string in = invert(temp);
            reverse(in.begin(), in.end());
            s = temp+"1"+in;
        }
        return s[k-1];
    }
};