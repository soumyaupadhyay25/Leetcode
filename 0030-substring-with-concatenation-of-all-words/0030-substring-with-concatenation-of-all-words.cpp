class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        int n = s.size();
        int m = words.size();
        int L = words[0].size();
        long long totalLen = 1LL * L * m;
        if (totalLen > n) return ans;

        unordered_map<string,int> need;
        need.reserve(words.size()*2);
        for (auto &w : words) ++need[w];

        for (int offset = 0; offset < L; ++offset) {
            unordered_map<string,int> seen;
            seen.reserve(need.size()*2);
            int left = offset;
            int count = 0;

            for (int right = offset; right + L <= n; right += L) {
                string word = s.substr(right, L);
                auto itNeed = need.find(word);
                if (itNeed == need.end()) {
                    seen.clear();
                    count = 0;
                    left = right + L;
                } else {
                    ++seen[word];
                    ++count;
                    while (seen[word] > itNeed->second) {
                        string leftWord = s.substr(left, L);
                        --seen[leftWord];
                        --count;
                        left += L;
                    }
                    if (count == m) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, L);
                        --seen[leftWord];
                        --count;
                        left += L;
                    }
                }
            }
        }
        return ans;
    }
};