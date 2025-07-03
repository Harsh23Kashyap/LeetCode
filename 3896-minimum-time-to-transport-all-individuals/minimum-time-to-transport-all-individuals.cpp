class Solution {
public:
int counter(int n){
    int c=0;
    while(n>0){
        n=n&(n-1);
        c++;
    }
    return c;
}
    struct Event{
        double time; 
        int mask;
        int stage;
        bool atBase;

    };
    struct Comparator{
        bool operator()(const Event &a, const Event &b){
            return  a.time>b.time;
        }
    };
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if(k==1){
            if(n==1)
                return mul[0]*time[0];
            return -1;

        }

        int fullMask=(1<<n)-1;
        priority_queue<Event, vector<Event>, Comparator> pq;

        vector<vector<vector<double>>> dp(1<<n, vector<vector<double>> (m, vector<double> (2,2e15)));

        pq.push({0.0,fullMask,0,true});

        dp[fullMask][0][1] = 0;

        while(!pq.empty()){
            auto [currtime,currmask,stage,atBase]=pq.top();
            pq.pop();
            if(currmask==0 and !atBase)
                return currtime;

            if(dp[currmask][stage][atBase]<currtime)
                continue;

            if(atBase)
            {
            for (int submask = currmask; submask > 0; submask = (submask - 1) & currmask){
                    int tc=counter(submask);
                    if(tc==0 or tc>k)
                        continue;
                    
                    int maxTime=0;
                    for(int bt=0;bt<n;bt++){
                        if(((submask>>bt)&1) == 1){
                            maxTime=max(maxTime,time[bt]);
                        }
                    }

                    double tripTime=mul[stage]*maxTime;

                    int nextStage=  (stage + (int)floor(tripTime)) % m;

                    int newmask= currmask^submask;

                    if(dp[newmask][nextStage][0]>tripTime){
                        dp[newmask][nextStage][0] = currtime + tripTime;
                        pq.push({currtime + tripTime,newmask, nextStage, false});
                    }
                }

            }

            else{
                for (int i = 0; i < n; i++) 
                {
                    if (((currmask >> i) & 1) == 0) 
                    { 
                        int newmask = currmask | (1 << i);
                        double returnTime = time[i] * mul[stage];
                        int nextStage = (stage + (int)floor(returnTime)) % m;

                        if (dp[newmask][nextStage][1] > currtime + returnTime) {
                            dp[newmask][nextStage][1] = currtime + returnTime;
                            pq.push({currtime + returnTime, newmask, nextStage, true});
                        }
                    }
                }

            }
            
        }
        return -1;
        
    }
};