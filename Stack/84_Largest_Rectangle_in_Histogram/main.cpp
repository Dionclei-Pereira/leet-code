class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        int maxArea = 0;
        vector<int> stack;

        for (int i = 0; i < heights.size(); i++) {

            while (!stack.empty() && heights[i] < heights[stack.back()]) {
                int height = heights[stack.back()];
                stack.pop_back();

                int width;

                if (stack.empty()) {
                    width = i;
                } else {
                    width = i - stack.back() - 1;
                }

                maxArea = max(maxArea, height * width);
            }

            stack.push_back(i);
        }

        return maxArea;
    }
};
