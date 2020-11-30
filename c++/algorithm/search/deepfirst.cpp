#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*************n个整数(1至n)的全排列*********/
void process_int(int step, vector<int>& box, vector<int>& book, int& n, int& counts)
{
    if(step == n+1)
    {
        for(int i=1; i<=n; i++)
            cout << box[i];
        cout << "   ";
        counts++;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(book[i] == 0)
        {
            box[step] = i;
            book[i] = 1;
            process_int(step+1, box, book, n, counts);
            book[i] = 0;
        }
    }
    return;
}

/*********字符串数组中是否存在一种排列方式，使每一个字符串的尾字符与下一个字符串的头字符相同**********/
void process_string(int step, vector<string>& arr, vector<string>& box, vector<int>& book, int& n, int& flag)
{
    if(step == n+1)
    {
        flag = 1;
        for(int i=1; i<=n; i++)
        {
            cout << box[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(book[i] == 0 && step == 1)
        {
            box[step] = arr[i];
            book[i] = 1;
            process_string(step+1, arr, box, book, n, flag);
            if(flag == 1)
                return;
            book[i] = 0;
        }
        else if(book[i] == 0 && arr[i][0] == box[step-1][box[step-1].size()-1])
        {
            box[step] = arr[i];
            book[i] = 1;
            process_string(step+1, arr, box, book, n, flag);
            if(flag == 1)
                return;
            book[i] = 0;
        }
    }
    return;
}

int main()
{
    int n;
    int counts = 0;
    cin >> n;
    vector<int> book(n+1, 0);
    vector<int> box(n+1, 0);

    process_int(1, box, book, n, counts);

    cout << endl << "total: " << counts << endl;

    // int flag = 0;
    // vector<string> box(n+1);
    // vector<string> arr(n+1);
    // vector<int> book(n+1, 0);
    // for(int i=1; i<=n; i++)
    // {
    //     cin >> arr[i];
    // }

    // process_string(1, arr, box, book, n, flag);
    // if(flag == 1)
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;
    return 0;
}