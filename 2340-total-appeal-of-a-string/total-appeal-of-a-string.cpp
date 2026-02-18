class Solution {
public:
    long long appealSum(string s) {
        //interesting question/
        // When problem says "sum over all substrings",
// think CONTRIBUTION.
// Count how many substrings each element is responsible for,
// instead of generating substrings.
//basic counting in all substring is for j is (i+1)*(n-i)
// For each index j:
// contribution = (j - lastSeen[char]) * (n - j)
// because this occurrence is the FIRST appearance
// in those substrings.

unordered_map<char,int> u;

long long res=0;

for(int i=0;i<s.size();i++){
    long long j=i+1;
    if(u.find(s[i])!=u.end())
        j=i-u[s[i]];
    
    res+=j*(s.size()-i);

    u[s[i]]=i;

}
return res;


    }
};