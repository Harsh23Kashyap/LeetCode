class MyCalendar {
    private:
    bool possible(int st, int et){
        int l=0,h=v.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            int cst=v[m].first,cen=v[m].second;
            //3 conditons
            //1 if st<cst and en>=cen
            if(st<cen and et>cst)
            return false;
            //2 if st is greater than cend
           
             if(st>=cen)
            l=m+1;
            else
            h=m-1;
        }
        return true;
    }
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        if(possible(startTime,endTime))
        {
            v.push_back({startTime,endTime});
            sort(v.begin(),v.end());
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */