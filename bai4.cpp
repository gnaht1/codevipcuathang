#include <iostream>
#include <cmath>
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
bool isPrime(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt(x); ++i)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}
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

    int primeAtOdd()
    {
        int count = 0;
        int index = 0;
        node *tmp = head;
        while (tmp != nullptr)
        {
            if (index % 2 == 0 && isPrime(tmp->value))
            {
                count++;
            }
            tmp = tmp->next;
            index++;
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
        cout << "Danh sach co " << primeAtOdd() << " so nguyen to o vi tri le.";
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