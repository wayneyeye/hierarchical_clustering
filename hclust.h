#ifndef HCLUST_H_
#define HCLUST_H_ //check if head file loaded
#include<iostream>
namespace HCLUST
{
    class Vector
    {
        private:
            int length=0;
            double * cords=NULL;
            long ID=0;
        public:
            explicit Vector();
            Vector(const Vector &);
            Vector(int len,double * c, long id=0);
            ~Vector();
            Vector operator+(const Vector & v2) const; 
            Vector operator-(const Vector & v2) const; 
            Vector operator-() const;
            double mode() const;
            //friends
            friend std::ostream & operator<<(std::ostream & os,const Vector & v); 
    };//class def
}//end namespace HCLUST
#endif
