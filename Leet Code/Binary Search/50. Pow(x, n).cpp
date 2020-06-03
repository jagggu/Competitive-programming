/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]

*/


#define ll long long int

class Solution {
public:
    double myPow(double x, int n) {
        
        double base = abs(x);
        long long int power = abs(n);
        
        double ans = 1;
        //cout<<"Power: "<<power<<endl;
        while(power>0) {
            //cout<<"checkPoint2"<<endl;
            if(power&1) {
                ans = ans * base;
                //cout<<ans<<endl;
                power--;
            } else {
                base = base*base;
                power/=2;
            }
        }
        int tmp = abs(n);
        if(x<0 && tmp&1) {
            //cout<<"checkPoint"<<endl;
            ans = -1*ans;
        }
        
        double res = ans;
        if(n<0) {
           // cout<<"Ans: "<<ans<<endl;
            res = 1.0/ans;
            //cout<<"Res: "<<res<<endl;
        } 
        
        return res;
        
        
        
    }
};