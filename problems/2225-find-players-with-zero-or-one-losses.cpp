// Solved 2022-07-07
// Runtime: 873 ms (73.62%)
// Memory Usage: 162.8 MB (83.24%)

class Solution {
   public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        map<int, int> losses;
        for (const auto &match : matches) {
            if (losses.find(match[0]) == losses.end()) {
                losses[match[0]] = 0;
            }
            ++losses[match[1]];
        }

        vector<vector<int>> answer(2);
        for (const auto &[player, loss_count] : losses) {
            if (loss_count <= 1) {
                answer[loss_count].emplace_back(player);
            }
        }

        return answer;
    }
};
