class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            // greedy
            // condition, player <= trainer[i];
    
            // sort both
            // if matching, increment
            // go to next trainer
    
            sort(players.begin(), players.end());
            sort(trainers.begin(), trainers.end());
            int counter = 0;
            int p = 0;
            int t = 0;
            while (p < players.size() && t < trainers.size()) {
    
                if (players[p] <= trainers[t]) {
                    counter++;
                    p++; // pointer for player
                }
                t++;
            }
    
            return counter;
        }
    };