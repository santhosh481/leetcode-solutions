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

        // Try each candidate
        for (int i = start; i < candidates.size(); i++) {

            // Candidate is too large
            if (candidates[i] > target) {
                continue;
            }

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i is passed again because we can reuse
            // the same number unlimited times
            backtrack(candidates,
                      target - candidates[i],
                      i);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        backtrack(candidates, target, 0);

        return result;
    }
};