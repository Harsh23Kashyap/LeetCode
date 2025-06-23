class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);

        priority_queue<int> pq;

        int duration=0;

        for(int i=0;i<courses.size();i++){

            int time=courses[i][0],deadline=courses[i][1];

            duration+=time;
            pq.push(courses[i][0]);

            while(duration>deadline and !pq.empty()){
                cout<<pq.top()<<" Not workung"<<endl;
                duration-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};