class Solution {
public:
    string processStr(string s) {
        std::string result;
        result.reserve(s.length());

        for (char c : s) {
            switch (c) {
                case '%':
                    std::reverse(result.begin(), result.end());
                    break;
                case '*':
                    if (!result.empty()) {
                        result.pop_back();
                    }
                    break;
                case '#':
                    result += result;
                    break;
                default:
                    result += c;
                    break;
            }
        }

        return result;
    }
};
