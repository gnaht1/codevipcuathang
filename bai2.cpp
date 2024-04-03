#include <iostream>
#include <unordered_map>
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
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
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
        //<key, value>
        unordered_map<int, int> freq;
        while (tmp != nullptr)
        {
            cout << tmp->value << " ";
            freq[tmp->value]++;
            tmp = tmp->next;
        }
        cout << endl;
        cout << "So lan xuat hien cua tung phan tu trong danh sach la:" << endl;

        tmp = head;
        while (tmp != nullptr)
        {
            if (freq[tmp->value] != -1) //flag
            {
                cout << tmp->value << ": " << freq[tmp->value] << endl;
                freq[tmp->value] = -1;
            }
            tmp = tmp->next;
        }

        freeMemory();
    }
    void freeMemory()
    {
        node *current = head;
        while (current != nullptr)
        {
            node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    linkedList head;
    int x;
    while (cin >> x && x != 0)
    {
        head.insertNodeTail(x);
    }
    head.printList();
    head.freeMemory();
    return 0;
}