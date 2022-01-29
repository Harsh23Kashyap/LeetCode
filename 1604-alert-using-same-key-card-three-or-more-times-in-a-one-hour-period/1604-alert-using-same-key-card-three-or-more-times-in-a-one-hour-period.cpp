class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) 
    {
        vector<string> ans;
        map<string,vector<string>> m;
        for(int i=0;i<keyName.size();i++)
        {
            string curr=keyName[i];
            m[curr].push_back(keyTime[i]);
        }
        for(auto i:m)
        {
            cout<<i.first<<" -> ";
            vector<string> v=i.second;
            if(v.size()<3) 
                continue;
            else
            {
                sort(v.begin(),v.end());
                for(string s:v)
                    cout<<s<<" : ";
                cout<<endl;
                for(int j=0;j<v.size()-2;j++)
                {
                    string zero=v[j];
                    
                    int start=((((zero[0]-'0')*10)+(zero[1]-'0'))*60)+((zero[3]-'0')*10+zero[4]-'0');
                    cout<<"Working on "<<zero<<" val - "<<start<<endl;
                    string two=v[j+2];
                    int end=((((two[0]-'0')*10)+(two[1]-'0'))*60)+((two[3]-'0')*10+two[4]-'0');
                    cout<<"and Working on "<<two<<" val - "<<end<<endl;
                    if(abs(end-start)<=60)
                    {
                        ans.push_back(i.first);
                        break;
                    }
                }
                
            }
        }
        return ans;
    }
};