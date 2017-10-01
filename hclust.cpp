#include<cmath>//lib for math
#include<typeinfo>
#include "hclust.h"
using std::sqrt;
using std::cout;
using std::cerr;
using std::endl;
namespace HCLUST{
// CLASS Vector
    long Vector::num_vectors=0;
    Vector::Vector(){
        num_vectors++;
    //    cerr<<"Warning: Default Constructor Used! Address: "<<this<<endl; 
    }

    Vector::Vector(const Vector & v1){
        //cout<<"inside of the Vector::Vector(const Vector & v1)"<<endl;
        if (v1.length>0){
            cords=new double[v1.length];
          //  cout<<"inside if v1.length\n";
            for (int i=0;i<v1.length;i++){
                cords[i]=v1.cords[i];
            }
            length=v1.length;
            ID=v1.ID;
            num_vectors++;
        //    cout<<"New Vector Created Address: "<<this<<endl;
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
            num_vectors++;
        //    cout<<"New Vector Created Address: "<<this<<endl;
        }
        else{
            cerr<<"Error: The Length of the Input Vector is 0!"<<endl;
        }
    }
    
    Vector & Vector::operator=(const Vector & v1) {
        int l=v1.get_length();
        if (l>0){
            double* temp =cords;
            delete [] temp;
            cords=new double [l];
            for (int i=0;i<l;i++){
                cords[i]=v1[i];
                length=l;
                ID=-2;
            }
            return *this;
        }
        else{
            cerr<<"Error: The Length of the Vector being Copied is 0!"<<endl;
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

    Vector Vector::operator*(double m) const{
        if (length>0){
            double cords_new[length];
            for (int i=0;i<length;i++){
                cords_new[i]=cords[i]*m;
            }
            Vector v_new=Vector(length,cords_new);
            return v_new;
        }
        else{
            cerr<<"Error: Lengths of Vectors is Zero!"<<endl;
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

    void Vector::changeID(long id){
        ID=id;
    }
    std::ostream & operator<<(std::ostream & os, const Vector &v){
        os<<"Vector "<<v.ID<<"("<<v.length<<")"<<":[ ";
        for (int i=0;i<v.length;i++){
            os<<v.cords[i]<<" ";        
        }
        os<<"]"<<endl;
        return os;
    }

    Vector::~Vector(){
        //cout<<"Vector"<<" freed! at:"<<this<<" content:"<<*this;
        num_vectors--;
        delete[] cords;
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
        num_nodes=1;        
        update_centroid();
    } 
    Cluster::Cluster(const Cluster & c){
        //cout<<c;
        num_nodes=0;
        Node * temp=c.front;
        for(int i=1;i<=c.num_nodes;i++){
           //cout<<*(temp->v);
           add_node(*(temp->v));
           if(num_nodes==1){
           front=rear;
           } 
            temp=temp->p_next;
        }    
    }
    
    Cluster Cluster::operator+(const Cluster & c2) {
        Cluster new_cluster=Cluster(*this);
//        cout<<new_cluster;
        Node * temp=c2.front;
      for(int i=1;i<=(c2.num_nodes);i++)
      {
        new_cluster.add_node(*(temp->v));
        temp=temp->p_next;
      }
      new_cluster.update_centroid();
      return new_cluster;
    }

    void Cluster::add_node(Vector & v1){ //add vector to cluster without update centroid
       Node * add=new Node;
       add->p_next=NULL;
       add->v=&v1;
       if(rear!=NULL )
           rear->p_next=add;
       else
           front=add;
       rear=add;
       num_nodes=num_nodes+1;
    }

    void Cluster::update_centroid(){
//       cout<<"at update_centroid()\n";
        Node * temp=front;
        //cout<<"num_nodes: "<<num_nodes<<endl;
        Vector vec_total=Vector(*(temp->v));
        for(int i=1;i<=num_nodes;i++){
        //    cout<<"loop "<<i<<endl;
            if(i==1)
            {}
            else{
               //cout<<vec_total;
          //     cout<<"add: "<<*(temp->v);
            //   cout<<vec_total+*(temp->v);
               vec_total=vec_total+*(temp->v);
              // cout<<"total: "<<vec_total;
            }
            temp=temp->p_next;
        }
        double m=1.0/num_nodes;
       // cout<<"m="<<m<<endl;
       // cout<<"total: "<<vec_total;
        centroid=vec_total*m;
        centroid.changeID(-1);
       // cout<<centroid;
    }

    void Cluster::show_centroid(){
        cout<<"centroid: "<<centroid;
    }

    //Destructor
    Cluster::~Cluster(){
        //cout<<"Cluster Freed!"<<endl;
        for(int i=1;i<=num_nodes;i++){
            Node * temp=front;
            front=front->p_next;
            delete temp;
        }
    }

    std::ostream & operator<<(std::ostream & os, const Cluster & c){
        Cluster::Node * temp=c.front;
        cout<<"Cluster "<<c.cluster_name<<" has "<<c.num_nodes<<" nodes:"<<endl;
        for(int i=1;i<=c.num_nodes;i++){
            cout<<*(temp->v);
            temp=temp->p_next;
        }
        cout<<"with Centroid:"<<c.centroid;
        cout<<"End of Cluster "<<c.cluster_name<<endl<<endl;
    }
//END of CLASS Cluster
}//end namespace HCLUST 
