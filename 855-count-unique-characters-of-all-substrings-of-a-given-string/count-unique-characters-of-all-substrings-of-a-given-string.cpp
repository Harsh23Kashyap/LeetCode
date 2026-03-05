class Solution {
public:
    int uniqueLetterString(string s) {
        
        unordered_map<char,set<int>> u;
        for(int i=0;i<s.size();i++)
            u[s[i]].insert(i);


        int count=0;

        for(int i=0;i<s.size();i++){

            set<int> &temp=u[s[i]];

            //this is bsaically my current
            //now all thse affected will be 
            auto p=temp.find(i);
            int previous=-1, nex=s.size();
            if(p!=temp.begin())
                previous=*prev(p);
            if(next(p)!=temp.end())
                nex=*next(p);

            count+=((i-previous)*(nex-i));


        }
        return count;
        

    }
};