class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101,0);
        int offset =1950;

        for(auto it : logs){
            diff[it[0]-offset]++;
            diff[it[1]-offset]--;
        }
        int maxpop= 0;
        int currpop =0;
        int maxyear = offset;
        for(int i= 0; i<101;i++){
            currpop = currpop + diff[i];
            if(currpop > maxpop){
                maxpop = currpop;
                maxyear = offset+ i;
            }
        }
        return maxyear;
    }
};