class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string,int> u;
        for(int i=0;i<list1.size();i++)
        {
            u[list1[i]]=-1*(i+1);
        }
        
        for(int i=0;i<list2.size();i++)
        {
            if(u.find(list2[i])!=u.end())
            {
                //cout<<list2[i]<<" - "<<u[list2[i]]<<endl;
                u[list2[i]]=-1*u[list2[i]]+i+1;
                //cout<<list2[i]<<" - "<<u[list2[i]]<<endl;
            }
            else
            u[list2[i]]=-1*(i+1);
        }   
        vector<string> ans;
        int min=INT_MAX;
        for(auto i:u)
        {
            //cout<<i.first<<" "<<i.second<<endl;
            if(i.second>=0 and i.second<=min)
            {
                
                min=i.second;
            }
        }
        
        for(auto i:u)
        {
            if(i.second==min)
            {
               ans.push_back(i.first);
            }
        }
        //<<u["Shougun"]<<endl;
        return ans;
    }
};