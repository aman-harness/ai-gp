#include <iostream>
using namespace std;
const int DefultVertices = 50;

template <class T>
class Graph{
public:
       Graph(int sz = DefaultVertices);
       ~Graph();
       bool GraphEmpty() const{
            if (numedges == 0) return true;
            else return false;
       }
       bool GraphFull() const{
            if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices -1) / 2) return true;
            else return false;
       }
       int NumberOfVertices(){return numVertices;}
       int NumberOfEdges(){return numEdges;}
       virtual T getValue(int i)=0;
       //virtual E getWeight(int v1,int v2)=0;
       virtual int getFirstNeighbor(int v)=0;
       virtual int getNextNeighbor(int v,int w)=0;
       virtual bool insertVertex(const T vertex)=0;
       virtual bool insertEdge(int v1,int v2/*,E cost*/)=0;
       virtual bool removeVertex(int v)=0;
       virtual bool removeEdge(int v1,int v2)=0;
protected:
          int maxVertices;
          int numEdges;
          int numVertices;
          int getVertexPos(T vertex);
};

template <class T>
//template <class T, class E>
struct Edge {
       int dest;
       //E cost;
       Edge<T> *link;
       //Edge<T,E> *link;
       Edge(){};
       Edge(int num) : dest(num) ,link (NULL){}
       //Edge(int num ,E weight) : dest(num), cost(weight) ,link (NULL){}
       bool operator != (Edge<T>& R)const {
            return (dest != R.dest) ? true : false;
       }
       /*bool operator != (Edge<T,E>& R)const {
            return (dest != R.dest) ? true : false;
       }*/
};

template <class T>
//template <class T,class E>
struct Vertex {
       T dada;
       Edge<T> *adj;
       //Edge<T,E> *adj;
};

template <class T>
//template <class T,class E>
class GraphInk :public Graph<T>{
      friend istream& operator >>(ifstream & in,GraphInk<T>& G);
      friend ostream& operator >>(ofstream & out,GraphInk<T>& G);
public:
       GraphInk(int sz = DefaultVertices);
       ~GraphInk();
       T getValue(int i){return (i >= 0 && i < numVertices)?NodeTable[i].data:0;};
       //E getWeight(int v1,int v2);
       int getFirstNeighbor(int v);
       int getNextNeighbor(int v,int w);
       bool insertVertex(const T vertex);
       bool insertEdge(int v1,int v2/*,E cost*/);
       bool removeVertex(int v);
       bool removeEdge(int v1,int v2);
private:
        Vertex<T> *NodeTable;
        //Vertex<T,E> *NodeTable;
        int getVertexPos(const T vertex){
            for (int i = 0; i < numVertices;i++)
                if(NodeTable[i].data == Vertex) return i;
            return -1;
        }
};

template <class T>
GraphInk<T>::GraphInk(int sz) {
         maxVertices = sz;
         munVertices = 0;
         numEdges = 0;
         NodeTable = new Vertex <T>[maxVertices];
         if(NodeTable == NULL){cerr << "´æ´¢·ÖÅä´íÎó!" <<endl; exit(1);}
         for( int i = 0; i< maxVertices ; i++) NodeTable[i].adj = NULL;
};

template <class T>
GraphInk<T>::~GraphInk() {
         for( int i = 0; i< maxVertices ; i++) {
              Edge<T> *p = NodeTable[i].adj;
              while(p != NULL) {
                  NodeTable[i].adj = p->link;
                  delete p;
                  p = NodeTable[i].adj;
              }
         }
         delete [] NodeTable;
};

template <class T>
int GraphInk<T>::getFirstNeighbor(int v) {
      if ( v! = -1 ){
           Edge <T> *P = NodeTable[v].adj;
           if (p! = NULL) return p->dest;
      }
      return -1;
};

template< class T,class E >
int Graphlnk<T>::getNextNeighbor(int v,int w) {
    if(v != -1){
         Edge<T> *p = NodeTable[v].adj;
         while( p != NULL && p->dest != w) p = p -> link;
         if(p != NULL && p ->link != NULL) return p -> link -> dest;
    }
    return -1;
};

template <class T>
bool GraphInk
template <class T>
istream& operator >>(ifstream & in,GraphInk<T>& G){
         int i,j,k,n,m;T e;
         in >> n;
         for(i =1 ;i <= n; i++){
               in >> e
/*
template <class T>
void DFS(Graph<T>& G,const T& v){
     int i, loc, n = G.NumberOfVertices();
     bool* visited = new bool[n];
     for(i = 0 ; i < n; i++) visited[i] = false;
     loc = G.getVertexPos(v);
     DFS(G ,loc ,visited);
     delete [] visited;
};
*/
template <class T>
void DFS(Graph<T>& G){
     int i, n = G.NumberOfVertices();
     bool* visited = new bool[n];
     for(i = 0 ; i < n; i++) visited[i] = false;
     DFS(G ,0 ,visited);
     delete [] visited;
};

template <class T>
void DFS(Graph<T>& G,int v,bool visitd[]){
     cout<< G.getValue(v)<<' ';
     visited[v] = true;
     int w = G.getFirstNeighbor(v);
     while( w! = -1){
         if(visited[w] == false)DFS(G,w,visited);
         w = G.getNextNeighbor(v,w);
     }
};
      
int a[1000],n,f[1000][1000];
int main(){
    int i,j,m,x,y;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    i=0;
    while(cin){
        cin>>x>>y;
        cin>>f[x][y];
        i++;
    }
    m = i-1;
    while(1);
    return 0;
}
