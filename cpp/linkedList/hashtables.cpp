#include <iostream>;
#include <vector>;
#include <map>;
#include <string>;

using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	};

};
class linkedLink
{
public:
	Node* head = NULL;
	Node* tail = NULL;

	void unShift(int data)
	{
		Node* newHead = new Node(data);
		Node* head = this->head;
		this->head = newHead;
		this->head->next = head;
	}
	void shift()
	{
		Node* newHead = this->head->next;
		this->head = newHead;
		newHead = NULL;
	}
	void pop()
	{
		Node* i = this->head;
		while (i->next != this->tail)
		{
			i = i->next;
		}
		i->next = NULL;
		this->tail = i;
	}

	void push(int val)
	{
		Node* data = new Node(val);
		if (!this->head)
		{
			this->head = data;
			this->tail = data;
		}
		else
		{
			this->tail->next = data;
			this->tail = data;
		}
	}
	void print()
	{
		Node* current = this->head;
		if (current)
		{
			cout << "[ ";
			while (current)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << "]" << endl;
		} 
		else 
		{
			cout << "[ ]" << endl;
		}
	}
};

int main()
{
	linkedLink* list = new linkedLink();
	list->push(5);
	list->push(6);
	list->push(1);
	list->push(7);
	list->pop();
	list->shift();
	list->unShift(2);
	list->print();
}

