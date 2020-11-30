#include <iostream>
#include "myStack.h"
#include "test.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
	// myStack<int> s;
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(1);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(2);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(3);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(4);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(5);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(6);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(7);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(8);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(9);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;
	// s.push(10);
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;

	// s.pop();
	// cout << "size:" << s.size() << "	capacity:" << s.capacity() << "	top:" << s.top() << endl;

	// cout << "s1:" << endl;
 // 	myStack<int> s1(s);
 // 	cout << "size:" << s1.size() << "	capacity:" << s1.capacity() << "	top:" << s1.top() << endl;
	// s.pop();
	// cout << "size:" << s1.size() << "	capacity:" << s1.capacity() << "	top:" << s1.top() << endl;
	
	// cout << "s2:" << endl;
	// myStack<int> s2 = s;
	// cout << "size:" << s2.size() << "	capacity:" << s2.capacity() << "	top:" << s2.top() << endl;

	vector<int> v(10);
	for(int i=0; i<v.size(); i++)
		v[i] = i;
	
	for (std::vector<int>::iterator i = v.begin(); i != v.end();)
	{
		if(*i > 3 && *i < 6)
			v.erase(i);
		else
			i++;
	}

	for(int i=0; i< v.size(); i++)
		cout << v[i];
	cout << endl;
	// useofnew();
	return 0;
}