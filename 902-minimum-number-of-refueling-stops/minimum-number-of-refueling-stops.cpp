class Solution {
public:
    // int ds(int curr, int target, int fuel, vector<vector<int>> u, int  sp){

    //     if(curr+fuel>=target)
    //     return 0;

    //    for(int k=sp;k<u.size();k++){

    //         if(sp+fuel<u[k].first)
    //             break;
            
    //         //buy petrol here and move
    //         int notbuy=
    //         //dont buy petrol here
    //    }

    // }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        // for(auto it:stations)
        //     u[it.first]=it.second;
        // return ds(0,target,startFuel,stations,0)
        vector<int> vis(stations.size(),false);
        int j=0;
        priority_queue<int> pq;
        int start=0;
        int c=0;
        while(startFuel>0){

            int maxDist=start+startFuel;
            cout<<maxDist<<endl;
            if(maxDist>=target)
            return c;
            cout<<"CUrrently at "<<maxDist<<endl;
            while(j<stations.size()){
                if(stations[j][0]<=maxDist)
                {
                    pq.push(stations[j][1]);
                    cout<<"Added "<<stations[j][0]<<endl;
                    j++;
                }
                else break;
            }

            start=maxDist;

            startFuel=0;
            if(pq.size()>0){
            startFuel+=pq.top();
            cout<<"Fuelded up "<<startFuel<<endl;
            pq.pop();
            c++;
            }



        }
        return -1;
    }
};