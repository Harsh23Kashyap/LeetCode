class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) 
    {
        int sum = 0;
        for (int i = 0; i < w.size(); i++) 
        {
            sum += w[i];
            prefix.push_back(sum);
        }
        
    }
    
    int pickIndex() 
    {
        
        int pick = rand()%prefix[prefix.size()-1]+ 1;
        int left = 0;
        int right = prefix.size()- 1;
        int mid;
        int ans;
        while (left <= right) 
        {
            mid = (left + right) / 2;
            
            
            if(prefix[mid] == pick)
                    return mid;
            if(prefix[mid] < pick)
                left = mid + 1;
            else 
            {
                ans = mid;
                right = mid-1;
            }
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */