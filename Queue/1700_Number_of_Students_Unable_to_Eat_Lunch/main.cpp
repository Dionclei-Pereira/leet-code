class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::array<int, 2> swCount = {0, 0};
		
		for (const auto& type : students) {
			swCount[type]++;
		}
		
		for (const auto& type : sandwiches) {
			if (swCount[type] == 0) {
				return type == 1 ? swCount[0] : swCount[1];
			}
			
			swCount[type]--;
		}
		
		return 0;
    }
};