# Graph

## Overview
This program implements a graph of using an adjacency list (data from https://snap.stanford.edu/data/roadNet-CA.html), providing functionality to manipulate and analyze the graph structure. It is designed for educational purposes as part of the CS 141 course in Fall 2022.

## Features
The program supports the following features:
- **Adding Neighbors**: Add neighbors to a node in sorted order.
- **Loading Graph**: Load a graph from an edge list file.
- **Dumping Graph**: Write the adjacency list to an output file.
- **Graph Statistics**: Print the number of nodes, edges, and the maximum degree of the graph.
- **Neighbor Count**: Retrieve the number of neighbors for a specific node.

## Usage
1. **Compile the Code**: Ensure you have a C++ compiler and the necessary libraries. Open the project in CLion and compile.
2. **Prepare Edge List File**: Create or obtain an edge list text file containing the graph edges. Each line should represent an edge between two nodes.
3. **Run the Program**: The main function initializes the graph, loads data from the edge list file, saves the adjacency list to an output file, and prints graph information to the console.
