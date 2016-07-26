/*** node.cc - GraphIt, Copyright (C) 20XY, Lee J. O'Riordan
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

//######################################################################################################################

#include "../inc/node.h"
#include <memory>
#include <iostream>

using namespace LatticeGraph;

//######################################################################################################################
//####################################    Ceiling Cat & Basement Cat     ###############################################
//######################################################################################################################

Node::Node():uid(++suid){
}

Node::~Node(){
	this->removeEdges();
}

Node::Node(Vtx::Vortex& data):uid(++suid){
	this->data = data;
}

//######################################################################################################################
//####################################            Get stuff              ###############################################
//######################################################################################################################

unsigned int Node::getUid(){
	return uid;
}

Vtx::Vortex &Node::getData(){
	return this->data;
}

std::vector<std::weak_ptr <Edge> >& Node::getEdges(){
	return this->edges;
}

std::weak_ptr<Edge> Node::getEdge(int idx) {
	return this->edges.at(idx);
}

std::shared_ptr<Node> Node::getConnectedNode(std::shared_ptr<Edge> e){
	return (e->getVortex(0).lock()->getUid() != this->Node::getUid()) ? e->getVortex(0).lock() :  e->getVortex(1).lock() ;
}

//######################################################################################################################
//####################################             Set stuff             ###############################################
//######################################################################################################################

template <typename T>
void Node::setData(T &data){
	this->data = data;
}

//######################################################################################################################
//####################################             +/- stuff             ###############################################
//######################################################################################################################

void Node::addEdge(std::weak_ptr<Edge> e){
	this->edges.push_back(e);
}

void Node::removeEdgeUid(unsigned int uid){
	for (int ii=0; ii < this->Node::edges.size(); ++ii){
		if(this->Node::getEdge(ii).lock()->getUid() == uid){
			this->Node::getEdges().erase(this->Node::getEdges().begin()+ii);
			break;
		}
	}
}

void Node::removeEdgeIdx(unsigned int idx){
	this->Node::getEdges().erase(this->Node::getEdges().begin()+idx);
}

void Node::removeEdge(std::shared_ptr<Node> n) {
	for(std::weak_ptr<Edge> e1 : this->Node::getEdges()){
		for(std::weak_ptr<Edge> e2 : n->getEdges()){
			if (Node::getConnectedNode(e1.lock())->getUid() == e2.lock()->getUid()){
				this->Node::removeEdgeUid(e2.lock()->getUid());
				return;
			}
		}
	}
}

void Node::removeEdge(std::weak_ptr<Edge> edge){
	this->Node::removeEdgeUid(edge.lock()->getUid());
}

void Node::removeEdges(){
	for(int ii=0; ii<this->getEdges().size(); ++ii){
		this->Node::removeEdge(this->Node::getEdge(ii));
	}
	this->Node::getEdges().clear();
}

//######################################################################################################################