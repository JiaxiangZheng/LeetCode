/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        UndirectedGraphNode* outGraph = NULL;
        if (!node) return outGraph;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dicts;
        queue<UndirectedGraphNode *> q;
        q.push(node);
    
        UndirectedGraphNode *graphCopy = new UndirectedGraphNode(node->label);
        dicts[node] = graphCopy;
    
        while (!q.empty()) {
            node = q.front(); q.pop();
            int n = node->neighbors.size();
            for (int i = 0; i < n; i++) {
                UndirectedGraphNode *neighbor = node->neighbors[i];
                // no copy exists
                if (dicts.find(neighbor) == dicts.end()) {
                    UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
                    dicts[node]->neighbors.push_back(p);
                    dicts[neighbor] = p;
                    q.push(neighbor);
                } else {     // a copy already exists
                    dicts[node]->neighbors.push_back(dicts[neighbor]);
                }
            }
        }
    
        return graphCopy;
    }
};

