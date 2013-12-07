class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.empty()) return std::vector<std::string>();
        std::map<string, std::vector<int> > maps;
        for (int i=0; i<strs.size(); ++i) {
            if (strs[i].empty()) continue;
            string curstr = strs[i];
            sort(curstr.begin(), curstr.end());
            std::map<string, std::vector<int> >::iterator it = maps.find(curstr);
            if (it == maps.end()) {
                it = maps.insert(curstr);
            }
            it->second.push_back(i);
        }
        std::map<string, std::vector<int> >::iterator it = maps.begin();
        std::vector<string> res;
        for (; it != maps.end(); ++it) {
            if (it->second.size() > 1)
                res.push_back(strs[it->second]);
        }
        return res;
    }
};

