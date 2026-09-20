#include <iostream>
#include <vector>
using namespace std;

class VertexCover {
private:
    int V, E;
    vector<pair<int, int>> edges;
    vector<bool> visited;
public:

    // Constructor
    VertexCover(int v, int e) {
        V = v;
        E = e;
        visited.resize(V, false);
    }
    
    // Method to take input
    void inputEdges() {
        cout << "Enter edges (u v):\n";
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;

            // Validation
            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid edge! Try again.\n";
                i--;
            continue;
            }
        edges.push_back({u, v});
        }
    }

    // Method to compute vertex cover
    void findVertexCover() {
        cout << "\n--- Step by Step Execution ---\n";
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
        
            if (!visited[u] && !visited[v]) {
                cout << "Selecting edge (" << u << ", " << v << ")\n";
                visited[u] = true;
                visited[v] = true;
                cout << "Adding vertices: " << u << " and " << v << "\n\n";
            }
        }
    }

    // Method to display result
    void display() {
        cout << "--- Final Vertex Cover ---\n";
        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Object creation
    VertexCover vc(V, E);
    vc.inputEdges();
    vc.findVertexCover();

    vc.display();
    
    return 0;
}