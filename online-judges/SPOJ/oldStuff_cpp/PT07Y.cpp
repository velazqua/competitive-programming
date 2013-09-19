#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int,int> EDGE;
typedef list<EDGE> TREE;
typedef TREE::iterator TREE_ITER;

string isTree (TREE t)
{    
    // Check for parallel edges
    TREE_ITER it = t.begin();
    TREE_ITER itEnd = t.end();
    EDGE e;
    TREE_ITER jt;
    for ( ; it != itEnd ; ++it)
    {
        jt = it;
        ++jt;
        e = make_pair(it->second,it->first);
        if (find(jt,itEnd,e) != t.end()) // if we find something
           return "NO";
    }
    return "YES";
          
}

int main ()
{
    /* A tree:
         - Has no self loops
         - No parallel edges
         - |E| = |V| -1
         - No circuits
         - Connected (STILL HAVE TO DO THIS) BFS!
    */
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    int n1, n2;
    TREE tree;
    bool found = false;
    set<int> circuit;
    for (int i=0;i<numEdges;++i)
    {
        cin >> n1 >> n2;
        if (n1 == n2)
           found = true;
        tree.push_back(make_pair(n1,n2));
        circuit.insert(n2);
    } 
    
    //check for self loop, tree property and circuit
    if (found || circuit.size() != tree.size() || numEdges != numNodes -1) // Check for self loop
       cout << "NO" << endl;
    else  //check for parallel edge
       cout << isTree(tree) << endl;
    
   // cin >> numNodes;  
}
