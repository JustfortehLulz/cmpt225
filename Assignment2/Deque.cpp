#include <iostream>
#include "Deque.h"

using namespace std;

//constructor
Deque::Deque()
{
	node* left_p = NULL;
	node* right_p = NULL;
	node* cursor = NULL;
	current_size = 0;
}

Deque::Deque(const Deque& dq)
{
	current_size = dq.current_size;
	left_p = new node(dq.left_p->data,NULL,NULL);
	node* old = dq.left_p->next;
	cursor = left_p;
	int i = 0;
	while(i < current_size-1)
	{
		node* temp = new node(old->data,NULL,NULL);
	 	cursor->next = temp;
	 	temp->prev = cursor;
	 	cursor = cursor->next;
	 	old = old->next;
	 	i++;
	}
	right_p = cursor;
}

Deque::~Deque()
{
	node* current = left_p;
	while (current != NULL)
	{
		node* next = current->next;
		delete current;
		current = next;
	}
}

// Insertion operators
void Deque::push_left(int item)
{
	if (current_size == 0)
	{
		left_p = new node(item,NULL,NULL);
		right_p = left_p;
		cursor = left_p;
	}
	else
	{
		node* temp = left_p;
		left_p = new node(item,NULL,temp);
		temp->prev = left_p;
	}
	current_size++;
}

void Deque::push_right(int item)
{
	if (current_size == 0)
	{
		right_p = new node(item,NULL,NULL);
		left_p = right_p;
		cursor = right_p;
	}
	else
	{
		node* temp = right_p;
		right_p = new node(item,temp,NULL);
		temp->next = right_p;
	}
	current_size++;
}

// Removal operators
int Deque::pop_left()
{
	int value = left_p->data;
	node* temp = left_p;
	if (current_size > 1)
	{
		if(cursor == left_p)
		{
			cursor_right();
		}
		left_p = left_p->next;
		left_p->prev = NULL;
	}
	else
	{
		left_p = NULL;
		right_p = NULL;
		cursor = NULL;
	}
	current_size--;
	delete temp->prev;
	delete temp;
	return value;
}

int Deque::pop_right()
{
	int value = right_p->data;
	node* temp = right_p;
	if (current_size > 1)
	{
		if(cursor == right_p)
		{
			cursor_left();
		}
		right_p = right_p->prev;
		right_p->next = NULL;
	}
	else
	{
		left_p = NULL;
		right_p = NULL;
		cursor = NULL;
	}
	current_size--;
	delete temp->next;
	delete temp;
	return value;
}

// Size functions
bool Deque::empty() {return current_size == 0;}

int Deque::size() {return current_size;}

//Cursor Movement operators
bool Deque::cursor_left()
{
	if(cursor->prev != NULL)
	{
		cursor = cursor->prev;
		return true;
	}
	else
	{
		return false;
	}
}

bool Deque::cursor_right()
{
	if(cursor->next != NULL)
	{
		cursor = cursor->next;
		return true;
	}
	else
	{
		return false;
	}
}

// Accessor functions
int Deque::peek_left() {return left_p->data;}

int Deque::peek_right() {return right_p->data;}

int Deque::get_cursor() {return cursor->data;}

void Deque::set_cursor(int i)
{
	int temp = 0;
	cursor = left_p;
	while(temp < i)
	{
		cursor_right();
		temp++;
	}
}

// Utility functions
void Deque::display()
{
	node* current = left_p;
	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

void Deque::verbose_display()
{
	node* current = left_p;
	while(current != NULL)
	{
		cout << "This is the address of the node: " << current 
		<< " This is the data inside the node: " << current->data << endl; 
		current = current->next;
	}
	cout << "This is the left pointer: " << left_p << endl;
	cout << "This is the right pointer: " << right_p << endl;
	cout << "This is the cursor pointer: " << cursor << endl;
}