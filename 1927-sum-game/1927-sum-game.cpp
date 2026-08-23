class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum1 =0, sum2 =0;
        int cnt1 =0, cnt2 =0;
        for(int i = 0; i < n/2; i++){
            if(num[i] == '?') cnt1 ++;
            else sum1 += num[i]-'0';
            if(num[n-i-1] == '?') cnt2++;
            else sum2 += num[n-i-1]-'0';
        }
        int diff = sum1-sum2;
        int qdiff = cnt1-cnt2;
        if(qdiff == 0){
            return diff != 0;
        }

        return 2 * (sum1 - sum2) != 9 * (cnt2 - cnt1);        
        
    }
};