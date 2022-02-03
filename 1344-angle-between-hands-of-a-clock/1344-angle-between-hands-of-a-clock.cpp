class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = 0;
        double total_hr = (hour%12)+double(1)/(double(60)/double(minutes));
        cout << total_hr;
        
        double mx_val = (total_hr*30)>(minutes*6) ? (total_hr*30) : (double(minutes)*6);
        double mn_val = (total_hr*30)<(minutes*6) ? (total_hr*30) : (double(minutes)*6);
        cout << mx_val << mn_val;
        return (mx_val-mn_val) > 180.0 ? 360.0-(mx_val-mn_val) : (mx_val-mn_val);
    }
};