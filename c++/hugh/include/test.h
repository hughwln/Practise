#include <iostream>
using namespace std;
int useofnew()
{
	int * p1 = new int[10];
	for(int i=0; i<10; i++)
	{
		p1[i] = i;
	}
	int * p2 = new int[10];
	for(int i=0; i<10; i++)
		cout << p2[i] << endl;
	memcpy(p2, p1, 5*sizeof(int));
	for(int i=0; i<10; i++)
		cout << p2[i] << endl;
	delete []p1;
	delete []p2;
	cout << "init int:" << int() << endl;
	return 0;
}