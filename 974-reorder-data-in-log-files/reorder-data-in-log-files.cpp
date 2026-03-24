class Solution {
public:
    static pair<bool,int> isdig(string a){
        for(int i=0;i<a.size();i++){
            if(a[i]==' '){
                i++;
                while(i<a.size()){
                    if(a[i]==' ')
                        i++;
                    else if(a[i]>='a' && a[i]<='z')
                        return {true,i};   // letter-log
                    else
                        return {false,i};  // digit-log
                }
            }
        }
        return {false,-1};
    }

    static bool cmp(string a, string b){
        auto dig1 = isdig(a), dig2 = isdig(b);

        // letter vs digit
        if(dig1.first != dig2.first)
            return dig1.first > dig2.first;

        // both digit → keep order
        if(!dig1.first && !dig2.first)
            return false;

        // compare contents
        int i = dig1.second, j = dig2.second;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]) return true;
            if(a[i] > b[j]) return false;
            i++, j++;
        }

        // shorter content first
        if(i == a.size() && j != b.size()) return true;
        if(i != a.size() && j == b.size()) return false;

        // contents equal → compare identifiers
        int x = 0, y = 0;
        while(a[x] != ' ' && b[y] != ' '){
            if(a[x] < b[y]) return true;
            if(a[x] > b[y]) return false;
            x++, y++;
        }

        return false;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};