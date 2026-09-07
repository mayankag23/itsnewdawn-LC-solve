class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9+7;

        vector<int> last_added(26,0);
        int total =0;
        for(auto c :s){
            int idx = c-'a';
            long prev = last_added[idx];
            long curr = (total+1)%MOD;
            total = (total+curr-prev+MOD)%MOD;
            last_added[idx]=curr;
        }
        return total;        
    }
};