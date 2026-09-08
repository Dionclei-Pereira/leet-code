class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        std::vector<std::string> list;
		int p = 0;
		
		for (int i = 1; i <= target[target.size() - 1]; i++) {
			list.emplace_back("Push");
			
			if (i != target[p]) {
				list.emplace_back("Pop");
				continue;
			}
				
			p++;
		}
		
		return list;
    }
};