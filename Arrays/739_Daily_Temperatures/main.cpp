class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		vector<int> answer(n);
		vector<int> stack(n);
		int top = -1;
		
 		for (int i = 0; i < n; i++) {
			while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
				int index = stack[top--];
				answer[index] = i - index;
			}
			
			stack[++top] = i;
		}
		
		return answer;
	}
};