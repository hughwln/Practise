#ifndef SMOOTH_H
#define SMOOTH_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

class smooth
{
private:
    float mScale = 0.5;
    vector< vector<float> > mControlPoints;
    vector< vector<float> > mSmoothedPoints;
public:
    void saveControlPoints(string& filename);	//������Ƶ�
    void saveSmoothedPoints(string& filename);	//����ƽ���켣
    void action(vector< vector<float> >& points, float scale = 0.5, int n = 10);		//����������ɢ����оֲ�����������ƽ����������浽mTrajectory
};

#endif
