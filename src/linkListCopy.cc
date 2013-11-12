/*
 * =====================================================================================
 *
 *       Filename:  linkListCopy.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/10/26 20:46:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiaxiang Zheng (NULL), jiaxiang.zheng135@gmail.com
 *   Organization:  State Key Lab of CAD&CG
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

template <typename T>
struct LinkNode
{
    T data;
    LinkNode *next, *rand;
    LinkNode(const T& _data) : data(_data), next(0), rand(0) 
    {}
    LinkNode() {}
};
template <typename T>
void create(LinkNode<T>*& head, const std::vector<T>& data)
{
    assert(head == NULL);
    LinkNode<T>* cur = head;
    std::vector<LinkNode<T>*> addressList;
    if (!data.empty())
        head = new LinkNode<T>(data[0]);
    cur = head;
    addressList.push_back(cur);
    for (int i=1; i<data.size(); ++i)
    {
        cur->next = new LinkNode<T>(data[i]);
        cur = cur->next;
        addressList.push_back(cur);
    }
    cur = head;
    for (int i=0; i<addressList.size(); ++i)
    {
        int _index = rand()%addressList.size();
        cur->rand = addressList[_index];
        cur = cur->next;
    }
    return;
}

template <typename T>
void print(LinkNode<T>*& head)
{
    LinkNode<T>* cur = head;
    while (cur)
    {
        std::cout << cur->data << "\t" << cur->rand->data << endl;;
        cur = cur->next;
    }
    return;
}

template <typename T>
LinkNode<T>* copy(LinkNode<T>* head)
{
    LinkNode<T>* out = NULL;
    LinkNode<T>* cur = head;
    int listLength = 0;
    std::map<LinkNode<T>*, int> dict;
    while (cur) {
        dict[cur] = listLength;
        ++listLength;
        cur = cur->next;
    }
    out = new LinkNode<T>[listLength];
    for (int i=0; i<listLength; ++i)
    {
        cur = out + i; 
        cur->data = head->data;
        if (i == listLength-1) cur->next = NULL;
        else    cur->next = cur + 1;
        cur->rand = out + dict[head->rand];
        head = head->next;
    }
    return out;
}

template <typename T>
void release(LinkNode<T>* head)
{
    LinkNode<T>* cur = head;
    while (head)
    {
        cur = head->next;
        delete head;
        head = cur;
    }
}

int main()
{
    std::vector<int> Vs(10);
    for (int i=0; i<Vs.size(); ++i) Vs[i] = i;
    LinkNode<int>* special_list = NULL;
    create(special_list, Vs);
    print(special_list);
    std::cout << std::endl;
    LinkNode<int>* copy_list = NULL;
    copy_list = copy(special_list);
    print(copy_list);

    //release(copy_list);
    delete[] copy_list;//because I allocate it using new []
    release(special_list);
    return 0;
}

