#include <iostream>
using namespace std;

struct node
{
public:
    int value;
    node *next;
    node()
    {
        value = 0;
        next = NULL;
    }
};

struct linkedList
{
    node *head = NULL;
    node *tail = NULL;

    void insertNodeTail(int x)
    {
        node *newNode = new node;
        newNode->value = x;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    int count()
    {
        int count = 0;
        node *tmp = head;
        while (tmp != nullptr)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    void printList()
    {
        if (head == nullptr)
        {
            cout << "Danh sach rong.";
            return;
        }
        node *tmp = head;
        cout << "Danh sach vua nhap la: ";
        while (tmp != NULL)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
        cout << "Danh sach co " << count() << " phan tu.";
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    linkedList a;
    int x;
    while (cin >> x && x != 0)
    {
        a.insertNodeTail(x);
    }
    a.printList();
    return 0;
}