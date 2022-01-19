class Solution {
public:
    int nthUglyNumber(int n) 
    {
        if(n==1) return 1;
        set<long> s;
        s.insert(1);
        auto itr=s.begin();
        while(s.size()<3*n)
        {
            cout<<*itr<<endl;
            s.insert((*itr)*2);
            s.insert((*itr)*3);
            s.insert((*itr)*5);
            *itr++;
        }
        int count=0;
        int ugly=0;
        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            ugly=*itr;
            //cout<<ugly<<" and "<<count+1<<endl;
            count++;
            if(count==n) break;
        }
        return ugly;
    }
};