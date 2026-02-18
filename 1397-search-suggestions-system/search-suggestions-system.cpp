class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
                sort(products.begin(), products.end());
        vector<vector<string>> result;
        int l = 0, r = products.size() - 1;
        for (int i = 0; i < searchWord.length(); i++) {
            char c = searchWord[i];
            while (l <= r && (products[l].length() <= i || products[l][i] < c)) l++;
            while (l <= r && (products[r].length() <= i || products[r][i] > c)) r--;
            vector<string> suggestion;
            for (int j = l; j < min(l + 3, r + 1); j++) {
                suggestion.push_back(products[j]);
            }
            result.push_back(suggestion);
        }
        return result; 
    }
};