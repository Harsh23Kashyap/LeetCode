class Solution {
public:
    vector<int> create(string version)
    {
        vector<int> first;
        string temp="";
        for(int i=0;i<version.size();i++)
        {
            if(version[i]=='.')
            {
                first.push_back(stoi(temp));
                temp="";
            }
            else
            {
                temp+=version[i];
            }
        }
        first.push_back(stoi(temp));
        return first;
    }
    int compareVersion(string version1, string version2) 
    {
        vector<int> first=create(version1);
        vector<int> second=create(version2);
        int i;
        for(i=0;i<first.size() and i<second.size();i++)
        {
            if(first[i]>second[i])
                return 1;
            else if(first[i]<second[i])
                return -1;
        }
        while(i<first.size())
        {
            if(first[i]>0)
                return 1;
            
            i++;
            
        }
        while(i<second.size())
        {
            cout<<"Runs";
            if(second[i]>0)
                return -1;
            i++;
        }
        return 0;
        
    }
};