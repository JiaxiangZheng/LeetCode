#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#define MAX_LEVEL 16

struct SkipNode {
    int key, level;
    SkipNode** next;
    SkipNode() {
        next = NULL;
    }
    SkipNode(int __key, int __level) : key(__key), level(__level) {
        next = new SkipNode[level];
    }
    ~SkipNode() {
        delete[] next;
    }
};

int getLevel() {
    int level = 1;
    while ((rand() & 1) == 0 && level < MAX_LEVEL) level++;
    return level;
}
class SkipList {
public:
    SkipList() : head_(new SkipNode(INT_MIN, MAX_LVELE)) {
    }
    void clear() {
        SkipNode* next = NULL;
        while (head_) {
            next = head_->next;
            delete head_;
            head_ = next;
        }
        return;
    }
    void insert(int key);
    const SkipNode* head() const { return head_; }
    int level() const { return level_; }
private:
    SkipNode* head_;
    int level_;
};

void SkipList::insert(int key) {
    SkipNode* cursor[MAX_LEVEL] = {0};
    // TODO!!!
    for (int i = level_-1; i >= 0; --i) {
        while (cursor[i]->next[i] && head->next[i]->key < key) 
    }
    
    // found a position to be insert
    int level = getLevel();
    SkipNode* node = new SkipNode(key, level);
}
#endif/* SKIP_LIST_H */
