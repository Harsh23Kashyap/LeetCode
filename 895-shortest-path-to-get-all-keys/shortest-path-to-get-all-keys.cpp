class Solution {
public:

    struct State {

        int x;
        int y;

        unordered_set<char> keys;
    };

    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int startX = 0;
        int startY = 0;

        int totalKeys = 0;

        // find start and total keys
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '@') {

                    startX = i;
                    startY = j;
                }

                if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    totalKeys++;
            }
        }

        queue<State> q;

        State start;
        start.x = startX;
        start.y = startY;

        q.push(start);

        // visited state:
        // position -> serialized key set
        map<pair<int,int>, unordered_set<string>> vis;

        vis[{startX, startY}].insert("");

        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        int steps = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                State curr = q.front();
                q.pop();

                // all keys collected
                if(curr.keys.size() == totalKeys)
                    return steps;

                for(auto &d : dir) {

                    int nx = curr.x + d.first;
                    int ny = curr.y + d.second;

                    // bounds
                    if(nx < 0 || ny < 0 ||
                       nx >= m || ny >= n)
                        continue;

                    char cell = grid[nx][ny];

                    // wall
                    if(cell == '#')
                        continue;

                    // copy current keys
                    unordered_set<char> nextKeys = curr.keys;

                    // lock
                    if(cell >= 'A' && cell <= 'F') {

                        char needed = tolower(cell);

                        if(nextKeys.find(needed) == nextKeys.end())
                            continue;
                    }

                    // key
                    if(cell >= 'a' && cell <= 'f') {

                        nextKeys.insert(cell);
                    }

                    // serialize keys
                    vector<char> temp(
                        nextKeys.begin(),
                        nextKeys.end()
                    );

                    sort(temp.begin(), temp.end());

                    string serial = "";

                    for(char c : temp)
                        serial += c;

                    // visited check
                    if(vis[{nx, ny}].find(serial)
                        != vis[{nx, ny}].end())
                        continue;

                    vis[{nx, ny}].insert(serial);

                    State nextState;

                    nextState.x = nx;
                    nextState.y = ny;
                    nextState.keys = nextKeys;

                    q.push(nextState);
                }
            }

            steps++;
        }

        return -1;
    }
};