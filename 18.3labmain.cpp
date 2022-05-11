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

   // Display strongly connected components of G
   cout << "\nHere are G's strongly connected components:" << endl;
   printSCCs( cout , G ); // Note parameter list

	return 0;
} 
