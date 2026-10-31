class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> result;
        int left = 0;
        int right = products.size()-1;

        for(int i=0;i< searchWord.size(); i++){
            char c= searchWord[i];

            while(left <= right && (products[left].size() <= i || products[left][i] != c)){
                left++;
            }
            while (left <= right && (products[right].size() <= i || products[right][i] != c)) {
                right--;
            }

            vector<string> suggestions;
            for (int j = left; j < min(left + 3, right + 1); j++) {
                suggestions.push_back(products[j]);
            }

            result.push_back(suggestions);
        }
        return result;
    }
};