class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();

        for (int len = lowLen; len <= highLen; len++) 
        {
            for (int start = 1; start <= 10 - len; start++) {
                int num = 0;
                int digit = start;

                for (int i = 0; i < len; i++) {
                    num = num * 10 + digit;
                    digit++;
                }

                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};
