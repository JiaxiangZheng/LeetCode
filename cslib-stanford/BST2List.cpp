#include <vector>
using namespace std;

struct BTNode {
    int value;
    BTNode* left;
    BTNode* right;
    BTNode(int v = 0, BTNode* l_ptr = NULL, BTNode* r_ptr = NULL) 
        : value(v), left(l_ptr), right(r_ptr) {}
};
BTNode* constructBST(int* data, int left, int right) {
    if (left > right) return NULL;
    if (left == right) return new BTNode(data[left]);
    int mid = left + ((right-left)>>1);
    return new BTNode(data[mid], constructBST(data, left, mid-1), constructBST(data, mid+1, right));
}

int main() {
}
