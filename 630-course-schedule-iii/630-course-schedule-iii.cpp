class Solution {
    static bool cmp(vector<int>&a, vector<int>& b)
    {
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        int time=0;
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> pq;
        
        for(int i=0;i<courses.size();i++)
        {
            if(courses[i][0]>courses[i][1])
                continue;
            else
            {
                if(courses[i][0]+time<=courses[i][1])
                {
                    time+=courses[i][0];
                    pq.push(courses[i][0]);
                }
                else
                {
                    if(pq.top()>courses[i][0])
                    {
                        time-=pq.top();
                        time+=courses[i][0];
                        pq.push(courses[i][0]);
                        pq.pop();
                    }
                }
            }
          //cout<<time<<endl;
        }
        return pq.size();
    }
};