class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = players.size() - 1;
        int j = trainers.size() - 1;
        int matches = 0;

        while (i >= 0 && j >= 0) {
            if (players[i] <= trainers[j]) {
                // player i can be matched with trainer j
                matches++;
                i--;
                j--;
            } else {
                // player i is too strong, try next weaker player
                i--;
            }
        }

        return matches;
    }
};
