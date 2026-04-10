# Kruskal Algorithm - Minimum Spanning Tree

## 📌 Description
This project implements Kruskal's Algorithm to find the Minimum Spanning Tree (MST) of a graph using C programming.

## ⚙️ Algorithm Overview
Kruskal's Algorithm is a greedy algorithm that:
- Sorts all edges in increasing order of weight
- Selects edges one by one
- Avoids cycles while forming the spanning tree

## 📥 Input
- Number of vertices
- Number of edges
- Edge list (source, destination, weight)

## 📤 Output
- Edges included in the Minimum Spanning Tree
- Total cost of the MST

## 🛠️ How to Run
1. Open the project in VS Code
2. Compile the code:
   ```bash
   gcc kruskal_algorithm.c -o kruskal
