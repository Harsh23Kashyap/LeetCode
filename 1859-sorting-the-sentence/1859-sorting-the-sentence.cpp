class Solution {
public:
    string sortSentence(string s) 
    {
        map<int,string> m;
        stringstream words(s);
        string temp="";
        while(words>>temp)
        {
            int ind= temp[temp.length()-1];
            m[ind]=temp.substr(0,temp.length()-1);
        }
        //sort(m.begin(),m.end())
        string copy="";
        for(auto i:m)
        {
            copy=copy+i.second+" ";
        }
        return copy.substr(0,copy.length()-1);
    }
};