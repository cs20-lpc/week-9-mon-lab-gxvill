#include "LinkedQueue.hpp"
#include <cstdlib>

using namespace std;
/*
TODO list
[ ] contructor
[ ] back
[ ] clear
[ ] copy
[ ] dequeue
[ ] enqueue
[ ] front
*/

int main(){

	cout << "Testing constructor" << endl;
	LinkedQueue<int> q;

	cout << "Testing enqueue" << endl;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	cout << "Testing front" << endl;
	cout << q.front() << endl;; // should print 1


	cout << "Testing back" << endl;
	cout << q.back() << endl;; // should print 5

	cout << "Testing copy" << endl;
	LinkedQueue<int> l = LinkedQueue(q);


	cout << "Testing clear" << endl;

	try{
		q.clear();
	}
	catch(const string& e){
		cout << e << endl;
	}

	cout << "Testing front" << endl;
	cout << l.front() << endl;; // should print 1


	cout << "Testing back" << endl;
	cout << l.back() << endl;; // should print 5


	cout << "Testing dequeue" << endl;

	try{
		l.dequeue();
	}
	catch(const string& e){
		cout << e << endl;
	}

	cout << "Testing uncaught exception" << endl;

	return 0;
}
