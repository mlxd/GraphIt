///@cond LICENSE
/*** edge.h - GraphIt, Copyright (C) 20XY, Lee J. O'Riordan
<loriordan@gmail.com>. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
///@endcond
//##############################################################################
/**
 *  @file    edge.h
 *  @author  Lee J. O'Riordan (mlxd)
 *  @date    12/11/2015
 *  @version 0.1
 *
 *  @brief Class for creating edges between adjacent nodes in the graph
 *
 *  @section DESCRIPTION
 *  This class is used as part of generating a graph from the positions of the
 *  vortices, given as pairs of coordinates. The edge can be set between any
 *  pair of nodes in the graph.
 */
 //##############################################################################

#ifndef LATTICEGRAPH_EDGE_H
#define LATTICEGRAPH_EDGE_H

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include "node.h"

namespace LatticeGraph {

    class Node;
    class Edge {


    private:
	    static unsigned int suid; //Incremented id for new

	    std::weak_ptr<Node> n1, n2; //Points to the connected nodes

	    int direction; //1 n1->n2, 0 undirected, -1 n2->n1

	    double weight; // 0.0 if not relevant, otherwise +/- reals

    public:
	    unsigned int uid;
		/**
		* @brief	Makes stuff exist
		* @ingroup	graph
		*/
	    Edge();
		/**
		* @brief	Makes stuff anti-exist
		* @ingroup	graph
		*/
	    ~Edge();

		/**
		* @brief	Makes stuff exist between vortices n1 and n2
		* @ingroup	graph
		* @param	n1 Vortex (node) 1 to connect to edge
		* @param	n2 Vortex (node) 2 to connect to edge
		*/
	    Edge(std::weak_ptr<Node> n1, std::weak_ptr<Node> n2);
		/**
		* @brief	Makes stuff exist between n1 and n2, with direction and weight
		* @ingroup	graph
		* @param	n1 Vortex (node) 1 to connect to edge
		* @param	n2 Vortex (node) 2 to connect to edge
		* @param	dir Direction of edge. 1 n1->n2; -1 n2->n1; 0 undirected
		* @param	weight Edge weight. 0.0 if not required
		*/
	    Edge(std::weak_ptr<Node> n1, std::weak_ptr<Node> n2, int dir, double weight);

		//##############################################################################

		/**
		* @brief	Returns edge UID
		* @ingroup	graph
		* @return	Edge UID
		*/
	    unsigned int getUid();
		/**
		* @brief	Returns static UID value for use in new edge UID
		* @ingroup	graph
		* @return	Static unsigned int, incremeneted with creation of new edge
		*/
	    unsigned int& getSuid();
		/**
		* @brief	Returns direction of edge. 1 n1->n2,;-1 n2->n1; 0 undirected
		* @ingroup	graph
		* @return	Integer for edge direction.
		*/
		int getDirection();
		/**
		* @brief	Returns the weight of an edge. 0 if unweighted.
		* @ingroup	graph
		* @return	Double of edge weight
		*/
		double getWeight();
		/**
		* @brief	Returns connected vortices (nodes)
		* @ingroup	graph
		* @param	idx 0 gets n1, others get node 2
		* @return	Returns weak_ptr to vortices; if exception, returns empty weak_ptr
		*/
		std::weak_ptr<Node> getVortex(int idx);

		//##############################################################################

		/**
		* @brief	Set the direction of the edge
		* @ingroup	graph
		* @param	direction 1 for n1->n2; -1 for n2->n1; 0 for undirected
		*/
	    void setDirection(int direction);
		/**
		* @brief	Set the weight of the edge
		* @ingroup	graph
		* @param	weight 0.0 if not used; +/- double otherwise
		*/
	    void setWeight(double weight);

		//##############################################################################

		/**
		* @brief	Updates the connected vortex at either side of edge
		* @ingroup	graph
		* @param	idx Selects connected vortex. 0 for n1, others for n2
		* @param	n_new New vortex at the specified position
		*/
	    void updateVortex(int idx, std::weak_ptr<Node> n_new);

		//##############################################################################

		/**
		* @brief	Checks to see if vortex/node n is on edge
		* @ingroup	graph
		* @return	Returns true if connected, otherwise false
		*/
	    bool isMember(std::weak_ptr<Node> n);

		//##############################################################################

		/**
		* @brief	Operator overloading for comparing UIDs between edges
		* @ingroup	graph
		* @return	Returns true if self is smaller, otherwise false
		*/
	    bool operator < (std::shared_ptr<Edge> e) const{
		    return uid < e->getUid();
	    }
    };
}
#endif //LATTICEGRAPH_EDGE_H
