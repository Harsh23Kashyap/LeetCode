class MyCalendar {
   
public:
    set<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int st, int et) {
       auto it=s.lower_bound({st,et});
       if(it!=s.end() and it->first<et)
       return false;

       if(it!=s.begin()){
        auto k=prev(it);
        if(k->second>st)
        return false;

        
       }
       s.insert({st,et});
       return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */