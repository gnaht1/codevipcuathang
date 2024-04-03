/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[]
template
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
	int info;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void CreateList(List &l);
void NhapList(List &l);
int DemSoPhanTu(List l);
void Split(List l, List &l1, List &l2);
void XuatList(List l);

int main()
{
	List l, l1, l2;
	CreateList(l);
	CreateList(l1);
	CreateList(l2);
	NhapList(l);
	if (DemSoPhanTu(l) == 0)
		cout << "Danh sach rong." << endl;
	else
	{
		cout << "Danh sach vua nhap la: ";
		XuatList(l);
		cout << endl;
		Split(l, l1, l2);
		cout << "Cac so chan trong danh sach la: ";
		XuatList(l1);
		cout << endl;
		cout << "Cac so le trong danh sach la: ";
		XuatList(l2);
		cout << endl;
	}
	return 0;
}

// ###INSERT CODE HERE -
void CreateList(List &l)
{
	l.pHead = l.pTail = nullptr;
}

void NhapList(List &l)
{
	int value;
	while (cin >> value && value != 0)
	{
		Node *newNode = new Node;
		newNode->info = value;
		newNode->pNext = nullptr;
		if (l.pHead == nullptr)
		{
			l.pHead = l.pTail = newNode;
		}
		else
		{
			l.pTail->pNext = newNode;
		}
		l.pTail = newNode;
	}
}

int DemSoPhanTu(List l)
{
	int count = 0;
	Node *tmp = l.pHead;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->pNext;
	}
	return count;
}

bool contains(Node *head, int value) {
	Node *tmp = head;
	while (tmp != nullptr) {
		if (tmp->info == value) {
			return true;
		}
		tmp = tmp->pNext;
	}
	return false;
}

void Split(List l, List &l1, List &l2)
{
	Node *tmp = l.pHead;
	while (tmp != nullptr)
	{
		Node *newNode = new Node;
		newNode->info = tmp->info;
		newNode->pNext = nullptr;
		if (tmp->info % 2 == 0 && !contains(l1.pHead, tmp->info))
		{

			if (l1.pHead == nullptr)
				l1.pHead = l1.pTail = newNode;
			else
			{
				l1.pTail->pNext = newNode;
				l1.pTail = newNode;
			}
		}
		else if (tmp->info % 2 != 0 && !contains(l2.pHead, tmp->info))
		{
			if (l2.pHead == nullptr) 
				l2.pHead = l2.pTail = newNode;
			else
			{
				l2.pTail->pNext = newNode;
				l2.pTail = newNode;
			}
		}

		tmp = tmp->pNext;
	}
}

void XuatList(List l)
{
	Node *tmp = l.pHead;
	while (tmp != nullptr)
	{
		cout << tmp->info << " ";
		tmp = tmp->pNext;
	}
}