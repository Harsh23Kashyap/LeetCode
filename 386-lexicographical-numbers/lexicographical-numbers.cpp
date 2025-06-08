class Solution {
public:
    static bool cmp(int &a, int& b){
        string s1=to_string(a);
        string s2=to_string(b);
        return s1<s2;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> a(n);
        iota(a.begin(),a.end(),1);
        sort(a.begin(),a.end(),cmp);

        return a;
    }
};