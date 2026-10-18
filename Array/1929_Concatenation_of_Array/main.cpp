class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        std::vector<int> result(len * 2);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < len; j++) {
                result[i * len + j] = nums[j];
            }
        }

        return result;
    }
};