class Solution {
private:
    // Helper function 
    int dateToDay(string s) {
        vector<int> m = {31,28,31,30,31,30,31,31,30,31,30,31};
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));
        
        int totalDays = day;
        for (int i = 0; i < month - 1; i++) {
            totalDays += m[i];
        }
        return totalDays;
    }

public:

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Call the standard helper function 
        int l = max(dateToDay(arriveAlice), dateToDay(arriveBob));
        int r = min(dateToDay(leaveAlice), dateToDay(leaveBob));
        
        return max(0, r - l + 1);
    }
};
