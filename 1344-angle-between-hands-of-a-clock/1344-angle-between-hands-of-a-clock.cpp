class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = 0,b =0;
        a+=30.0*hour;
        a+=(1.0/2.0)*1.0*minutes;
        b+=6.0*minutes*1.0;
        return min(abs(b-a),360-abs(b-a));
    }
};