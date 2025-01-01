#include <iostream>
using namespace std;

class Graph {
public:
    string vertices[100]; 
    int adjMatrix[100][100]; 
    int numVertices;

    Graph() {
        numVertices = 0; 
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(string v, string w) {
        int vIndex = -1, wIndex = -1;
        for (int i = 0; i < numVertices; i++) {
            if (vertices[i] == v) {
                vIndex = i;
                break;
            }
        }
        if (vIndex == -1) {
            vertices[numVertices] = v;
            vIndex = numVertices++;
        }

        for (int i = 0; i < numVertices; i++) {
            if (vertices[i] == w) {
                wIndex = i;
                break;
            }
        }
        if (wIndex == -1) {
            vertices[numVertices] = w;
            wIndex = numVertices++;
        }

        adjMatrix[vIndex][wIndex] = 1;
        adjMatrix[wIndex][vIndex] = 1;
    }

    int getVertexIndex(string v) {
        for (int i = 0; i < numVertices; i++) {
            if (vertices[i] == v) {
                return i;
            }
        }
        return -1; 
    }

    void BFS(string start) {
        bool visited[100] = {false}; 
        int queue[100];  
        int front = 0, rear = 0; 

        int startIndex = getVertexIndex(start);
        if (startIndex == -1) return;

        visited[startIndex] = true;
        queue[rear++] = startIndex; 

        while (front < rear) {
            int vIndex = queue[front++];
            cout << vertices[vIndex] << " "; 

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[vIndex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i; 
                }
            }
        }
    }

    void DFSUtil(int vIndex, bool visited[]) {
        visited[vIndex] = true;
        cout << vertices[vIndex] << " "; 

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[vIndex][i] == 1 && !visited[i]) {
                DFSUtil(i, visited); 
            }
        }
    }

    void DFS(string start) {
        bool visited[100] = {false}; 
        int startIndex = getVertexIndex(start);
        if (startIndex == -1) return;

        DFSUtil(startIndex, visited); 
    }
};

int main() {
    Graph g;
    g.addEdge("Ha Noi", "Bac Ninh");
    g.addEdge("Bac Ninh", "Hai Phong");
    g.addEdge("Hà Noi", "Hai Phong");

    cout << "BFS bat dau tu Ha Noi\n";
    g.BFS("Ha Noi");

    cout << "\nDFS bat dau tu Ha Noi\n";
    g.DFS("Ha Noi");

    return 0;
}

