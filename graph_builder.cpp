#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Representasi graf menggunakan daftar ketetanggaan (adjacency list)
class Graph {
public:
    vector<vector<int>> adjList;  // Daftar ketetanggaan
    int V;  // Jumlah simpul

    // Konstruktor untuk graf dengan jumlah simpul tertentu
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Fungsi untuk menambah sisi
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Fungsi untuk menambahkan loop
    void addLoop(int u) {
        adjList[u].push_back(u);
    }

    // Fungsi untuk menulis graf ke file dalam format DOT (untuk Graphviz)
    void writeToDotFile(const string& filename) {
        ofstream file(filename);
        file << "graph G {\n";  // Mulai definisi graf (graf tidak terarah)
        
        // Menulis sisi-sisi ke dalam file DOT
        for (int i = 0; i < V; ++i) {
            for (int j : adjList[i]) {
                // Menulis sisi antara simpul i dan simpul j
                // Menjaga agar sisi hanya ditulis satu kali (graf tidak terarah)
                if (i < j) {
                    file << "  " << i + 1 << " -- " << j + 1 << ";\n";
                }
            }
        }
        
        // Menutup definisi graf
        file << "}\n";
        file.close();
    }

    // Fungsi untuk menampilkan graf dalam format teks (untuk debugging)
    void displayGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Simpul " << i + 1 << " terhubung ke: ";
            for (int v : adjList[i]) {
                cout << v + 1 << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Input jumlah simpul, loop, pasang sisi ganda, dan derajat
    int V, loopCount, edgeCount;
    cout << "Masukkan jumlah simpul: ";
    cin >> V;
    Graph g(V);

    cout << "Masukkan jumlah loop: ";
    cin >> loopCount;

    // Menambahkan loop
    for (int i = 0; i < loopCount; ++i) {
        int simpul;
        cout << "Masukkan simpul untuk loop ke-" << i + 1 << ": ";
        cin >> simpul;
        g.addLoop(simpul - 1);  // Menambahkan loop (index dimulai dari 0)
    }

    cout << "Masukkan jumlah pasang sisi ganda: ";
    cin >> edgeCount;

    // Menambahkan pasang sisi ganda
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cout << "Masukkan pasangan sisi ganda ke-" << i + 1 << " (simpul u dan v): ";
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);  // Menambahkan sisi ganda (index dimulai dari 0)
        g.addEdge(u - 1, v - 1);  // Menambahkan sisi kedua untuk sisi ganda
    }

    // Input derajat setiap simpul
    vector<int> degrees(V, 0);
    cout << "Masukkan derajat setiap simpul (misalnya untuk simpul 1, masukkan derajatnya):\n";
    for (int i = 0; i < V; ++i) {
        cout << "Derajat simpul " << i + 1 << ": ";
        cin >> degrees[i];
    }

    // Menampilkan graf dalam bentuk teks
    g.displayGraph();

    // Menulis graf ke file DOT
    string filename = "graf.dot";
    g.writeToDotFile(filename);

    cout << "Graf telah ditulis ke dalam file " << filename << "\n";
    cout << "Silakan gunakan Graphviz untuk menghasilkan visualisasi (contoh: dot -Tpng graf.dot -o graf.png)\n";

    return 0;
}
