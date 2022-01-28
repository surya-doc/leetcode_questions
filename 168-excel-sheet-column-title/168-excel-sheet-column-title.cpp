class Solution {
public:
    string convertToTitle(int columnNumber) {
        char base = 'A';
        string ans = "";
        int temp = columnNumber;
        while(temp>0){
            temp--;
            int divide = temp%26;
            cout << temp << " ";
            temp = temp/26;
            ans += char(divide+'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};