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
    void saveControlPoints(string& filename);	//保存控制点
    void saveSmoothedPoints(string& filename);	//保存平滑轨迹
    void action(vector< vector<float> >& points, float scale = 0.5, int n = 10);		//根据输入离散点进行局部贝塞尔曲线平滑，结果保存到mTrajectory
};

#endif
