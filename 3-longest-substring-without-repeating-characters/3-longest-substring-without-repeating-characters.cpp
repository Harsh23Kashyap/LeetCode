class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> u;
        for(char ch:s)
            u[ch]=0;
        int left=0,right=0;
        int best=0;
        while(right<s.length())
        {
            if(u[s[right]]==0)
               {
                   u[s[right]]++;
               right++;
                   
               }
               else
               {
                   u[s[left]]--;
                   left++;
                   
               }
             best=max(best,right-left);
               
        }
               return best;
        
    }
};