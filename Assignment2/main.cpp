#include <iostream>
#include "Deque.cpp"

using namespace std;

int main()
{
	Deque* deque = new Deque();

	// deque->push_left(6);
	// deque->push_left(420);
	// deque->push_left(3);
	// deque->push_left(10);

	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;

	deque->push_right(69);
	deque->push_right(91);
	deque->push_right(1);
	deque->push_right(17);

	//cout << &deque << endl;
	
	Deque* dank = new Deque(*deque);

	cout << "This is copy size " << dank->size() << endl;
	cout << "This copy empty? " << dank->empty() << endl;

	cout << "---NOW PRINTING LINKED LIST---" << endl;	
	dank->display();
	cout << "---FINISHED PRINTING LINKED LIST---" << endl;


	cout << "---NOW PRINTING LINKED LIST---" << endl;	
	deque->verbose_display();
	cout << "---FINISHED PRINTING LINKED LIST---" << endl;

	cout << dank->peek_left() << endl;

	cout << dank->peek_right() << endl;

	cout << dank->get_cursor() << endl;


	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl;
	// cout << deque->cursor_right() << endl; 

	// cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	// deque->set_cursor(2);

	// cout << "---NOW PRINTING LINKED LIST---" << endl;
	// deque->display();
	// cout << "---FINISHED PRINTING LINKED LIST---" << endl;
	// cout << "This is the size: " << deque->size() << endl;
	// cout << "Is the queue empty? " << deque->empty() << endl;


	// cout << "This is popped: " << deque->pop_right() << endl;
	// cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	// cout << "Peek Right " << deque->peek_right() << endl;

	// cout << "This is popped: " << deque->pop_right() << endl;
	// cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	// cout << "Peek Right " << deque->peek_right() << endl;
	//cout << "This is popped: " << deque->pop_left() << endl;
	//cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	//cout << "This is popped: " << deque->pop_left() << endl;
	
	//cout << "BIG deque " << deque->peek_left() << endl;
	//cout << "EVEN BIGGER deque " << deque->peek_left() << endl;
	//cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	// cout << "---NOW PRINTING LINKED LIST---" << endl;

	//cout << "This is popped: " << deque->pop_right() << endl;


	// deque->display();
	// cout << "---FINISHED PRINTING LINKED LIST---" << endl;
	//cout << endl;


	// cout << "---NOW PRINTING LINKED LIST---" << endl;	
	// deque->verbose_display();
	// cout << "---FINISHED PRINTING LINKED LIST---" << endl;
	// deque->~Deque();

 
	//deque->display();


	deque->~Deque();

	return 0;
}