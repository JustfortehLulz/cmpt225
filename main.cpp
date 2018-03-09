#include <iostream>
#include "Deque.cpp"

using namespace std;

int main()
{
	Deque* weed = new Deque();

	// weed->push_left(6);
	// weed->push_left(420);
	// weed->push_left(3);
	// weed->push_left(10);

	//cout << weed->cursor_right() << endl;
	//cout << weed->cursor_right() << endl;
	//cout << weed->cursor_right() << endl;
	//cout << weed->cursor_right() << endl;

	weed->push_right(69);
	weed->push_right(91);
	weed->push_right(1);
	weed->push_right(17);

	cout << "This is the size: " << weed->size() << endl;
	cout << "Is the queue empty? " << weed->empty() << endl;
	cout << "This is popped: " << weed->pop_left() << endl;
		cout << "THE BIGGEST WEED EVER " << weed->get_cursor() << endl;
	cout << "This is popped: " << weed->pop_left() << endl;
		cout << "THE BIGGEST WEED EVER " << weed->get_cursor() << endl;
	cout << "This is popped: " << weed->pop_left() << endl;
	
	//cout << "BIG WEED " << weed->peek_left() << endl;
	//cout << "EVEN BIGGER WEED " << weed->peek_left() << endl;
	cout << "THE BIGGEST WEED EVER " << weed->get_cursor() << endl;
	// cout << "---NOW PRINTING LINKED LIST---" << endl;

	//cout << "This is popped: " << weed->pop_right() << endl;

	//weed->display();
	//cout << endl;
	//weed->verbose_display();

	// weed->~Deque();

	//weed->display();
	return 0;
}