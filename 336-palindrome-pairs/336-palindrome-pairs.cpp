class Solution {
public:
     bool isPalin(string str, int start, int end)
    {
        while(start < end)
        {
            if(str[start++] != str[end--])
                return false;
        }
        
        return true;
    }
    

    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> res;
        
        int n = words.size();
        
        unordered_map<string, int> mp;
        set<int> st;
        
        // first insert all words with index into hashmap
        for(int i = 0; i < n; i++)
        {
            mp[words[i]] = i;
            st.insert(words[i].size());
        }
        
        
        for(int i = 0; i < n; i++)
        {            
            int len = words[i].size();
            
            // case 1
            if(len == 1)
            {
                if(mp.count("") && mp[""] != i)
                {
                    res.push_back({i, mp[""]});
                    res.push_back({mp[""], i});
                }
                
                continue;
            }
            
                
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            
            // case 2
            if(mp.count(rev) && mp[rev] != i)
            {
                res.push_back({i, mp[rev]});
            }
            
            
            for(auto size : st)
            {
                if(len == size) 
                    break;
                
                // case 3
                if(isPalin(rev, 0, len - 1 - size))
                {
                    string str1 = rev.substr(len-size);
                    if(mp.count(str1))
                    {
                        res.push_back({i, mp[str1]});
                    }
                }
                
                
                // case 4
                if(isPalin(rev, size, len - 1))
                {
                    string str2 = rev.substr(0, size);
                    
                    if(mp.count(str2))
                    {
                        res.push_back({mp[str2], i});
                    }
                }
            }
                
        }
        
        
        return res;
    }
};