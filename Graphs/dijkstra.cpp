// Algorithm to find the single source shortest path in weighted directed/undirected -> cyclic/acyclic graph with no negative weights

// Question in mind: 
// 1. SSSP for unit weights in Directed Graph
// 2. SSSP for unit weights in DAG, (available for weighted DAG)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(vector <vector <pair <int , int > > > &graph , vector <int> &distance , priority_queue <pair <int , int> > &pq , int source) {

    pq.push(make_pair(distance[source] , source));
    while(!pq.empty()) {

        pair <int , int> distSrc = pq.top();
        pq.pop();

        for(int i = 0; i < graph[distSrc.second].size(); i++) {
            pair <int , int> newSrc = graph[distSrc.second][i];
            int wt = distSrc.first;
            int dist = wt + newSrc.second;
            if(dist < distance[newSrc.first]) {
                distance[newSrc.first] = dist;
                pq.push(make_pair(dist , newSrc.first));
            }
        }

    }

}

int main() {

    int noOfVertices , noOfEdges;
    cin >> noOfVertices >> noOfEdges;

    vector <vector <pair <int , int> > > graph(noOfVertices);
    for(int i = 0; i < noOfEdges; i++) {
        int src , dest , wt;
        cin >> src >> dest >> wt;

        graph[src].push_back(make_pair(dest , wt));
        graph[dest].push_back(make_pair(src , wt));
    }

    vector <int> distance(noOfVertices , INT_MAX);
    int source;
    cin >> source;

    priority_queue <pair <int , int> > pq;

    distance[source] = 0;
    dijkstra(graph , distance , pq , source);

    for(int i = 0; i < distance.size(); i++) {
        cout << distance[i] << " ";
    }
    cout << endl;

    return 0;
}


// 5
// 6
// 0 1 2
// 0 3 1
// 1 4 5
// 1 2 4
// 2 4 1
// 2 3 3
// 0