/*
 * CommunityGraph.h
 *
 *  Created on: 22.08.2013
 *      Author: cls
 */

#ifndef COMMUNITYGRAPH_H_
#define COMMUNITYGRAPH_H_

#include "../structures/Partition.h"

namespace NetworKit {

class CommunityGraph {
public:

	CommunityGraph();

	virtual ~CommunityGraph();

	/**
	 * Create a graph coarsened according to communities. Edge weights are the weights of
	 * inter-community cuts.
	 */
	virtual void run(const Graph& G, const Partition& zeta);

	virtual Graph getGraph();

	/** only to be used by cython - this eliminates an unnecessary copy */
	Graph* _getGraph() {
		return new Graph{std::move(getGraph())};
	};

	/** 
	 * Maps community id to id of node in the community graph.
	 */
	virtual std::map<index, node> getCommunityToNodeMap();

	/** 
	 * Maps node id in the community graph to community id.
	 */
	virtual std::map<node, index> getNodeToCommunityMap(); 


private:
	Graph Gcom;		//!< the current community graph
	std::vector<node> communityToSuperNode;		//!< community id -> node id in community graph

};

} /* namespace NetworKit */
#endif /* COMMUNITYGRAPH_H_ */