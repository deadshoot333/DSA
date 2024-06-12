#include <bits/stdc++.h>
#define int long long
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void BubbleSort(vector<int> &a)
{
    // bubble sort
    int n = a.size();
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
int32_t main()
{

    FastIO();
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    BubbleSort(a);
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}