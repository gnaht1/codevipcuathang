/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[]
template
###End banned keyword*/

#include <iostream>
using namespace std;
struct node
{
    int info;
    node *pNext;
};
struct List
{
    node *pHead;
    node *pTail;
};
void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
void ReverseList(List &l);

// ###INSERT CODE HERE -
void nhap(List &l)
{
    int value;
    while (cin >> value && value != 0)
    {
        node *newNode = new node;
        newNode->info = value;
        newNode->pNext = nullptr;
        if (l.pHead == nullptr)
        {
            l.pHead = l.pTail = newNode;
        }
        else
        {
            l.pTail->pNext = newNode;
            l.pTail = newNode;
        }
    }
}

void xuat(List l)
{
    node *tmp = l.pHead;
    while (tmp != nullptr)
    {
        cout << tmp->info << " ";
        tmp = tmp->pNext;
    }
}

void ReverseList(List &l)
{
    node *curr = l.pHead;
    node *prev = nullptr;
    node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }

    l.pHead = prev;
}

int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        ReverseList(l);
        cout << endl
             << "Danh sach sau khi dao nguoc la: ";
        xuat(l);
    }
    return 0;
}
