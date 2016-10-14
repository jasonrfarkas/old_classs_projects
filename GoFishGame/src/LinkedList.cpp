#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList()
{
	count = 0;
	head=NULL;
	tail=NULL;
}

LinkedList::LinkedList(const LinkedList& otherList)
{
	count = otherList.count;
	Node *travOther = otherList.head;

	for(int i=0; i < count; i++)
	{
		insertAtTail(travOther->getData());
		travOther = travOther->getNext();
	}
}

Card* LinkedList::getHead() const
{
	if(isEmpty())
		return NULL;

	return head->getData();
}

Card* LinkedList::getTail() const
{
	if(isEmpty())
		return NULL;

	return tail->getData();
}

Card* LinkedList::getAtIndex(int index) const
{
	//cout << endl << "index is " << index << endl;
	if(isEmpty() || index < 0 || index > count-1)
	{
		return NULL;
	}
	Node *temp= head;
	for(int i = 0; i < index; i++)
	{
		//cout << "ahh" << endl;
		temp = temp->getNext();
	}
	return temp->getData();
}

int LinkedList::getCount() const
{
	return count;
}

void LinkedList::insertAtHead( Card* data)
{
	head = new Node(data, head);

	if (isEmpty())
		tail = head;
		count++;
}

void LinkedList::insertAtTail( Card* data)
{
	if (isEmpty())
	{
		insertAtHead(data);
	}

	else
	{
		Node* temp = new Node(data);
		tail->setNext(temp);
		tail = tail->getNext();
		count++;
	}	

}

bool LinkedList::insertAtIndex(Card* data, int index)
{
	//cout<< " index to insert is  " << index;
	if(isEmpty() || index ==0)
	{
		insertAtHead(data);
		return true;
	}

	else if(index > count)
	{
		return false;
	}

	else if(index == count)
	{
		insertAtTail(data);
		return true;
	}

	else
	{
		Node *temp = head;
		for(int i = 0; i < index-1; i++)
		{
			temp = temp->getNext();
		}

		Node* temp2 = new Node(data, temp->getNext());
		temp->setNext(temp2);
		count++;
		return true;
	}

	return false;
}

Card* LinkedList::removeAtHead()
{
	if (isEmpty())
		return NULL;

	Card* temp = head->getData();
	Node *discard = head;

	head = head->getNext();

	if (head == NULL)
		tail = NULL;

	delete discard;
	count--;
	return temp;
}

Card* LinkedList::removeAtTail()
{
	if (isEmpty())
		return NULL;

	if (count == 1)
		return removeAtHead();

	Node *trav = head;

	while (trav->getNext()->getNext() != NULL)
		trav = trav->getNext();

	Card* temp = tail->getData();
	Node *discard = tail;

	tail = trav;
	trav->setNext(NULL);

	delete discard;
	count--;
	return temp;
}

Card* LinkedList::removeAtIndex(int index)////
{
	if (isEmpty() || index < 0 || index > count)
		return NULL;

	if (index == 0)
		return removeAtHead();

	if (index == count-1) // this may have to be -1
		return removeAtTail();

	Node *trav = head;
	int c=0;

	for (int i = 0; i < index-1; i++)
		{
		trav = trav->getNext();
		c++;
		}
	
	Card* temp = trav->getNext()->getData();
	Node *discard = trav->getNext();
// what next next doesn't exist??, what if we are deleting the head??
	if(c+2 < count)
	{
	trav->setNext(trav->getNext()->getNext());
	}
	else
	{
	trav->setNext(NULL);
	tail = trav;
	}

	//delete discard;
	discard = NULL;
	count--;
	return temp;
}


Card* LinkedList::remove(Card* data)
{
	int index = search(data);
	return removeAtIndex(index);
}
//--f--

bool LinkedList::contains(Card* data)
{
	int i = search(data);

	if (i == -1)
		return false;

	return true;
}

//returns index of first Node in LinkedList containing data
//if not found, return -1 

int LinkedList::search(Card* data) const
{
	if(isEmpty())
	{
		return -1;
	}

	Node* temp = head;
	for(int i = 0 ; i < count-1; i++)
	{

		if (data->equals(*(temp->getData())) )//change it o that it is the data
		{
			return i;
		}

		temp = temp->getNext();
	}

	return -1;
}


int LinkedList::search(int r) const
{

	if(isEmpty())
	{
		return -1;
	}


	Node* temp = head;
	for(int i = 0 ; i <= count-1; i++)
	{
		if (temp->getData()->compareByRank(r) == 0)//change it o that it is the data
		{
			return i;
		}

		temp = temp->getNext();
	}
	return -1;
}


bool LinkedList::isEmpty() const
{
	return count == 0;
}

const Card& LinkedList::operator[](int index)
{
	return *getAtIndex(index);
}

string LinkedList::displayList() const
{
	string show ="";
	//returns a string displaying the list
	if (count == 0)
		show = show +  "Empty List" +  "\n" ;
		else
		{
			Node *trav = head;
			for (int i = 0; i < count; i++)
			{
				show +=  trav->getData()->display() + " -> ";
				trav = trav->getNext();
			}
			cout << endl;
		}

		return show;
}

ostream& operator<<(ostream& out, const LinkedList& linkedlist)
{
	if (linkedlist.count == 0)
		out << "Empty List" << endl;
	else
	{
		Node *trav = linkedlist.head;
		for (int i = 0; i < linkedlist.count; i++)
		{
			out << *trav->getData() << " -> ";
			trav = trav->getNext();
		}
	}

	return out;
}



LinkedList& LinkedList::operator=(const LinkedList& otherList)
{

	if (this != &otherList)

		for (int i = 0; i < count; i++)
		{
			Node *discard = head;
			head = head->getNext();
			delete discard;
		}
	{
		count = otherList.count;
		Node *travOther = otherList.head;

		for (int i = 0; i < count; i++)
		{
			insertAtTail(travOther->getData());
			travOther = travOther->getNext();
		}
	}
	return *this;

}

LinkedList::~LinkedList()
{
	for (int i = 0; i < count; i++)
	{
		Node *discard = head;
		head = head->getNext();
		delete discard;
	}
}


