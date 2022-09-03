class Solution {
public:
   int ans;
    void backtrack(int pos, vector<int>& cookies, vector<int>& buckets, int maxx)
    {
        if(pos == cookies.size())
        {
            ans = min(ans, maxx);
            return;
        }
        for(int b = 0; b < buckets.size(); b++)
        {
            buckets[b] += cookies[pos];
            backtrack(pos + 1, cookies, buckets, max(maxx, buckets[b]));
            buckets[b] -= cookies[pos];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        ans = INT_MAX;
        vector<int> buckets(k, 0);
        backtrack(0, cookies, buckets, 0);
        return ans;
    }
};