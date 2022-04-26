#include "Graph.h"

// Driver code
int main()
{
    // Declare an empty graph G
	Graph G;

   // Add edges to graph G
   unsigned u,v;
   while( cin >> u >> v )
	   addEdge(G, u, v);

   // Display graph G
   cout << G << endl;

   cout << "The graph is "
        << ( connected(G) ? "" : "not " )
        << "connected." << endl;

	return 0;
} 
