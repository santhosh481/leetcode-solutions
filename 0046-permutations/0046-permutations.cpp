class Solution {
public:

    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& nums,
                   vector<bool>& used) {

        // A complete permutation is formed
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Skip already used number
            if (used[i]) {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, used);

            // Undo / Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> used(nums.size(), false);

        backtrack(nums, used);

        return result;
    }
};