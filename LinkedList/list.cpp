#include "list.h"
ostream& operator<<(ostream& os, IntList& il)
{
    Node* ptr = il.first;
    while (ptr != 0) {
        os << ptr->data << " "; ptr = ptr->link;
    }
    os << endl;
    return os;
}

void IntList::InsertBack(int e)
{
    if (!first) {
    first = last = new Node(e);
    }
    else {
        last->link = new Node(e);
        last = last->link;
    }
}
void IntList::InsertFront(int e) { 
    if (!first) {
        first = last = new Node(e);
    }
    else {
        first = new Node(e, first);
    }
}
void IntList::Insert(int e) {  
    if (!first) {
        first = last = new Node(e);    
    }
    else if (first->data > e) {
        first = new Node(e, first);
    }
    else if (first->data != e) {
        Node* cur = first->link;
        Node* prev = first;
        while (cur) {
            if (cur->data > e) {
                prev->link = new Node(e, cur);
                return;
            }
            else if (cur->data < e) {
                prev = cur;
                cur = cur->link;
            }
            else if (cur->data == e) {
                return;
            }
        }
        prev->link = new Node(e, cur);
        last = prev->link;
    }
}
void IntList::Delete(int e) { 
    Node* cur = first;
    Node* prev = first;
    Node* x;
    while(cur)
    if (cur->data > e) {
        return;
    }
    else if (cur->data < e) {
        prev = cur;
        cur = cur->link;
    }
    else{
        prev->link = cur->link;
        x = cur;
        if (x == first) {
            first = first->link;
        }
        else if (x == last) {
            last = prev;
        }
        delete x;
        return;
    }
}