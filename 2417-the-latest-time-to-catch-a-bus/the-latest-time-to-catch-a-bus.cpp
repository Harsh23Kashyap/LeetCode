class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& p, int capacity) {
        sort(buses.begin(),buses.end());
        sort(p.begin(),p.end());
        int c=buses.size();
        unordered_set<int> u;
        int last=0;

        int i=0,j=0;
        int cc=0;
//         vector<vector<int>> pp;
// vector<int> t;
        while(i<buses.size() and j<p.size()){
            // cout<<i<<" "<<j<<endl;
            if(p[j]<=buses[i]){
                if(cc<capacity){
                    
                    // t.push_back(p[j]);
                    last=p[j];
                    cout<<last<<" ";
                    u.insert(last);
                    cc++;
                    // cout<<"Pushing"<<" "<<cc<<endl;
                    j++;
                }
                else{
                    if(i+1==buses.size())
                    break;
                    last=p[j];
                    cout<<"\n"<<last<<" ";
                    u.insert(last);
                    cc=1;
                    i++;
                    j++;

                }
            }
            else {

               cout<<endl;
               if(cc<capacity){
                last=abs(buses[i]);
                u.insert(-1*last);
               }
                cc=0;

               i++;

            }
        }
        if(j==p.size()){
            if(i<buses.size()-1){
            last=buses[buses.size()-1];
            }
            else if(i==buses.size()-1){
                if(cc!=capacity)
                    last=buses[buses.size()-1];
            }
        }
        // pp.push_back(t);
        cout<<"Bus Passengers"<<" "<<last<<endl;
        // for(auto it:pp){
        //     for(auto j:it)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
for(auto it:u){
    cout<<it<<" ";
}
cout<<endl;
        for(int i=last;i>=0;i--){
            if(u.find(i)!=u.end())
                continue;
            if(u.find(i)==u.end())
                return i;
             if(u.find(-1*i)!=u.end())
                return i;
            
        }
        return -1;



    }
};