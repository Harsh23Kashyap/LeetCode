class Solution {
public:
    static bool sortlexo(string a,string b)
    {
        string ab=a+b;
        string ba=b+a;
        if(ab>ba)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) 
    {
        string ans;
        vector<string> v;
        for(int i:nums)
            v.push_back(to_string(i));
        sort(v.begin(),v.end(),sortlexo);
        if(v[0]=="0")
            return "0";
        for(string a:v)
            ans+=a;
        return ans;
        
    }
};