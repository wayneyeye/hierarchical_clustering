#include<cmath>//lib for math
#include "hclust.h"
using std::sqrt;
using std::cout;
using std::endl;
using HCLUST::Vector;
using HCLUST::Cluster;
using HCLUST::Hclustering;
int main(){
    {
    //Test of create vectors
    //cout<<endl<<"Test of Vectors:"<<endl<<endl;
    double a1[3]={5,12,7};
    Vector v1=Vector(3,a1,1);
    //cout<<v1;
    double a2[3]={4,3,2};
    Vector v2=Vector(3,a2,2);
    //cout<<v2;
    Vector v3=v2;
    v3.changeID(3);
    cout<<v3;
    Vector v4=Vector(v1);
    //cout<<v4;
    //Test of overloading operators for vectors
    cout<<"-v1+v2: "<<-v1+v2;
    //cout<<"-v2: "<<-v2;
    //cout<<"mode(v2)"<<v2.mode()<<endl;
    //cout<<"v1*15.5: "<<v1*15.5;
    //cout<<"2*v2: "<<2*v2;
    //cout<<"number of vectors: "<<Vector::num_vectors<<endl;
    //Test of create cluster
    cout<<endl<<"Test of Clusters:"<<endl<<endl;
    Cluster c1(v1);
    Cluster c2=Cluster(v2);
    
    cout<<"cluster 1:\n"<<c1;
    cout<<"cluster 2:\n"<<c2;
    //cout<<"combined:\n"<<c1+c2;
    Cluster c3=c1+c1+c2;
    cout<<"c3: "<<c3;
    cout<<"c1+c2: "<<c1+c2;
    cout<<"number of vectors: "<<Vector::num_vectors<<endl;
    //Test of create Hcluster
    cout<<endl<<"Test of Hclustering:"<<endl<<endl;
    Hclustering hc=Hclustering();
    hc.add_pair(&c1,&c2);
    hc.add_pair(&c1,&c2);
    hc.add_pair(&c1,&c2);
    hc.add_pair(&c1,&c2);
    hc.add_pair(&c1,&c2);
    }

    return 0;
}
