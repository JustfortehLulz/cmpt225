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

// Deque::~Deque()
// {
// 	node* current = left_p;
// 	while (current != NULL)
// 	{
// 		node* temp_L = left_p;
// 		current = current->next;
// 		delete temp_L;
// 	}
// 	//delete cursor;
// }

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
		left_p = left_p->next;
		left_p->prev = NULL;
		if(cursor == NULL)
		{
			cursor = left_p;
		}
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
bool Deque::empty()
{
	return current_size == 0;
}

int Deque::size()
{
	return current_size;
}

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
	node* current = right_p;
	while(current != NULL)
	{
		cout << current->data << endl; 
		current = current->prev;
	}
}