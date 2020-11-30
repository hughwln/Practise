#include <iostream>
#include <vector>
using namespace std;
/*********************************************
冒泡排序
外层遍历：每次遍历找出最大的数，放在最右边，遍历n-1次；
内层遍历：将较大的数往后移，遍历n-1-i次；
*********************************************/
void maopao_sort(vector<int>& arr)
{
    for(int i=0; i < arr.size()-1; i++)
        for(int j = 0; j < arr.size()-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

/*********************************************
插入排序
外层遍历：从第二个数开始，将每个数插入左边序列的合适位置；
内层遍历：将第i个数左边所有比它大的数与其交换位置
*********************************************/
void charu_sort(vector<int>& arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i;
        for(; j > 0 && arr[j-1] > temp; j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}   

/*********************************************
快速排序
二分法，分割点选取第一个数
比分割点小的放到左边，比分割点大的放到右边
迭代排序左右子序列
*********************************************/
void quick_sort(vector<int>& arr, int begin, int end)
{
    if(begin > end)
        return;
    int temp = arr[begin];
    int i = begin;
    int j = end;
    while(i != j)
    {
        //要先从右往左找
        while(arr[j] >= temp && j>i)
            j--;
        //再从左往右找
        while(arr[i] <= temp && i<j)
            i++;
        if(i < j)//i和j相遇时不需要交换
        {
            int n = arr[j];
            arr[j] = arr[i];
            arr[i] = n;
        }
    }
    arr[begin] = arr[i];
    arr[i] = temp;
    quick_sort(arr, begin, i-1);
    quick_sort(arr, i+1, end);
}

/*********************************************
输入长度不确定的数组
输入行的结尾必须是数字
*********************************************/
void inputarr(vector<int>& arr)
{
    char c;
    int n = 0;
    cin >> n;
    arr.push_back(n);
    while((c = getchar()) != '\n')
    {
        cin >> n;
        arr.push_back(n);
    }
}

/*********************************************
输入长度不确定的数组
*********************************************/
void inputArr(vector<int>& arr)
{
    char c;
    while((c = getchar()) != '\n')
    {
        if(c != ' ')  
        {
            int n;
            ungetc(c, stdin);
            cin>>n;
            arr.push_back(n);
        }
    }
}

void display(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    vector<int> arr;
    cout << "Input a arr:" << endl;
    inputArr(arr);
    cout << "sorted arr is:" << endl;
    maopao_sort(arr);   
    // charu_sort(arr);
    //quick_sort(arr, 0, arr.size()-1);
    display(arr);
    return 0;
}