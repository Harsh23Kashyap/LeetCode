class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> u;

        cout << "Building frequency map:\n";
        for(auto it:s) {
            u[it]++;
        }

        for(auto it:u) {
            cout << it.first << " -> " << it.second << "\n";
            pq.push({it.second,it.first});
        }

        string res="";
        cout << "\nStarting PQ processing...\n";

        while(pq.size()>=2){
            cout << "\nPQ size: " << pq.size() << "\n";

            

            auto it=pq.top();
            pq.pop();
            cout << "Top1: " << it.second << " freq=" << it.first << "\n";

            auto sit=pq.top();
            pq.pop();
            cout << "Top2: " << sit.second << " freq=" << sit.first << "\n";

            cout << "Appending: " << it.second << " and " << sit.second << "\n";
            res+=it.second;
            res=res+sit.second;

            if(it.first-1>0) {
                cout << "Pushing back: " << it.second << " freq=" << it.first-1 << "\n";
                pq.push({it.first-1,it.second});
            }

            if(sit.first-1>0) {
                cout << "Pushing back: " << sit.second << " freq=" << sit.first-1 << "\n";
                pq.push({sit.first-1,sit.second});
            }

            cout << "Current result: " << res << "\n";
        }

        if(pq.size()==1) {
                cout << "Only one element left: "
                     << pq.top().second << " freq=" << pq.top().first << "\n";
            }

        if(pq.size()==1 and pq.top().first>1)
            return "";
        else if(pq.size()==1 and pq.top().first==1)
            res+=pq.top().second;
        cout << "\nFinal result: " << res << "\n";
        return res;
    }
};