
class Solution
{
public:
    int similarity(const std::string& str1, const std::string& str2)
    {
        int** sim;
        sim = new int*[str1.size()];
        for (int i=0; i<str1.size(); ++i)
            sim[i] = new int[str2.size()];
        for (int i=0; i<str1.size(); ++i)
            sim[i][0] = 
    }
};
