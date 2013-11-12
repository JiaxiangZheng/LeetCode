/*
 * =====================================================================================
 *
 *       Filename:  graph.cc
 *
 *    Description:  graph basic info
 *
 *        Version:  1.0
 *        Created:  2013/4/16 19:56:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiaxiang Zheng (NULL), jiaxiang.zheng135@gmail.com
 *   Organization:  State Key Lab of CAD&CG
 *
 * =====================================================================================
 */
#include <vector>
#include <queue>
#include <iterator>
#include <iostream>
using namespace std;

struct graph_node {
    int v_id;
    float weight;   // not used yet.
    graph_node* next;
    graph_node(int _v, float _w, graph_node* _n = NULL) : v_id(_v), weight(_w), next(_n) { }
};
std::vector<graph_node*> g;

void topo_sort(const std::vector<graph_node*>& g, std::vector<int>& seq);
// construct a directive graph
int main() {
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(void*) = " << sizeof(void*) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << sizeof(graph_node) << endl;
    int vn; cin >> vn;
    g.resize(vn, NULL);
    int en; cin >> en;
    int v1, v2;
    for (int i=0; i<en; ++i) {
        cin >> v1 >> v2; v1--, v2--;
        if (g[v1] == NULL) {
            g[v1] = new graph_node(v2, 0.0f);
        } else {
            g[v1] = new graph_node(v2, 0.0f, g[v1]);
        }
    }
    std::vector<int> seq;
    topo_sort(g, seq);
    std::copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}

void topo_sort(const std::vector<graph_node*>& g, std::vector<int>& seq) {
    int vn = g.size();
    std::vector<bool> v_flag(vn, false);
    std::vector<int> indegree(vn, 0);
    for (int i=0; i<vn; ++i) {
        graph_node* cur = g[i];
        while (cur) {
            indegree[cur->v_id]++;
            cur = cur->next;
        }
    }
    std::queue<int> Q;
    for (int i=0; i<vn; ++i) 
        if (indegree[i] == 0) Q.push(i);
    if (!seq.empty()) seq.clear();
    seq.reserve(vn);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        v_flag[cur] = true;
        seq.push_back(cur);
        graph_node* cur_ptr = g[cur];
        while (cur_ptr ) {
            if (!v_flag[cur_ptr->v_id]) {
                indegree[cur_ptr->v_id]--;
                if (indegree[cur_ptr->v_id] == 0) 
                    Q.push(cur_ptr->v_id);
            }
            cur_ptr = cur_ptr->next;
        }
    }
    // check circle
    if (seq.size() != vn) {
        fprintf(stderr, "there is a circle in the graph...\n");
    }
    return;
}
