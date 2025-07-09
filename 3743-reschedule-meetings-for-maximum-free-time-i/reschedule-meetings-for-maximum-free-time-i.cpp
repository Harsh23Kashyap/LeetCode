class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int,int>> freeTime;
        // if(startTime[0]!=0)
        freeTime.push_back({0,startTime[0]});
        for(int i=1;i<startTime.size();i++){
            // if(endTime[i-1]!=startTme[i])
                freeTime.push_back({endTime[i-1],startTime[i]});

        }
        // if(endTime.back()!=eventTime)
        freeTime.push_back({endTime.back(),eventTime});

        int i=0,j=0;;
        int time=0;
        int maxi=0;
        int dis=freeTime.size()<k+1?freeTime.size():k+1;
        while(j<dis){
            time+=freeTime[j].second-freeTime[j].first;
            cout<<"CUrrent time "<<time<<endl;
            j++;
        }
        maxi=max(maxi,time);
        while(j<freeTime.size()){
            time+=freeTime[j].second-freeTime[j].first;
            time-=freeTime[i].second-freeTime[i].first;
            j++;
            i++;

            maxi=max(maxi,time);
        }

        return maxi;;

    }
};