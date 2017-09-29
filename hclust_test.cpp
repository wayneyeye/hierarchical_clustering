#include<cmath>//lib for math
#include "hclust.h"
using std::sqrt;
using std::cout;
using std::endl;
using HCLUST::Vector;
int main(){
    {
    double c1[2]={1,1};
    Vector v1=Vector(2,c1,1);
    cout<<v1;
    double c2[2]={2,3};
    Vector v2=Vector(2,c2,2);
    cout<<v2;
    cout<<-v1+v2;
    cout<<-v2;
    cout<<v1-v2;
    cout<<v2.mode()<<endl;
    cout<<v1.mode()<<endl;
    }
    return 0;
}
