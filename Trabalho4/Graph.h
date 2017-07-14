#include "Includes.h"
#include "Ant.h"

struct City{
    int id;
    double x;
    double y;
};

struct Edge{
    double tij;
    double deltatij;
    int id1;
    int id2;
};

class Graph{
    
    static vector<City> data;
    vector<Ant> antvector;
    double **adjacencymatrix;
    Edge *edge;
    
public:

    Graph();
    void allocmatrix();
    double euclidiandistance(double x1 , double y1 , double x2 , double y2);
    void addEdges();
    void setEdge(Edge e);
    bool getEdge(int v1, int v2, Edge *p);
    void setMatrix();
    void printPheromone();
    void printAdjacency();
    vector<int> getNeighbor(vector<int> path);
    map<int,double> probability(Ant a);
    int roulette(map<int,double> m, vector<int> neighbor);
    void setAnt();
    void printAntvector();
    vector<Ant> getAntvector();
    void Execute();
    void Antvector();
    double getDistance(int i, int j);
    int sizedata();
    
};