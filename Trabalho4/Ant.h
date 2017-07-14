#include "Includes.h"

typedef struct auxedge{
    int u;
    int v;
}Auxedge;

class Ant{
    vector<int> path;
    vector<int> vizinhos;
    double length;
    int current_city;
    Auxedge last_edge;

public:
    void setPath(int n);
    vector<int> getPath();
    void setVizinhos(vector<int> n);
    vector<int> getVizinhos();
    void removeVizinho(int n);
    void setLength(double length);
    double getLength();
    void setCurrent_city(int current_city);
    int getCurrent_city();
    void setLast_edge(int u, int v);
    Auxedge getLast_edge();
};