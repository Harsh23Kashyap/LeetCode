class Solution {
public:
    bool replacable(string stamp,string target,int start)
    {
        for(int i=start,j=0;i<stamp.size()+start;i++,j++)
        {
            if(target[i]!='?' and stamp[j]!=target[i])
            {
                //cout<<"Fails "<<i<<endl;
                return false;
            }

        }
        return true;
    }
    int replace(string &target,int start,int size)
    {
        int conv=0;
        for(int i=start;i<start+size;i++)
        {
            if(target[i]!='?')
            {
                target[i]='?';
                conv++;
            }
        }
        return conv;
    }
    vector<int> movesToStamp(string stamp, string target) 
    {
        int count=0;
        vector<int> ans;
        vector<bool> visited(target.size(),false);
        while(count!=target.size())
        {
        //     cout<<count<<endl;
        //     cout<<target<<endl;
            bool change=false;
            for(int i=0;i<=target.size()-stamp.size();i++)
            {
                //cout<<i<<endl;
                if(!visited[i] and replacable(stamp,target,i))
                {
                    //cout<<"runs "<<i<<endl;
                    change=true;
                    count+=replace(target,i,stamp.size());
                    ans.insert(ans.begin(),i);
                    visited[i]=true;
                }
            }
            if(!change)
                return {};
        }
        return ans;
        
    }
};