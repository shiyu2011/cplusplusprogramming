#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

typedef char t_Vertex;
typedef int t_EdgeT;
#define MAX_VER 100
#define INFINITY 65536

typedef struct graph{
	t_Vertex vexs[MAX_VER];
        t_EdgeT arc[MAX_VER][MAX_VER];
	int nVertexs, nEdges;	
}s_graph;


void createGraph(s_graph *gh){
	std::cout << "input number of vertex and number of edge:"<<"\n";
	std::cin>>gh->nVertexs;
	std::cin>>gh->nEdges;
	std::cout << "input number of vertexe:"<<gh->nVertexs<<"\n";
	std::cout << "input number of edges:"<<gh->nEdges<<"\n";
	std::cout << "input vertex:"<<"\n";
	for (int i = 0; i<gh->nVertexs;i++){
		std::cin>>gh->vexs[i];
	}
	//init graph edge
	for (int i = 0; i<gh->nVertexs;i++){
		for (int j =0; j<gh->nVertexs; j++){
			gh->arc[i][j] = INFINITY;
		}

	}
	std::cout << "input edge position and weight:"<<"\n";
	int indr, indc;
	t_EdgeT tmp ;
	for (int i = 0; i<gh->nEdges; i++){
		std::cin>>indr;
		std::cin>>indc;
		std::cin>>tmp;
		gh->arc[indr][indc] = tmp;
		gh->arc[indc][indr] = tmp;
	}
}

void DFS(s_graph *gh, int i, bool *isAccess){
	for (int j = 0; j<gh->nVertexs; j++){
		if(j!=i && isAccess[j] ==false){
			isAccess[j] = true;
			std::cout<<"current node: "<<gh->vexs[i]<<"connected to: "<<gh->vexs[j]<<"\n";
			DFS(gh, j, isAccess);
		}	
	}
}
void tranverse_graph(s_graph *gh){
	bool isAccess[gh->nVertexs];
	for (int i = 0; i<gh->nVertexs; i++){
		isAccess[i] = false;
	}
	for (int i = 0; i<gh->nVertexs; i++){
		if(!isAccess[i]){
			isAccess[i] = true;
			DFS(gh, i, isAccess);
		}
	}
}
int main(){
	s_graph gh;
	createGraph(&gh);
	for (int i = 0; i<gh.nVertexs; i++)
		std::cout << "vertex:"<<gh.vexs[i]<<"\n";
	for (int i = 0; i<gh.nVertexs; i++){
		for (int j = 0; j<gh.nVertexs; j++){
			std::cout <<gh.arc[i][j]<<" ";
		}
		std::cout <<"\n";
	}
	tranverse_graph(&gh);
	return 1;
}
