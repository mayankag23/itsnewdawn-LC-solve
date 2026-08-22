class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro= 1;
        int temp = n;
        while(temp >0){
            sum = sum + temp % 10;
            pro = pro * (temp % 10);
            temp = temp/10;
        }
        int net = sum + pro;
        if(n % net == 0) return true;
        else return false;        
    }
};