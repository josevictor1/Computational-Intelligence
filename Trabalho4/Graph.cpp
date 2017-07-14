#include "Graph.h"

vector<City> Graph::data = vector<City>();

Graph::Graph(){
    if (data.empty() ) {
		ifstream file;

		try {
			file.open("teste0.txt");

			// for (int i = 0; i < 366; i++) {
			while ( file.good() ) {
				City c;

				file >> c.id;
				file >> c.x;
				file >> c.y; 

				//cout << "data" <<endl;
				//cout << c.id << "   ";
				//cout << c.x <<" ";
				//cout << c.y;

				data.push_back(c);
			}
			//cout << "ddata size "<< data.size();
		}
		
		catch (exception&) {}
		file.close();
		
	}
}

void Graph::addEdges(){

	int n = data.size();
	int edges = (n*(n-1))/2;

	for(size_t i = 0; i < edges; i++){
		for(size_t j = 0; j < edges; j++){
			
		}	
	}
	
}

bool Graph::getEdge(int v1, int v2, Edge *p){
	int n = data.size();
	int edges = (n*(n-1))/2;
	//cout << "edges  " << edges<<"  " << endl;
	
	for(size_t i = 0; i < edges; i++){
		if((edge[i].id1 == v1 && edge[i].id2 == v2) || (edge[i].id1 == v2 && edge[i].id2 == v1)){
			*p = edge[i];
			return true;
		}
	}

	return false;
}


void Graph::allocmatrix(){
	//cout << "passou"<< ;
	int n = data.size();
	int edges = (n*(n-1))/2;
	adjacencymatrix = (double**)malloc(n * sizeof(double*));
	edge = (Edge*)malloc(edges * sizeof(Edge));
	

	for (size_t i = 0; i < n; i++){

		adjacencymatrix[i] = (double*) malloc(edges * sizeof(double));

		for (size_t j = 0; j < n; j++){ 
			adjacencymatrix[i][j] = 0;
		}
	}
	
	for(size_t i = 0; i < edges; i++){
		
		edge[i].tij = 1;
		edge[i].deltatij = 0;
		
	}

}

double Graph::euclidiandistance(double x1 , double y1 , double x2 , double y2){
	//if(sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) == 0)
	//	cout << "deu rum aki" << x1 << y1 << x2 << y2 << endl;

	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

void Graph::setMatrix(){

	int n = data.size(); 
	int count = 0;
	int edges = (n*(n-1))/2;
	Edge p;
	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < n; j++){
			adjacencymatrix[i][j] = euclidiandistance(data[i].x,data[i].y,data[j].x,data[j].y);
			//cout << adjacencymatrix[i][j] << " ";
			if(!getEdge(i+1,j+1,&p) && i != j){
				edge[count].id1 = i+1;
				edge[count].id2 = j+1;
				count = (count +1)%edges;	
			}
		}
		//cout << endl;
	}

}

void Graph::printPheromone(){
	int edges = (data.size() * (data.size() - 1))/2;
	for(size_t i = 0; i < edges; i++){
		cout << edge[i].id1 << " ";
		cout << edge[i].id2<<":";

		cout << edge[i].tij << endl;
	}
	cout << endl;
}

void Graph::printAdjacency(){
	int n = data.size();
	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < n; j++){
			cout << adjacencymatrix[i][j] << " ";		
		}
		cout << endl;
	}
}

vector<int> Graph::getNeighbor(vector<int> path){
	
	vector<int> neighbor;
	//bool verifier = false;

	for(size_t i = 0; i < data.size(); i++){
		for(int &j: path){
			if(j != i+1)
				neighbor.push_back(i+1);
		}
	}

	return neighbor;
}



int Graph::roulette(map<int,double> m, vector<int> neighbor){
	
	int j = 0;

	/*
	for(int &i: neighbor){
		total += m[i];
		cout <<m[i] << endl;
	}
//cout<< total;
	
	int randomico = rand()%t;
	cout << randomico;
	

	sum = m[neighbor[0]];

	while(sum < (double) randomico){
		j++;
		sum = sum + m[neighbor[j]];
	}*/

	return neighbor[j];

}

map<int,double> Graph::probability(Ant a){
	map<int,double> probs;
	
	double result1 = 0, result2 = 0; 
	Edge e;
	/*cout << "neighbor" << endl;
	for(int &i: a.getVizinhos()){
		cout << i <<" "; 
	}
	cout << endl;*/

	for(int &i: a.getVizinhos()){	 
		getEdge(a.getCurrent_city(), i, &e);
		//cout << adjacencymatrix[a.getCurrent_city() - 1][i-1] << endl;
		//if(adjacencymatrix[a.getCurrent_city() - 1][i-1] ==0){
		//	cout << "i "<< a.getCurrent_city() - 1<< endl;
		//	cout <<"j "<< i-1 << endl;
			//printAdjacency();
		//}
		double aux = 1 / (adjacencymatrix[a.getCurrent_city() - 1][i-1]);
		//cout <<aux << endl;
		result2 += pow(e.tij, ALFA)*pow(aux,BETA); 
	}
	//cout << result2<< endl;

	for(int &i: a.getVizinhos()){
		result1 = 0; 
		//cout << "i0 " << i << endl;
		//cout <<"segundo for "<< endl;
		getEdge(a.getCurrent_city(), i, &e);
		//cout << "passou get edge" << endl;
		//cout << "i " << i << endl;
		//cout <<  "a" << a.getCurrent_city() - 1 << endl;
		double aux = 1/(adjacencymatrix[a.getCurrent_city() - 1][i-1]);
		//cout << "passou matriz " << endl;
		result1 = pow(e.tij,ALFA)*pow(aux,BETA);
		//cout << "passou conta " << endl;
		//cout <<" probs "<< result1/result2<< endl; 
		probs[i] = result1/result2;
		//cout <<" passou probs "<< endl;
		//cout << "i " << i << endl;
	}

	//cout <<"passou aqui";
	return probs;
	//int r = roulette(probs,neighbor);
	//cout<<"roleta:" << r<< endl;
	//a.setCurrent_city(r);
	
}

void Graph::setAnt(){

	for(size_t i = 0; i < data.size(); i++){
		Ant a;
		a.setCurrent_city(i+1);
		a.setLength(0);
		a.setPath(i+1);
		antvector.push_back(a);
	}
}

void Graph::printAntvector(){

	for(Ant& i: antvector){
		cout << i.getCurrent_city()<< endl;
	}
}

vector<Ant> Graph::getAntvector(){
	return antvector;
}

double Graph::getDistance(int i, int j){
	return adjacencymatrix[i][j];
}

void Graph::setEdge(Edge e){
	int n = (data.size()*(data.size()-1))/2;
	for(size_t i = 0; i < n; i++){
		if(e.id1 == edge[i].id1 && e.id2 == edge[i].id2){
			edge[i] = e;
		}
	}
}

int Graph::sizedata(){
	return data.size();
}



//void Graph::Execute(){
	//for(Ant& i: antvector){
		//probability(i);
	//}
//}



