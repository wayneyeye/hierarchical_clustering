#include<cmath>//lib for math
#include "hclust.h"
using std::sqrt;
using std::cout;
using std::endl;
using HCLUST::Vector;
using HCLUST::Cluster;
int main(){
    {
    //Test of create vectors
    double a1[2]={1,1};
    Vector v1=Vector(2,a1,1);
    cout<<v1;
    double a2[2]={2,3};
    Vector v2=Vector(2,a2,2);
    //Test of overloading operators for vectors
    cout<<v2;
    cout<<-v1+v2;
    cout<<-v2;
    cout<<v1-v2;
    cout<<v2.mode()<<endl;
    cout<<v1.mode()<<endl;
    //Test of create cluster
    Cluster c1(v1);
    cout<<c1;
    //Add a vector to cluster
    c1.add_node(v2);
    c1.add_node(v1);
    cout<<c1;
    //Copy a cluster
    Cluster c2=Cluster(c1);
    //cout<<c2;
    }

    return 0;
}
