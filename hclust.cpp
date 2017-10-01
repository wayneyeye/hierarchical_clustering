#include<cmath>//lib for math
#include<typeinfo>
#include "hclust.h"
using std::sqrt;
using std::cout;
using std::cerr;
using std::endl;
namespace HCLUST{
// CLASS Vector
    Vector::Vector(){
        cerr<<"Warning: Default Constructor Used!"<<endl; 
    }

    Vector::Vector(const Vector & v1){
        if (v1.length>0){
            cords=new double[v1.length];
            for (int i=0;i<v1.length;i++){
                cords[i]=v1.cords[i];
            }
            length=v1.length;
            ID=v1.ID;
        }
        else{
            cerr<<"Error: The Length of the Vector being Copied is 0!"<<endl;
        }
    }

    Vector::Vector(int len, double* c, long id){
        if (len>0){
            cords=new double[len];
            for (int i=0;i<len;i++){
                cords[i]=c[i];
            }
            length=len;
            ID=id;
        }
        else{
            cerr<<"Error: The Length of the Input Vector is 0!"<<endl;
        }
    }
    
    Vector Vector::operator+(const Vector & v2) const{
        if (length==v2.length){
            double cords_new[length];
            for (int i=0;i<length;i++){
                cords_new[i]=cords[i]+v2.cords[i];
            }
            Vector v_new=Vector(length,cords_new);
            return v_new;
        }
        else{
            cerr<<"Error: Lengths of Vectors Do not Match!"<<endl;
        }
    }

    Vector Vector::operator-(const Vector & v2) const{
        if (length==v2.length){
            double cords_new[length];
            for (int i=0;i<length;i++){
                cords_new[i]=cords[i]-v2.cords[i];
            }
            Vector v_new=Vector(length,cords_new);
            return v_new;
        }
        else{
            cerr<<"Error: Lengths of Vectors Do not Match!"<<endl;
        }
    }
    
    Vector Vector::operator-() const{
        if (length>0){
            double cords_new[length];
            for (int i=0;i<length;i++){
                cords_new[i]=-cords[i];
            }
            Vector v_new=Vector(length,cords_new);
            return v_new;
        }
        else{
            cerr<<"Error: Length of Vector is Zero!"<<endl;
        }
    }

    double Vector::mode() const{
        if (length>0){
            double total=0;
            for (int i=0;i<length;i++){
                total+=cords[i]*cords[i];
            }
            return sqrt(total);
        }
        else{
            cerr<<"Error: Length of Vector is Zero!"<<endl;
            return -1;
        }
    }

    std::ostream & operator<<(std::ostream & os, const Vector &v){
        os<<"Vector "<<v.ID<<":[ ";
        for (int i=0;i<v.length;i++){
            os<<v.cords[i]<<" ";        
        }
        os<<"]"<<endl;
        return os;
    }

    Vector::~Vector(){
        delete [] cords;
    }
//END of CLASS Vector
//ClASS Cluster
    Cluster::Cluster(){
        cerr<<"Error: Illegal call Cluster() Directly!"<<endl;
    }
    Cluster::Cluster(Vector & v1){
        Node * add= new Node;
        add->p_next=NULL;
        add->v = &v1;
        rear=front=add;
        update_centroid();
        num_nodes=1;        
    } 
    Cluster::Cluster(const Cluster & c){
        //cout<<c;
        num_nodes=0;
        Node * temp=c.front;
        for(int i=1;i<=c.num_nodes;i++){
           cout<<*(temp->v);
           add_node(*(temp->v));
           if(num_nodes==1){
           front=rear;
           } 
            temp=temp->p_next;
        }    
    }
    
    Cluster Cluster::operator+(const Cluster & c2) const {

      for(int i=1;i<=(num_nodes+c2.num_nodes);i++)
      {
      
      }
    }
    void Cluster::add_node(Vector & v1){ //add vector to cluster without update centroid
       Node * add=new Node;
       add->p_next=NULL;
       add->v=&v1;
       rear->p_next=add;
       rear=add;
       num_nodes++;
    }
    void Cluster::update_centroid(){
    }
    //Destructor
    Cluster::~Cluster(){
        for(int i=1;i<=num_nodes;i++){
            Node * temp=front;
            front=front->p_next;
            delete temp;
        }
    }

    std::ostream & operator<<(std::ostream & os, const Cluster & c){
        Cluster::Node * temp=c.front;
        cout<<"Cluster "<<c.cluster_name<<":"<<endl;
        for(int i=1;i<=c.num_nodes;i++){
            cout<<*(temp->v);
            temp=temp->p_next;
        }
        cout<<"End of Cluster "<<c.cluster_name<<endl;
    }
//END of CLASS Cluster
}//end namespace HCLUST 
