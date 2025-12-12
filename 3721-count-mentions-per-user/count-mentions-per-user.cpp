class Solution {
public:
    vector<int> mentions;
    int all=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> offline;
    vector<int> online;

    void update_mention(string men){
         if(men=="HERE"){
                for(int i=0;i<online.size();i++){
                    if(online[i]==1)
                        mentions[i]++;
                }
            }
            else if(men=="ALL"){
               all++;
            }
            else{
                stringstream ss(men);
                string id;
                while(ss>>id){
                        int nid=stoi(id.substr(2));
                        cout<<nid<<endl;
                            mentions[nid]++;
                    
                }
            }
    }
    static bool cmp(vector<string> &a, vector<string> &b){
        int ta=stoi(a[1]);
        int tb=stoi(b[1]);
        if (ta<tb){
            return true;

        }
        if(ta>tb){
            return false;
        }
        if(ta==tb){
            if(a[0]=="OFFLINE" and b[0]=="MESSAGE")
            return true;

             if(a[0]=="MESSAGE" and b[0]=="OFFLINE")
            return false;

        }
        return true;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        mentions.resize(numberOfUsers);
        vector<int> temp(numberOfUsers,1);
        online=temp;

        sort(events.begin(),events.end(),cmp);

        for(int i=0;i<events.size();i++){
            // cout<<"Run "<<i<<endl;
            int currtime=stoi(events[i][1]);
            while(!offline.empty() and currtime>=offline.top().first){
                auto it=offline.top();
                offline.pop();
                online[it.second]=1;
            }

            if(events[i][0]=="MESSAGE"){
                update_mention(events[i][2]);
            }
            else{
            int user=stoi(events[i][2]);
                offline.push({currtime+60,user});
                online[user]=0;
            }
        }
        for(int i=0;i<mentions.size();i++)
        mentions[i]+=all;
        return mentions;


    }
};