#include <iostream>
#include <fstream>
#include "smooth.h"

int main()
{
	string fpoints = "C:\\home\\Code\\matlab\\data\\input.txt";
	string fcontrol = "C:\\home\\Code\\matlab\\data\\control.txt";
	string fsmooth = "C:\\home\\Code\\matlab\\data\\result.txt";
	fstream inpoint(fpoints);
	if (!inpoint)
	{
		cout << "Unable to open the file !";
		return 1;
	}
	vector< vector<float> > p;
	for(size_t i = 0; i < 100; i++)
	{
		float x, y;
		vector<float> point;
		inpoint >> x >> y;
		point.push_back(x);
		point.push_back(y);
		p.push_back(point);
	}

	smooth S;
	S.action(p);
	S.saveControlPoints(fcontrol);
	S.saveSmoothedPoints(fsmooth);

    return 0;
}