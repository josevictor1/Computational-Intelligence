#include "Graph.h"

#define exec 5

int main(int argc, const char* argv[]){
    double media_geralpath = 0;
    float media_geraltempo = 0;
    size_t x;
    for(x = 0; x <50*exec; x++){        
        Graph g;
        //cout << "passou ";
        g.allocmatrix();
        g.setMatrix();
        //g.printAdjacency();
        //g.printPheromone();
        g.setAnt();
        vector<Ant> a = g.getAntvector();
        srand(time(NULL));
        double past = 0;
        bool stop = false;
        int flag = 0;
        time_t t,t_begin,t_end;
        float timeprogram;

        t_begin = time(NULL);
        while(!stop){
            for(Ant& i: a){
                int j = 0;
                double total = 0;
                map<int,double> probs;
                
                if(flag < g.sizedata()){
                    i.setVizinhos((g.getNeighbor(i.getPath())));
                    flag++;    
                }
                    
                probs = g.probability(i);

                for(int &k: i.getVizinhos()){
                    total += probs[k];
                }
                //cout<< "passou";
                //cout<<"total" << total<<endl;
                vector<int> neighbor = i.getVizinhos();
                std::default_random_engine generator;
                std::normal_distribution<double> d1(0.0,total);

                double value, sum = 0;
                int rept = 0 , help;
                help = rand()*10000%100;

                while(rept < help){
                    rept++;
                    value = d1(generator);
                }

                
                while(value > total || value < 0 || past == value){
                    value = d1(generator);
                }

                //cout << "aleatorioooooo " << value<< endl;
                
                past = value;
                sum = probs[neighbor[0]];

                while(sum < value){
                    j++;
                    sum = sum + probs[neighbor[j]];
                }

                //cout<< neighbor[j]<< endl; 
                i.setLength(i.getLength() + g.getDistance(i.getCurrent_city()-1,neighbor[j]-1));
                i.setLast_edge(i.getCurrent_city(), neighbor[j]);
                i.setCurrent_city(neighbor[j]);
                i.setPath(neighbor[j]);
                i.removeVizinho(neighbor[j]);         
            }

            for(size_t i = 0; i < (g.sizedata()*(g.sizedata()-1)/2); i++) {
                for(size_t j = 0; j < (g.sizedata()*(g.sizedata()-1)/2); j++) {
                    double aux,sum = 0;
                    Edge auxe;
                    if(g.getEdge(i,j,&auxe)){
                        aux = P*auxe.tij;
                        for(Ant& k: a){
                            Auxedge auxe1 = k.getLast_edge();
                            if((auxe1.u == auxe.id1 && auxe1.v == auxe.id2)||(auxe1.u == auxe.id2 && auxe1.v == auxe.id1)){
                                sum += Q/k.getLength(); 
                            }
                        }
                        auxe.tij = aux + sum;
                        g.setEdge(auxe);
                    }
                }                   
            }

            int verify = 0;
            for(Ant& i: a){
                if(i.getPath().size() == g.sizedata())
                    verify++;
            }

            if(verify == g.sizedata()){
                stop = true;
            }
        }

        Ant min = a[0];
        for(Ant& i: a){
            vector<int> auxpath;
            auxpath = i.getPath();
            i.setLength(g.getDistance(i.getCurrent_city()-1, auxpath[0]-1) + i.getLength());
            i.setPath(auxpath[0]);
            i.setCurrent_city(auxpath[0]);
            if(min.getLength() > i.getLength()){
                min = i;
            }        
        }
        t_end = time(NULL);
        timeprogram = difftime(t_end, t_begin);
        cout << "Configurações: "<< endl;
        cout<< "ALFA"<< ALFA<<endl;
        cout<< "BETA"<< BETA<<endl; 
        cout<< "p"<<P<<endl;
        cout<< "Q"<<Q<<endl;

        cout << "Comprimento do caminho:" << min.getLength()<<endl;

        for(int& i: min.getPath()){
            cout << i <<" ";
        }
        cout << endl;
        media_geralpath += min.getLength();
        media_geraltempo+=timeprogram;
    }

    cout << " Média em "<< exec << " execuções" << endl;
    cout << "Tempo: " << media_geraltempo/x <<endl;
    cout << "Caminho " << media_geralpath/x <<endl;



    //g.getAntlist();
    //g.Execute();
    //g.getAntvector();
    //Distribution(0,1);
    //Random random;
/*
  std::default_random_engine generator;
  std::normal_distribution<double> d1(0.0,1.0);
  std::normal_distribution<double> d2(d1.param());

  // print two independent values:
  std::cout << d1(generator) << std::endl;
  std::cout << d2(generator) << std::endl;
  for(size_t i = 0; i <10;i++)
       std::cout << d1(generator) << std::endl;
 */   
   //cout << Distribution(random) << endl;



}