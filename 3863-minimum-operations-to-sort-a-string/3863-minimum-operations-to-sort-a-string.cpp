class Solution {
public:
    bool check(vector<int> nums){
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }

    int minOperations(string s) {
        int n = s.size();
        vector<int> vec;
        for(char c : s){
            vec.push_back(c - 'a');
        }

        if(check(vec)) return 0;  // alr sorted
        if(n ==2 && check(vec) != true) return -1; //only 2 elements but not in sorted order
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i =0; i < n; i++){
            if(mini > vec[i]) mini = vec[i];
            if(maxi < vec[i]) maxi = vec[i];
        }

        if(mini == vec[0] || maxi == vec[n-1]) return 1; // if mini is at begin or maxi is at end
        
        for(int i = 1; i<n-1; i++){
            if(mini == vec[i]) return 2;
            if(maxi == vec[i]) return 2;
        }
        
        return 3;
        // // edge cases
        // if(check(vec) == true || n==1) return 0;
        // if(n == 2 && check(vec) != true) return -1;
        
        // vector<int> prev(vec.begin(), vec.end()-1);   // 0 to n-2
        // vector<int> next(vec.begin()+1, vec.end());   // 1 to n-1
        
        // // do sort from 0 to n-2, add cost 1 and check
        // sort(prev.begin(), prev.end());
        // prev.push_back(vec[n-1]);
        // if(check(prev)) return 1;
        
        // // do sort from 1 to n-2, add cost 1 and check
        // sort(next.begin(), next.end());
        // next.insert(next.begin(), vec[0]);
        // if(check(next)) return 1;

        // // check if vec is in decreasing order
        // vector<int> rev_vec = vec;
        // reverse(rev_vec.begin(), rev_vec.end());
        // if(check(rev_vec)) return 3;
        
        // return 2;
    }
};