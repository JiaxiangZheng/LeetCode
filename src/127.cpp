#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define INT_MAX 100000

int editDistance(const string& str1, const string& str2) {
    int n1 = str1.size(), n2 = str2.size();
    std::vector<std::vector<int> > dp(n1+1, std::vector<int>(n2+1, 0));
    for (int i=1; i<=n1; ++i) dp[i][0] = i;
    for (int i=1; i<=n2; ++i) dp[0][i] = i;
    for (int i=1; i<=n1; ++i) {
        for (int j=1; j<=n2; ++j) {
            int add = (str1[i-1] == str2[j-1]) ? 0 : 1;
            dp[i][j] = std::min(min(dp[i-1][j], dp[i][j-1]) + 1, dp[i-1][j-1] + add);
        }
    }
    return dp[n1][n2];
}
int bfs(int start, const std::vector<std::vector<int> >& graph, const std::set<int>& end) {
    std::queue<int> Q; std::vector<int> visit(graph.size(), false);

    std::vector<int> path(graph.size(), 0); path[start] = 1;
    Q.push(start); visit[start] = true; if (end.find(start) != end.end()) return path[start];
    while (!Q.empty()) {
        int front = Q.front(); Q.pop();
        for (int i=0; i<graph[front].size(); ++i) {
            if (!visit[graph[front][i]]) {
                int ci = graph[front][i];
                visit[ci] = true;
                path[ci] = path[front] + 1;
                if (end.find(ci) != end.end()) return path[ci];
                Q.push(ci);
            }
        }
    }
    return INT_MAX;
}
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<string> vdicts(dict.begin(), dict.end());
        std::vector<std::vector<int> > graphs(vdicts.size());
        for (int i=0; i<vdicts.size(); ++i) {
            for (int j=i+1; j<vdicts.size(); ++j) {
                int dist = editDistance(vdicts[i], vdicts[j]);
                if (dist == 1) {
                    graphs[i].push_back(j);
                    graphs[j].push_back(i);
                }
            }
        }
//        for (int i=0; i<graphs.size(); ++i) {
//            cout << vdicts[i] << " : ";
//            for (int j=0; j<graphs[i].size(); ++j)
//                cout << vdicts[graphs[i][j]] << " ";
//            cout << endl;
//        }
        
//        printf("%s : ", start.c_str());
        std::vector<int> vstart;
        for (int i=0; i<vdicts.size(); ++i) 
            if (editDistance(vdicts[i], start) == 1)  {
                vstart.push_back(i);
//                printf("%s ", vdicts[i].c_str());
            }
//        printf("\n");

//        printf("%s : ", end.c_str());
        std::set<int> vend;
        for (int i=0; i<vdicts.size(); ++i) 
            if (editDistance(vdicts[i], end) == 1){
                vend.insert(i);
//                printf("%s ", vdicts[i].c_str());
            }
//        printf("\n");

        if (vend.empty() || vstart.empty()) return INT_MAX;
        int min_paths = INT_MAX;  // INF
        for (int i=0; i<vstart.size(); ++i) {
            int paths = bfs(i, graphs, vend);
//            printf("%d\n", paths);
            if (min_paths > paths) min_paths = paths;
        }

        return min_paths;
    }
};

int main() {
    int N; cin >> N;
    string word;
    std::vector<string> dict;
    while (N--) {
        cin >> word;
        dict.push_back(word);
    }
    string start, end;
    cin >> start >> end;
    Solution s;
    cout << s.ladderLength(start, end, dict) << endl;
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
int ladderLength(string start, string end, unordered_set<string> &dict) {
    int ret = 0;
    if (start == end)
        return ret;

    unordered_set<string> added;
    queue<string> que;
    int lev1 = 1;
    int lev2 = 0;
    que.push(start);
    added.insert(start);

    while (!que.empty()) {
        string s = que.front();
        que.pop();
        --lev1;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < 26; ++j) {
                string t = s;
                t[i] = 'a' + j;
                if (t == end)
                    return ret + 2;
                if (dict.find(t) != dict.end()
                    && added.find(t) == added.end()) {
                    que.push(t);
                    added.insert(t);
                    ++lev2;
                }
            }
        }

        if (lev1 == 0) {
            ++ret;
            lev1 = lev2;
            lev2 = 0;
        }
    }

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
