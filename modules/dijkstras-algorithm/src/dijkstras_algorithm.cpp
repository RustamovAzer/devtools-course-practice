// Copyright 2021 Rustamov Azer

// #include <algorithm>
// #include <limits>
#include <vector>

#include "include/dijkstras_algorithm.h"

std::vector<double> dijkstras_algorithm(std::vector<double> graph,
                                        int verts, int source_vertex) {
    if (graph.size() != verts * verts) {
        throw "Incorrect graph";
    }
    if (source_vertex >= verts) {
        throw "Incorrecr source vertex";
    }
    double inf = 9007199254740992;
    std::vector<double> distance_to_verex(verts);
    for (int i = 0; i < distance_to_verex.size(); i++) {
        distance_to_verex[i] = inf;
    }
    // std::fill(distance_to_verex.begin(), distance_to_verex.end(), inf);
    distance_to_verex[source_vertex] = 0.0;
    int closest_vert_in, closest_vert_out;
    while (true) {
        double shortest_path;
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
        distance_to_verex[closest_vert_out] =
                distance_to_verex[closest_vert_in] + shortest_path;
    }
    return distance_to_verex;
}
