class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> >  res;
        Permute(num, 0, res);
        return res;
    }
    void Permute(std::vector<int>& num, int index, std::vector<vector<int> >& out) {
        if (index == num.size()) {
            out.push_back(num);
            return;
        }
        for (int i=index; i<num.size(); ++i) {
            if (i != index) swap(num[i], num[index]); 
            Permute(num, index+1, out);
            if (i != index) swap(num[i], num[index]); 
        }
        return;
    }
};

