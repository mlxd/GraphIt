//
// Created by Lee James O'Riordan on 23/07/15.
//

#define NUM_VORT 3

#include "../inc/lattice.h"
#include "../inc/node.h"
#include "../inc/edge.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <algorithm>

using namespace LatticeGraph;
unsigned int Edge::suid = 0;
unsigned int Node::suid = 0;

int main(){
	Lattice *l = new Lattice();

	std::shared_ptr<Node> n;//
	std::shared_ptr<Edge> e;

	//shared_ptr<Node> n( new int );

	Vtx::Vortex *v = (Vtx::Vortex*) malloc(sizeof(Vtx::Vortex)*NUM_VORT);
	for(int i=0; i < NUM_VORT; ++i) {
		v[i].coords.x = (i + 1) * NUM_VORT;
		v[i].coords.y = (i + 1) * NUM_VORT;
		n.reset(new Node(v[i]));
		l->Lattice::addVortex(n);
		//std::cout << "UID=" << l->getElement(i).getUid() << std::endl;
	}
	n=NULL;

	std::sort(l->getVortices().begin(),l->getVortices().end());

	e.reset(new Edge(l->getVortexIdx(0),l->getVortexIdx(1),0,0 ));
	l->addEdge(e);
	//l->addEdge(e,l->getElement(0),l->getElement(1));

	e.reset(new Edge(l->getVortexIdx(0),l->getVortexIdx(2),0,0 ));
	l->addEdge(e);

	e.reset( new Edge(l->getVortexIdx(1),l->getVortexIdx(2),0,0 ));
	l->addEdge(e);


	for (int ii=0; ii < 3; ++ii){
		std::cout << l->getVortices().at(ii)<< "    ";
		std::cout << l->getVortices().at(ii)->getUid()<< std::endl;
	}

	l->swapIdxUid(1,2);
	//std::swap(l->getVortices().at(l->getVortexIdxUid(1)),l->getVortices().at(l->getVortexIdxUid(2)));
	l->removeEdgeUid(1);
	std::vector< std::shared_ptr<Node> > s3;

	//std::sort(l->getVortices().begin(),l->getVortices().end());

	//std::set_intersection(l->getVortices().begin(),l->getVortices().end(),l->getVortices().begin(),l->getVortices().end(),s3);
	for (int ii=0; ii < 3; ++ii){
		std::cout << l->getVortices().at(ii)<< "    ";
		std::cout << l->getVortices().at(ii)->getUid()<< std::endl;
	}

	for(auto a : s3){
		std::cout << a << std::endl;
	}


	//l->removeEdgeUid(2);
	//l->removeVortexUid(2);
	//l->removeVortexUid(2);


	//l->removeEdge(l->getVortexUid(1),l->getVortexUid(2));
	//l->removeVortexIdx(0);
	//l->removeEdge(l->getVortexUid(1),l->getVortexUid(3));
	//l->removeEdge(l->getElement(1),l->getElement(2));

	//l->createEdges(9);
	//l->removeEdge(l->getElementUid(1),l->getElementUid(2));
	//l->removeNode(0);
	/*
	e.reset( new Edge(l->getElement(0),l->getElement(4),0,0 ));
	l->addEdge(e,l->getElement(0),l->getElement(4));

	e.reset( new Edge(l->getElement(0),l->getElement(5),0,0 ));
	l->addEdge(e,l->getElement(0),l->getElement(5));

	e.reset( new Edge(l->getElement(0),l->getElement(6),0,0 ));
	l->addEdge(e,l->getElement(0),l->getElement(6));




	e.reset( new Edge(l->getElement(7),l->getElement(8),0,0 ));
	l->addEdge(e,l->getElement(7),l->getElement(8));

	e.reset( new Edge(l->getElement(7),l->getElement(9),0,0 ));
	l->addEdge(e,l->getElement(7),l->getElement(9));

	e.reset( new Edge(l->getElement(7),l->getElement(10),0,0 ));
	l->addEdge(e,l->getElement(7),l->getElement(10));

	e.reset( new Edge(l->getElement(7),l->getElement(11),0,0 ));
	l->addEdge(e,l->getElement(7),l->getElement(11));

	e.reset( new Edge(l->getElement(7),l->getElement(12),0,0 ));
	l->addEdge(e,l->getElement(7),l->getElement(12));

	e.reset( new Edge(l->getElement(7),l->getElement(3),0,0 ));
	l->addEdge(e,l->getElement(7),l->getElement(3));




	e.reset( new Edge(l->getElement(1),l->getElement(2),0,0 ));
	l->addEdge(e,l->getElement(1),l->getElement(2));

	e.reset( new Edge(l->getElement(2),l->getElement(3),0,0 ));
	l->addEdge(e,l->getElement(2),l->getElement(3));

	e.reset( new Edge(l->getElement(3),l->getElement(4),0,0 ));
	l->addEdge(e,l->getElement(3),l->getElement(4));

	e.reset( new Edge(l->getElement(4),l->getElement(5),0,0 ));
	l->addEdge(e,l->getElement(4),l->getElement(5));

	e.reset( new Edge(l->getElement(5),l->getElement(6),0,0 ));
	l->addEdge(e,l->getElement(5),l->getElement(6));

	e.reset( new Edge(l->getElement(6),l->getElement(1),0,0 ));
	l->addEdge(e,l->getElement(6),l->getElement(1));



	e.reset( new Edge(l->getElement(3),l->getElement(8),0,0 ));
	l->addEdge(e,l->getElement(3),l->getElement(8));

	e.reset( new Edge(l->getElement(3),l->getElement(12),0,0 ));
	l->addEdge(e,l->getElement(3),l->getElement(12));


	e.reset( new Edge(l->getElement(2),l->getElement(8),0,0 ));
	l->addEdge(e,l->getElement(2),l->getElement(8));

	e.reset( new Edge(l->getElement(8),l->getElement(9),0,0 ));
	l->addEdge(e,l->getElement(8),l->getElement(9));

	e.reset( new Edge(l->getElement(9),l->getElement(10),0,0 ));
	l->addEdge(e,l->getElement(9),l->getElement(10));

	e.reset( new Edge(l->getElement(10),l->getElement(11),0,0 ));
	l->addEdge(e,l->getElement(10),l->getElement(11));

	e.reset( new Edge(l->getElement(11),l->getElement(12),0,0 ));
	l->addEdge(e,l->getElement(11),l->getElement(12));

	e.reset( new Edge(l->getElement(12),l->getElement(4),0,0 ));
	l->addEdge(e,l->getElement(12),l->getElement(4));


	 */

	//l->removeEdge(l->getElementUid(12),l->getElementUid(4));

/*
	e1 = new Edge(l->getElement(0),l->getElement(1),0,0 );
	l->addEdge(*e1,l->getElement(0),l->getElement(1));

	e2 = new Edge(l->getElement(0),l->getElement(2),0,0 );
	l->addEdge(*e2,l->getElement(0),l->getElement(2));

	e3 = new Edge(l->getElement(1),l->getElement(2),0,0 );
	l->addEdge(*e3,l->getElement(1),l->getElement(2));
*/

	unsigned int* mat = (unsigned int*) calloc(l->getVortices().size()*l->getVortices().size(),sizeof(int));
	l->genAdjMat(mat);
	l->adjMatMtca(mat);

	//free(mat); free(n); free(e); free(v);
}
