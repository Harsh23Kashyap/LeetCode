class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> in;
    unordered_map<string,pair<long long,int>> avg;
    UndergroundSystem() 
    {
        in.clear();
        avg.clear();
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        if(in.find(id)!=in.end())
            return;
        in[id]={stationName,t};
        
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        auto info=in[id];
        string startStation=info.first;
        int time=info.second;
        
        string commute=startStation+":"+stationName;
        //cout<<commute<<" - "<<t-time<<endl;
        in.erase(id);
        if(avg.find(commute)==avg.end())
            avg[commute]={t-time,1};
        else
        {
            auto inform=avg[commute];
            int total=(t-time)+inform.first;
            int pass=inform.second+1;
             avg[commute]={total,pass};
        }
        
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string commute=startStation+":"+endStation;
        long long time=avg[commute].first;
        int pass= avg[commute].second;
                //cout<<commute <<" - "<<time<<" - "<<pass<<endl;

        return(time*1.0)/pass;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */