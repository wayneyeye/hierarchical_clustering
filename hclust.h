#ifndef HCLUST_H_
#define HCLUST_H_ //check if head file loaded
#include<iostream>
#include<string>
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

    class Cluster
    {
        private:
            struct Node {Node * p_next; Vector * v=NULL;};
            Node * front=NULL;
            Node * rear=NULL;
            std::string cluster_name="Default";
            Vector centroid;
            long num_nodes;
        public:
            explicit Cluster();
            explicit Cluster(Vector & v1);
            Cluster(const Cluster & c);
            ~Cluster();
            Cluster & operator=(const Cluster & c2);
            Cluster operator+(const Cluster & c2) const;//combine clusters
            void add_node(Vector & v);
            void update_centroid();
            //friends
            friend std::ostream & operator<<(std::ostream & os, const Cluster & c);//show nodes
    };
}//end namespace HCLUST
#endif
