struct LinkNode {
    int value;
    LinkNode* next;
    LinkNode(int v=0, LinkNode* n_ptr=NULL) : value(v), next(n_ptr) {}
};

int Length(LinkNode* head) {
    int count = 0;
    for (; head != NULL; head = head->next) {
        ++count;
    } 
    return count;
}

void Push(LinkNode*& head, int newVal) {
    LinkNode* node = new LinkNode(3, head);
    head = node;
}
void Pop(LinkNode*& head) {
    LinkNode* cur = head;
    head = head->next;
    delete cur;
    return;
}

int Count(LinkNode* head, int searchFor) {
    int cnt = 0;
    for (; head != NULL; head = head->next) 
        if (searchFor == head->value) cnt++;
    return cnt; 
}

void InsertNth(LinkNode*& head, int val, int index) {
    if (index < 0) return;

}

void SortInsert(LinkNode*& head, LinkNode* newNode) {
    LinkNode* cur = head;
    LinkNode* pre = NULL;
    while (cur != NULL && cur->value < newNode->value) {
        pre = cur;
        cur = cur->next;
    }
    if (pre == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = pre->next;
        pre->next = newNode;
    }
    return;
}

