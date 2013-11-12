class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector< std::vector<int> > res;
        int n = S.size(); int N = 1 << n;
        for (int i=0; i<N; ++i) {
            std::vector<int> temp;
            for (int j=0; j<n; ++j) {
                if (((i>>j) & 1) == 1)
                    temp.push_back(S[j]);  
            }
            res.push_back(temp);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > subsetResults;
        std::vector<int> out;
        subset(S, 0, out, subsetResults);
        return subsetResults;
    }
    void subset(vector<int>& S, int pos, std::vector<int>& out, std::vector<std::vector<int> >& subsetResults) {
        if (pos == S.size()) {
            subsetResults.push_back(out);
            return;
        }
        subset(S, pos+1, out, subsetResults);
        out.push_back(S[pos]);
        subset(S, pos+1, out, subsetResults);
        out.pop_back();
        return;
    }
};

