// Copyright 2020 Rustamov Azer

#include <iostream>
#include <limits>
#include <vector>

#include "include/dijkstras_algorithm.h"

Matrix dijkstras_algorithm(Matrix graph, int verts, int source_vertex) {
    if (graph.size() != verts * verts) {
        throw "Incorrect graph";
    }
    if (source_vertex >= verts) {
        throw "Incorrecr source vertex";
    }
    // Matrix shortest_path_tree(verts * verts);
    double inf = std::numeric_limits<double>::infinity();
    // std::fill(shortest_path_tree.begin(), shortest_path_tree.end(), inf);
    Matrix distance_to_verex(verts);
    std::fill(distance_to_verex.begin(), distance_to_verex.end(), inf);
    distance_to_verex[source_vertex] = 0.0;
    int closest_vert_in, closest_vert_out;
    double shortest_path;
    while (true) {
        shortest_path = inf;
        for (int vert_in = 0; vert_in < verts; vert_in++) {
            if (distance_to_verex[vert_in] != inf) {
                for (int vert_out = 0; vert_out < verts; vert_out++) {
                    if ((distance_to_verex[vert_out] == inf) &&
                        (graph[vert_in * verts + vert_out] < shortest_path)) {
                        closest_vert_in = vert_in;
                        closest_vert_out = vert_out;
                        shortest_path = graph[vert_in * verts + vert_out];
                    }
                }
            }
        }
        if (shortest_path == inf)
            break;
        // shortest_path_tree[closest_vert_in * verts + closest_vert_out] = shortest_path;
        distance_to_verex[closest_vert_out] = distance_to_verex[closest_vert_in] +
           shortest_path;
    }
    /*
    for (int i = 0; i < verts; i++) {
        std::cout << distance_to_verex[i] << "; "; 
    }
    std::cout << std::endl;
    */

    //return shortest_path_tree;
    return distance_to_verex;
}
