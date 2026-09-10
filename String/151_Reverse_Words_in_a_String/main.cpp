class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss(s);
        std::vector<string> words;
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }

        std::string result;
        result.reserve(s.size());

        for (int i = words.size() - 1; i > 0; i--) {
            result += words[i] + ' ';
        }

        result += words[0];
        return result;
    }
};