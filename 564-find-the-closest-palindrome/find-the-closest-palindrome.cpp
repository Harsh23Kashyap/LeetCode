class Solution {
public:
    string nearestPalindromic(string n) {
         if(n.size()==1){
            if(n=="0")
                return "1";
            return to_string(n[0]-'0'-1);
        }

        long long no=stoll(n);
        int sz=n.size();
        string n99s(sz,'9');
        string n9s(sz-1,'9');
        long long n99=stoll(n99s);
        long long n9=stoll(n9s);
        string zero(sz-2,'0');
        long long n100=stoll("1"+zero+"1");
        string zero1(sz-1,'0');
        long long n1000=stoll("1"+zero1+"1");


        vector<long long> ans;
        ans.push_back(n99);
        ans.push_back(n9);
        ans.push_back(n100);
        ans.push_back(n1000);
        int half=sz/2;
        if(sz%2!=0)
            half++;

        long long prefix=stoll(n.substr(0,half));

        for(int i=prefix-1;i<=prefix+1;i++){
            string left=to_string(i);
            string right=left;
            if(sz%2!=0)
                right.pop_back();
            reverse(right.begin(),right.end());
            ans.push_back(stoll(left+right));
        }

        long long best = LLONG_MAX, diff = LLONG_MAX;
        for(auto it : ans){
            cout<<it<<endl;
            if(it==no)
                continue;
            long long currDiff = llabs(it - no);
            if(currDiff < diff){
                diff = currDiff;
                best = it;
            }
            else if(currDiff == diff){
                best = min(best, it);
            }
        }

        return to_string(best);




    }
};