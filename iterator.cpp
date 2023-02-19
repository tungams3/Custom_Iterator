#include<iostream>
#include "vector.h"
#include<vector>
using namespace std;
int main()
{
    Vector<int>values;
    values.pushback(5);
    values.pushback(6);
    values.pushback(7);
    values.pushback(8);
    values.pushback(9);
    Vector<int>::Iterator itr;
    for(itr=values.begin();itr!=values.end();itr++)
    {
        cout<<*itr<<endl;
    }
    return 0;
}