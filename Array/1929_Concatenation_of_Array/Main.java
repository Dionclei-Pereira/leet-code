class Solution {
    public int[] getConcatenation(int[] nums) {
        int len = nums.length;
        int[] result = new int[len * 2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < len; j++) {
                result[i * len + j] = nums[j];
            }
        }

        return result;
    }
}