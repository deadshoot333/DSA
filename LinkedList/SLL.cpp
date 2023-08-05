#include<bits/stdc++.h>
#include"SLL.h"
using namespace std;
int main()
{
    SLL l;
    l.insert_last(10);
    l.insert_last(9);
    l.insert_last(8);
    l.insert_last(7);
    l.insert_last(6);
    l.display();
    l.reverse_list();
    l.display();
    l.loop(1);
    cout<<l.DetectLoop()<<"\n";
}