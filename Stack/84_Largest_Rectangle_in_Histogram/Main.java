class Solution {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
		
		int[] h = Arrays.copyOf(heights, ++len);
		int[] stack = new int[n];
		int top = -1;
		
		int maxArea = 0;
		
		for (int i = 0; i < len; i++) {
			while (top >= 0 && h[i] < h[stack[top]]) {
				int height = h[stack[top--]];
				
				int width = top >= 0 ? i - stack[top] - 1 : i;
				
				maxArea = Math.max(maxArea, (height * width));
			}
		
			stack[++top] = i;
		}
		
		
		return maxArea;
    }
}