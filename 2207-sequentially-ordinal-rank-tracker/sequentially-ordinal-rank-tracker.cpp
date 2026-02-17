class SORTracker {
public:
    
    unordered_map<int, string> idToName;
    int idCounter = 0;

    struct LeftCmp {
        unordered_map<int,string>* mp;
        LeftCmp(unordered_map<int,string>* m) : mp(m) {}

        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            if (a.first == b.first)
                return (*mp)[a.second] < (*mp)[b.second];
            return a.first > b.first;
        }
    };

    struct RightCmp {
        unordered_map<int,string>* mp;
        RightCmp(unordered_map<int,string>* m) : mp(m) {}

        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            if (a.first == b.first)
                return (*mp)[a.second] > (*mp)[b.second];
            return a.first < b.first;
        }
    };

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        LeftCmp
    > left;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        RightCmp
    > right;

    SORTracker()
        : left(LeftCmp(&idToName)),
          right(RightCmp(&idToName)) {}

    void add(string name, int score) {

        idToName[idCounter] = name;

        left.push({score, idCounter});
        right.push(left.top());
        left.pop();

        idCounter++;
    }

    string get() {

        left.push(right.top());
        right.pop();

        return idToName[left.top().second];
    }
};
