class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;

        int complement = 0;
        for (int i = 0; i < nums.size(); i++) {
            complement = target - nums[i];
            if (umap.find(complement) != umap.end()) {
                return { umap[complement], i };
            }
            umap[nums[i]] = i;
        }

        return {};
    }
};