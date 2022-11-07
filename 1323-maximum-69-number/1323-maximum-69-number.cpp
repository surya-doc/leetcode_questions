class Solution {
public:
    
    string intToStr(int num){
        string temp = "";
        while(num){
            temp += to_string(num%10);
            num /= 10;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    
    int maximum69Number (int num) {
        string strNum = intToStr(num);
        for(int i=0; i<strNum.size(); i++){
            if(strNum[i] == '6'){
                strNum[i] = '9';
                num = stoi(strNum);
                return num;
            }
        }
        return num;
    }
};