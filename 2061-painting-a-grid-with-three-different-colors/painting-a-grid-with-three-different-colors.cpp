class Solution {
public:
    int MOD = 1e9 + 7;

    unordered_map<string, vector<string>> compat;

    void genStates(vector<string>& states, string& res, int n){
        if(res.size() == n){
            states.push_back(res);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!res.empty() && res.back() == ch) 
                continue;
            res.push_back(ch);
            genStates(states, res, n);
            res.pop_back();
        }
    }

    bool compatible(const string& a, const string& b){
        for(int i = 0; i < a.size(); i++){
            if(a[i] == b[i]) 
                return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        if (n > m) 
            return colorTheGrid(n, m);
        vector<string> states;
        string temp;
        genStates(states, temp, n);

        for(int i = 0; i < states.size(); i++){
            for(int j = 0; j < states.size(); j++){
                if(compatible(states[i], states[j])){
                    compat[states[i]].push_back(states[j]);
                }
            }
        }

        unordered_map<string, long long> prevdp, currdp;

        for(auto& s : states)
            prevdp[s] = 1;
        

        // build row by row
        for(int row = 1; row < m; row++){
            unordered_map<string, long long>  currdp;
            for(auto s : states){
                long long ways = 0;
                for(auto p : compat[s]){
                    ways = (ways + prevdp[p]) % MOD;
                }
                currdp[s] = ways;
            }
            prevdp=currdp;
        }

        long long ans = 0;
        for(auto it : prevdp){
            ans = (ans + it.second) % MOD;
        }
        return ans;
    }
};
