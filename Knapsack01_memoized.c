#include <bits/stdc++.h>
using namespace std;
int t[100][100];

int knapsack(int val[],int wt[],int n,int w) {
    if (w == 0 || n == 0)
        return 0;

    if(t[n][w]!=-1)
        return t[n][w];

    if (wt[n - 1] > w)
        return t[n][w]=knapsack(val, wt, n - 1, w);
    else
    {
        return t[n][w]= max(
                knapsack(val, wt, n - 1, w),val[n-1]+ knapsack(val, wt, n - 1, w-wt[n-1])
        );
    }



}
int main()
{
    memset(t,-1,sizeof(t));
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapsack(val,wt,n,W);
    return 0;
}
