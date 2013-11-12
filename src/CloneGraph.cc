#include <iostream> 
#include <vector>
using namespace std;
/*  Clone a graph. Input is a Node pointer. Return the Node pointer of the
 *  cloned graph.  
 *  A graph is defined below:
 *  
 *  struct Node {
 *      vector<Node *> neighbors;
 *  }
 */
struct Node;
struct Node {
    vector<Node*> neighbors;
};

void bfs(Node* graph, VisitorType& visit)
{
    std::queue<Node*> queue_graph;
    std::map<Node*, bool> flag_mapper;
    queue_graph.push(graph);
    while (!queue_graph.empty())
    {
        Node* top = queue_graph.top(); queue_graph.pop();
        flag_mapper[top] = true;
        visit(top);
        for (auto it = top.neighbors.begin(); it != top.neighbors.end(); ++it)
        {
            if (flag_mapper.cout(*it) && flag_mapper[*it] == true)  continue;
            flag_mapper[*it] = false;
            queue_graph.push(*it);
        }
    }
}

//this is comment
Node* clone(const Node* graph)
{
    if (graph == NULL) return NULL;
    Node* result;
    map<Node*, int> flag;
    queue<Node*> Q;
    Q.push(graph);
    while (!Q.empty())
    {
        Node* topNode = Q.top();
        for ()
    }
}

class Solution {
public:
    Node* clone(const Node* graph)
    {
        
    }
    Node* _clone_recursively(Node* root)
    {

    }
};

int main(int argc, char* argv[])
{
    
}
