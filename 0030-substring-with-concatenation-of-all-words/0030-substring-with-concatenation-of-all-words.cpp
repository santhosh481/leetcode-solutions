class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        // Try every possible offset inside one word
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> current;

            for (int right = offset;
                 right + wordLen <= s.length();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not present in words
                if (required.find(word) == required.end()) {

                    current.clear();
                    count = 0;
                    left = right + wordLen;

                    continue;
                }

                current[word]++;
                count++;

                // Too many copies of this word
                while (current[word] > required[word]) {

                    string leftWord = s.substr(left, wordLen);

                    current[leftWord]--;
                    count--;
                    left += wordLen;
                }

                // Found all words
                if (count == wordCount) {

                    result.push_back(left);

                    // Move window forward
                    string leftWord = s.substr(left, wordLen);

                    current[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return result;
    }
};