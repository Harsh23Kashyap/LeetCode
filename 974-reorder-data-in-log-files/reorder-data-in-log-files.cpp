class Solution {
public:
    static bool cmp(string &a, string &b){
        bool diga=true;
        bool digb=true;
        int i=0;
        for(i=0;i<a.size();i++){
            if(a[i]==' '){
                break;
            }
        }
        int j=0;
        for(j=0;j<b.size();j++){
            if(b[j]==' '){
                break;
            }
        }
        i++;
        j++;
        if(a[i]>='0' and a[i]<='9')
            diga=true;
        else diga=false;

        if(b[j]>='0' and b[j]<='9')
            digb=true;
        else digb=false;

       if(!diga and digb)
        return true;

        if(diga and !digb)
        return false;
        if(diga and digb)
        return false;
        if (!diga && !digb) {
            string contentA = a.substr(i);
            string contentB = b.substr(j);
            if (contentA != contentB)
                return contentA < contentB;

            string idA = a.substr(0, i - 1);
            string idB = b.substr(0, j - 1);
            return idA < idB;
        }

        return true;


    }
    vector<string> reorderLogFiles(vector<string>& logs) {
         vector<string> letterLogs, digitLogs;
         for (auto log : logs) {
            int i = log.find(' ');
            if (isdigit(log[i + 1]))
                digitLogs.push_back(log);
            else
                letterLogs.push_back(log);
        }

         sort(letterLogs.begin(), letterLogs.end(), cmp);

        // Combine result
        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
        return letterLogs;
    }
};