#include "Ant.h"

void Ant::setPath(int n){
    this->path.push_back(n);
}
vector<int> Ant::getPath(){
    return this->path;
}
void Ant::setLength(double length){
    this->length = length; 
}
double Ant::getLength(){
    return this->length;
}
void Ant::setCurrent_city(int current_city){
    this->current_city = current_city;
}
int Ant::getCurrent_city(){
    return this->current_city;
}
void Ant::setLast_edge(int u, int v){
    last_edge.u = u;
    last_edge.v = v;
}
auxedge Ant::getLast_edge(){
    return last_edge;
}

void Ant::setVizinhos(vector<int> n){
	vizinhos = n;
}
vector<int> Ant::getVizinhos(){
	return vizinhos;
}

void Ant::removeVizinho(int n){
    auto it = find(vizinhos.begin(), vizinhos.end(), n);
    if(it != vizinhos.end())
        vizinhos.erase(it);
}