#include<cmath>//lib for math
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
        }
    }

    std::ostream & operator<<(std::ostream & os, const Vector &v){
        os<<"Vector "<<v.ID<<":[ ";
        for (int i=0;i<v.length;i++){
            os<<v.cords[i]<<" ";        
        }
        os<<"]"<<endl;
    }

    Vector::~Vector(){
        delete [] cords;
    }
//END of CLASS Vector
}//end namespace HCLUST 
