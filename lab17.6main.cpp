#include <vector>
using namespace std;

#include "Graph.h"

// Driver code
int main()
{
    // Declare an empty graph G
    Graph G; // Assume to be a DAG

    // Add edges to graph G
    unsigned u,v;
    while( cin >> u >> v )
        addEdge(G, u, v);

    // Display graph G
    cout << G << endl << endl;

    vector<unsigned> tsortV=topologicalSort( G );

    // Display a topological of the vertices of G
    cout << "A topological sort of the vertices: ";
    for( unsigned v : tsortV )
        cout << v << " ";
    cout << endl;

    return 0;
}
