
#ifndef _BIN_HEAP_H
#define _BIN_HEAP_H

typename <class T>
class BinomialHeap
{
    static int INF = INT_MAX;
    class BinomialTreeNode
    {
        friend void binomial_link(BinomialTreeNode* T1, BinomialTreeNode* T2);
        BinomialTreeNode* child;
        BinomialTreeNode* sibling;
        BinomialTreeNode* parent;
        T value;
        int degree;

        BinomialTreeNode() : child(0), sibling(0), parent(0), degree(INF) {}
    }
    static void binomial_link(BinomialTreeNode* T1, BinomialTreeNode* T2)
    {// make T2 to be T1's parent
        T1->parent = T2;
        T1->sibling = T2->child;
        T2->child = T1;
        T2->degree += 1;
    }

    void destory(); //for destructor

    BinomialHeap(const BinomialHeap&);// no copy

    BinomialHeap operator = (const BinomialHeap&);// no assign

public:
    BinomialHeap() : head(NULL), min(NULL) {}
    ~BinomialHeap() {destory();}
    void heap_merge(BinomialHeap& H);
    void heap_union(BinomialHeap& H)
    {
    }


//data set
    BinomialTreeNode* head; //链表的头
    BinomialTreeNode* min;  //存储指向最小元素的指针
};//BinomialHeap

void BinomialHeap::destory()
{
    //to be add
}
void BinomialHeap::heap_merge(BinomialHeap& _L)
{
    BinomialTreeNode *_head = NULL;
    BinomialTreeNode **pos = &_head;
    BinomialTreeNode *cur = head, *cur_L = _L.head;
    while (cur && cur_L)
    {
        if (cur->degree < cur_L->degree)
        {
            *pos = cur;
            cur = cur->sibling;
        }
        else
        {
            *pos = cur_L;
            cur_L = cur_L->sibling;
        }
        pos = &(*pos)->sibling;
    }
    if (cur)
        *pos = cur;
    else *pos = cur_L;
    head = _head;
}
#endif  //_BIN_HEAP_H
