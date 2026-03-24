class Solution {
public:
    static bool cmp(string &a, string &b){
        int i = a.find(' ');
        int j = b.find(' ');

        string contentA = a.substr(i + 1);
        string contentB = b.substr(j + 1);

        if (contentA != contentB)
            return contentA < contentB;

        string idA = a.substr(0, i);
        string idB = b.substr(0, j);

        return idA < idB;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs, digitLogs;

        for (auto &log : logs) {
            int i = log.find(' ');
            if (isdigit(log[i + 1]))
                digitLogs.push_back(log);
            else
                letterLogs.push_back(log);
        }

        sort(letterLogs.begin(), letterLogs.end(), cmp);

        // append digit logs (order preserved)
        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());

        return letterLogs;
    }
};