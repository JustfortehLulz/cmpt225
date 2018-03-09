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

	//cout << deque->cursor_right() << endl;
	//cout << deque->cursor_right() << endl;
	//cout << deque->cursor_right() << endl;
	//cout << deque->cursor_right() << endl;

	deque->push_right(69);
	deque->push_right(91);
	deque->push_right(1);
	deque->push_right(17);

	cout << "This is the size: " << deque->size() << endl;
	cout << "Is the queue empty? " << deque->empty() << endl;
	cout << "This is popped: " << deque->pop_left() << endl;
		cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	cout << "This is popped: " << deque->pop_left() << endl;
		cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	cout << "This is popped: " << deque->pop_left() << endl;
	
	//cout << "BIG deque " << deque->peek_left() << endl;
	//cout << "EVEN BIGGER deque " << deque->peek_left() << endl;
	cout << "THE BIGGEST deque EVER " << deque->get_cursor() << endl;
	// cout << "---NOW PRINTING LINKED LIST---" << endl;

	//cout << "This is popped: " << deque->pop_right() << endl;

	//deque->display();
	//cout << endl;
	//deque->verbose_display();

	// deque->~Deque();

	//deque->display();
	return 0;
}
