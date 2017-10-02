#ifndef HCLUST_H_
#define HCLUST_H_ //check if head file loaded
#include<iostream>
#include<string>
namespace HCLUST
{
    class Vector
    {
        private:
            double * cords=NULL;
            long ID=0;
            int length=0;
        public:
            static long num_vectors;
            explicit Vector();
            Vector(const Vector &);
            Vector(int len,double * c, long id=0);
            ~Vector();
            Vector & operator=(const Vector & v2); 
            Vector operator+(const Vector & v2) const; 
            Vector operator-(const Vector & v2) const; 
            Vector operator-() const;
            Vector operator*(double m) const;
            double operator[](int j) const{return cords[j];};
            int get_length() const{return length;};
            double mode() const;
            void changeID(long id);
            //friends
            friend std::ostream & operator<<(std::ostream & os,const Vector & v); 
            friend Vector operator*(double m, const Vector & v){
                return v*m;
            }            
    };//class def

    class Cluster
    {
        private:
            struct Node {Node * p_next; Vector * v=NULL;};
            Node * front=NULL;
            Node * rear=NULL;
            std::string cluster_name="Default";
            long num_nodes;
        public:
            Vector centroid;
            explicit Cluster();
            explicit Cluster(Vector & v1);
            Cluster(const Cluster & c);
            ~Cluster();
            Cluster operator=(const Cluster & c2);
            Cluster operator+(const Cluster & c2) ;//combine clusters
            void add_node(Vector & v);
            void update_centroid();
            void show_centroid();
            //friends
            friend std::ostream & operator<<(std::ostream & os, const Cluster & c);//show nodes
    };
     
    class Hclustering
    {
        private:
            struct Pair {
                Pair * p_next=NULL;
                Cluster * a=NULL;
                Cluster * b=NULL;
                double distance;
            };
            Pair * front=NULL;
            Pair * rear=NULL;
      
        public:
            explicit Hclustering();
            ~Hclustering();
            void add_pair_to_end(Cluster * a, Cluster * b);
            void add_pair(Cluster * a, Cluster * b);
            Pair pop_pair();
    };
}//end namespace HCLUST
#endif
