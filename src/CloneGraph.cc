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
struct Node {
    vector<Node*> neighbors;
};

Node* clone(const Node* graph)
{
    if (graph == NULL) return NULL;
    Node* result;
    map<Node*, bool> flag;
    queue<Node*> Q;
    Q.push(graph);
    while (!Q.empty())
    {
        Node* topNode = Q.top();
        for ()
    }
}


