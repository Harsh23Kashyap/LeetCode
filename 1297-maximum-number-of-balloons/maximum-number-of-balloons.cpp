class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26,0);
        for(auto it:text)
            freq[it-'a']++;
        
        int times=freq['b'-'a'];
        times=min(freq['a'-'a'],times);
        times=min(freq['l'-'a']/2,times);
        times=min(freq['o'-'a']/2,times);
        times=min(freq['n'-'a'],times);

        return times;
    }
};