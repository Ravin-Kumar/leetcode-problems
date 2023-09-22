class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> a {0,0};
        unordered_map<int, int> hashmap;
        int current_target_idx;

        hashmap[nums[0]] = -1;
        
        for (int i = 1; i < nums.size(); i++) {
            current_target_idx = hashmap[target-nums[i]];
            if (current_target_idx != 0) {
                if (current_target_idx == -1) {
                    current_target_idx = 0;
                }
                a = {i, current_target_idx};
                break;
            } else {
                hashmap[nums[i]] = i;
            }
        }
        return a;
    }
};