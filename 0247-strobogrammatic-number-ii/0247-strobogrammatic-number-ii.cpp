class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans = pass(n, n);
        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    vector<string> pass(int curr, int n) {
        const vector<string> res = {"11", "88", "69", "96", "00"};

        if (curr == 1)
            return {"1", "8", "0"};

        if (curr == 2) {
            vector<string> currrres = {"11", "88", "69", "96"};
            if (curr != n)
                currrres.push_back("00");
            return currrres;
        }

        vector<string> check = pass(curr - 2, n);
        vector<string> ans;
        for (const string& side : res) {
            if (curr == n && side == "00")
                continue;
            string first = string(1, side[0]);
            string last = string(1, side[1]);
            for (const string& mid : check)
                ans.push_back(first + mid + last);
        }
        return ans;
    }
};
