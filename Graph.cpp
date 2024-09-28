/****************************
 * Program 5: Graph
 *
 * Course: CS 141, Fall 2022
 * System: WindowsOS using Clion
 * Student Author: Zaid Khan Mohammed
 * *** **********************/


/*
 * Program 5: Graph
 *
 * Course: CS 141, Fall 2022
 * System: WindowsOS using Clion
 * Student Author: Zaid Khan Mohammed
 *
 * This program implements a graph using an adjacency list.
 * It supports:
 * - Adding neighbors in sorted order.
 * - Loading a graph from an edge list file.
 * - Dumping the adjacency list to an output file.
 * - Printing graph statistics (number of nodes, edges, max degree).
 * - Retrieving the number of neighbors for a node.
 *
 * The main function initializes the graph, loads data, saves the adjacency list,
 * and prints graph information to the console.
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;


//************************** Node *************************

class Node{
public:
    int data;
    Node *pNext;
};

//************************** Graph ****************************
class Graph {
public:
    //add the node with neighborId as the neighbor of nodeId
    void addNeighbor(int nodeId, int neighborId);

    //reads the edge list from file and creates the adjacency list data structure
    void loadGraph(string edgeListFileName);

    //writes the adjacency list into the file
    void dumpGraph(string adjListFileName);

    //Prints number of nodes, number of edges, and maximum degree on terminal
    void printGraphInfo();

    //returns the number of neighbor (degree) of a node
    int getNumNeighbors(int nodeId);

    //returns the number of nodes in the graph
    int getNumVertices();
private:
    vector<Node*> vertices;

};

void Graph::addNeighbor(int nodeId, int neighborId) {
    Node *pNode=new Node;
    pNode->data=neighborId;
    pNode->pNext=NULL;
    while (vertices.size()<=nodeId){
        vertices.push_back(NULL);
    }
    Node *pCurr=vertices.at(nodeId);
    if (vertices.at(nodeId)==NULL){
        vertices.at(nodeId)=pNode;
    }
    else {
        while (pCurr!=NULL){
            if (pCurr->pNext==NULL){
                if (neighborId<pCurr->data){
                    pNode->pNext=pCurr;
                    vertices.at(nodeId)=pNode;
                    break;
                }
                else if(neighborId>pCurr->data){
                    pCurr->pNext=pNode;
                    break;

                }
                else {break;}
            }
            else {
                if (pCurr->data>neighborId){
                    pNode->pNext=pCurr;
                    vertices.at(nodeId)=pNode;
                    break;
                }
                else if (pCurr->data<neighborId && pCurr->pNext->data<neighborId){
                    pCurr=pCurr->pNext;
                }
                else if (pCurr->data<neighborId && pCurr->pNext->data>neighborId){
                    pNode->pNext=pCurr->pNext;
                    pCurr->pNext=pNode;
                    break;
                }
                else if (pCurr->data<neighborId && pCurr->pNext==NULL){
                    pCurr->pNext=pNode;
                    break;
                }
                else {break;}
            }
        }
    }
}

void Graph::loadGraph(string edgeListFileName) {
    ifstream myFile;
    myFile.open(edgeListFileName);
    int vertice1;
    int vertice2;
    while(!myFile.eof()){
        myFile>>vertice1;
        myFile>>vertice2;
        addNeighbor(vertice1, vertice2);
        addNeighbor(vertice2, vertice1);
    }
}

void Graph::dumpGraph(string adjListFileName) {
    ofstream myFile;
    myFile.open(adjListFileName);
    for (int i=0;i<vertices.size();++i){
        if (vertices.at(i)!=NULL) {
            myFile << i << ":";
            Node *pTemp = vertices.at(i);
            while (pTemp != NULL) {
                myFile << " " << pTemp->data;
                pTemp = pTemp->pNext;

            }
            myFile << endl;
        }
    }
    myFile.close();
}

void Graph::printGraphInfo() {
    int edges = 0;
    int degree = 0;
    int degreeNew = 0;
    int nodes = 0;
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices.at(i) != NULL) {
            nodes++;
            Node *pTemp = vertices.at(i);
            while (pTemp != NULL) {
                edges++;
                degreeNew++;
                pTemp = pTemp->pNext;
            }
            if (degreeNew > degree) {
                degree = degreeNew;
            }
            degreeNew = 0;
        }
    }
    cout << "Number of nodes: " << nodes << endl;
    cout << "Number of edges: " << edges / 2 << endl;
    cout << "Maximum degree: " << degree << endl;
}

int Graph::getNumNeighbors(int nodeId) {
    int numNeighbors=0;
    Node *pTemp=vertices.at(nodeId);
    while (pTemp!=NULL){
        numNeighbors++;
        pTemp=pTemp->pNext;
    }
    return numNeighbors;
}

int Graph::getNumVertices() {
    int numVertices = 0;
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices.at(i) != NULL) {
            numVertices++;
        }
    }
    return numVertices;
}

void run(string edgeListFileName, string adjListFileName) {
    Graph graph;
    graph.loadGraph(edgeListFileName);
    graph.dumpGraph(adjListFileName);
    graph.printGraphInfo();

}

//*****************************************************************************


int main() {
    string edgeListFileName("C:\\Users\\zaidk\\Documents\\CLion Projects\\Program 6\\roadNet-CA.txt");
    string adjListFileName("C:\\Users\\zaidk\\Documents\\CLion Projects\\Program 6\\roadNet-CA_adj.txt");
    run(edgeListFileName, adjListFileName);
    return 0;
}

