#include<iostream>
#include "vector.h"
using namespace std;
struct Vector_struct
{
    float x=0.0f,y=0.0f,z=0.0f;
    
    Vector_struct(){}
    Vector_struct(float scalar)
        :x(scalar),y(scalar),z(scalar){
            cout<<"Create obj\n";
        }
    Vector_struct(float x,float y,float z)
        :x(x),y(y),z(z){
            cout<<"Create obj\n";
        }
    /*Vector3(const Vector3& other)
        :x(other.x),y(other.y),z(other.z)
    { 
        cout<<"Copy\n";
    }*/
    /*
    Vector3(Vector3&& other)
        :x(other.x),y(other.y),z(other.z)
    {
        cout<<"Move";
    }
    */
    ~Vector_struct()
    {
        cout<<"Destroy\n";
    }
    Vector_struct& operator=(const Vector_struct& other)
    {
        cout<<"Copy\n";
        x=other.x;
        y=other.y;
        z=other.z;
        return *this;
    }
    Vector_struct& operator=(Vector_struct&& other)
    {
        cout<<"Move\n";
        x=other.x;
        y=other.y;
        z=other.z;
        return *this;
    }
};
template<typename T>
void PrintVector(const Vector<T>&vector)
{
    for(size_t i=0;i<vector.Size();i++)
        cout<<vector[i]<<endl;
    cout<<"-----------------\n";
}
void PrintVector(const Vector<Vector_struct>&vector)
{
    for(size_t i=0;i<vector.Size();i++)
        cout<<vector[i].x<<","<<vector[i].y<<","<<vector[i].z<<endl;
    cout<<"-----------------\n";
}
int main()
{
    /*Vector<Vector_struct> vector;
    vector.pushback(Vector_struct(1));
    vector.pushback(Vector_struct(2,3,4));
    vector.pushback(Vector_struct());
    vector.popback();
    PrintVector(vector);
    vector.Clear();
    PrintVector(vector);*/
    //test
    Vector<int>res;
    res.pushback(1);
    res.pushback(2);
    res.pushback(2);
    res.pushback(3);
    res.pushback(2);
    res.pushback(4);
    res.pushback(5);
    res.popback();
    PrintVector(res);
    return 0;
    cin.get();
}