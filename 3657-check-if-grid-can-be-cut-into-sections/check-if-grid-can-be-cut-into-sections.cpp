class Solution {
public:
bool possible(vector<pair<int,int>> a){
    sort(a.begin(),a.end());
    int c=0;
    unordered_set<int> u;
    int i=1;
    int maxi=a[0].second;
    while(i<a.size()){
        cout<<a[i].first<<" "<<a[i].second<<endl;
        if(maxi<=a[i].first and u.find(a[i].first)==u.end()){
            cout<<"FOund"<<endl; 
            u.insert(a[i].first);
            c++;
        }
        maxi=max(a[i].second,maxi);
        if(c>=2)
        return true;
        i++;
    }
    return false;

}
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<pair<int,int>> td,lr;

        for(auto it:rectangles){
            td.push_back({it[0],it[2]});
            lr.push_back({it[1],it[3]});
        }
        cout<<"Left Right"<<endl;
        if(possible(td))
        return true;
        cout<<"Top Down"<<endl;
        return possible(lr);
    }


};