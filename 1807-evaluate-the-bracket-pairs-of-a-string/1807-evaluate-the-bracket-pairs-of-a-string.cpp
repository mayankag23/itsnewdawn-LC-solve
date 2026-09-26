class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for(auto it : knowledge){
            dict[it[0]] = it[1];
        }
        bool addkey = false;
        string key, res;
        for(char c : s){
            if(c == '('){
                addkey = true;
            }
            else if(c== ')'){
                if(dict.count(key) > 0){
                    res += dict[key];
                }
                else{
                    res.push_back('?');
                }
                addkey = false;
                key.clear();
            }
            else if(addkey){
                key.push_back(c);
            }
            else res.push_back(c);
        }
        return res;
    }
};