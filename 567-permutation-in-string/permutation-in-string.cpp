class Solution {
public:
bool isContained(const unordered_map<char, int>& a,
                 const unordered_map<char, int>& b) {

    for (auto& [ch, freq] : a) {
        if (b.find(ch) == b.end() || b.at(ch) < freq) {
            return false;
        }
    }
    return true;
}

    bool checkInclusion(string s, string s2) {
        if(s2.size()<s.size())
        return false;
        int k=s.size();
      unordered_map<char, int> mp;
       unordered_map<char, int> mp2;
        for (int i = 0; i < k && i < s.size(); i++) {
            mp[s[i]]++;
            mp2[s2[i]]++;
        }
       if(isContained(mp,mp2))
       return true;

       for(int i=k;i<s2.size();i++){
        mp2[s2[i]]++;
        mp2[s2[i-k]]--;
        if(isContained(mp,mp2))
       return true;
       }
       return false;
        }
};