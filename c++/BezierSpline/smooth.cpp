#include "smooth.h"

void smooth::saveControlPoints(string& filename)
{
    ofstream os(filename);
    for (size_t i = 0; i < mControlPoints.size(); i++)
    {
        for (size_t j = 0; j < mControlPoints[i].size(); j++)
        {
            os << mControlPoints[i][j] << ' ';
        }
        os << endl;
    }
}

void smooth::saveSmoothedPoints(string& filename)
{
    ofstream os(filename);
    for (size_t i = 0; i < mSmoothedPoints.size(); i++)
    {
        for (size_t j = 0; j < mSmoothedPoints[i].size(); j++)
        {
            os << mSmoothedPoints[i][j] << ' ';
        }
        os << endl;
    }
}

void smooth::action(vector< vector<float> >& points, float scale, int n)
{
    mScale = scale;
    mControlPoints.push_back(points[0]);
    for (size_t i = 1; i < points.size() - 1; i++)
    {
        float abx = (points[i - 1][0] + points[i][0]) / 2;
        float aby = (points[i - 1][1] + points[i][1]) / 2;
        float bcx = (points[i + 1][0] + points[i][0]) / 2;
        float bcy = (points[i + 1][1] + points[i][1]) / 2;
        float gx = (abx + bcx) / 2;
        float gy = (aby + bcy) / 2;
        vector<float> gbv;
        gbv.push_back(points[i][0] - gx);
        gbv.push_back(points[i][1] - gy);
        float ex = abx + gbv[0];
        float ey = aby + gbv[1];
        float fx = bcx + gbv[0];
        float fy = bcy + gbv[1];
        ex = points[i][0] + mScale * (ex - points[i][0]);
        ey = points[i][1] + mScale * (ey - points[i][1]);
        fx = points[i][0] + mScale * (fx - points[i][0]);
        fy = points[i][1] + mScale * (fy - points[i][1]);
        vector<float> e;
        vector<float> f;
        e.push_back(ex);
        e.push_back(ey);
        f.push_back(fx);
        f.push_back(fy);

        mControlPoints.push_back(e);
        mControlPoints.push_back(f);
    }
    mControlPoints.push_back(points[points.size()-1]);

    mSmoothedPoints.push_back(points[0]);
    for (size_t i = 0; i < mControlPoints.size() - 2; i++)
    {
        for (float t = 0; t <= 1;)
        {
            float b0 = 1.0 / 2.0 * (1.0 - t) * (1.0 - t);
            float b1 = 1.0 / 2.0 * (-2.0 * t * t + 2.0 * t + 1.0);
            float b2 = 1.0 / 2.0 * t * t;
            float x = b0 * mControlPoints[i][0] + b1 * mControlPoints[i + 1][0] + b2 * mControlPoints[i + 2][0];
            float y = b0 * mControlPoints[i][1] + b1 * mControlPoints[i + 1][1] + b2 * mControlPoints[i + 2][1];
            vector<float> p;
            p.push_back(x);
            p.push_back(y);
            mSmoothedPoints.push_back(p);
            t += 1.0 / n;
        }
    }
    mSmoothedPoints.push_back(points[points.size() - 1]);
}