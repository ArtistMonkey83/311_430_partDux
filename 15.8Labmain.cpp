#include "Graph.h"

int main()
{
    Graph G1, G2;
    unsigned E,u,v;

    // Add edges to graph G1
    cin >> E; // number of edges in G1
    for( unsigned i=0 ; i<E ; i++ )
    {
        cin >> u >> v;
        addEdge( G1 , u , v );
    }
    // Display graph G1
    cout << "1st " << G1 << endl;

    // Add edges to graph G2
    cin >> E; // number of edges in G2
    for( unsigned i=0 ; i<E ; i++ )
    {
        cin >> u >> v;
        addEdge( G2 , u , v );
    }
    // Display graph G2
    cout << "2nd "<< G2 << endl;

    // Display the union and difference of G1 and G2
    cout << "Union " << G1+G2 << endl;
    cout << "Difference " << G1-G2 << endl;

    return 0;
}
