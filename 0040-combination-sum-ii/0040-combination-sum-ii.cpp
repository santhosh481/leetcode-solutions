class Solution {
public:

    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& candidates,
                   int target,
                   int start) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Since array is sorted
            // no later number can work
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicates at the same level
            if (i > start &&
                candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i + 1 because each element
            // can only be used once
            backtrack(candidates,
                      target - candidates[i],
                      i + 1);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        // Sort to handle duplicates
        // and enable pruning
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return result;
    }
};