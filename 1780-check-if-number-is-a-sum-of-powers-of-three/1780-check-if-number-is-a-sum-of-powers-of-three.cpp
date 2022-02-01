class Solution {
public:
    bool checkPowersOfThree(int n) {
        int arr[15] = {};
        int a = 0;
        while(n){
            if(n%3 == 0){
                n = n/3;
                a++;
            }
            else if(n%3 == 1){
                n--;
                arr[a]++;
                if(arr[a] >= 2) return false;
            }
            else return false;
        }
        return true;
    }
};