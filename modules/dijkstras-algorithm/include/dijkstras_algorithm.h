// Copyright 2020 Rustamov Azer

#include <vector>

#ifndef MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_H_
#define MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_H_

using Matrix = std::vector<double>;

Matrix RandomGraph(int verts, int edges, bool oriented = false);
Matrix RandomGraphSparce(int verts, int edges, bool oriented = false);
Matrix RandomGraphDence(int verts, int edges, bool oriented = false);

Matrix dijkstras_algorithm(Matrix graph, int verts, int source_vertex);

#endif  // MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_H_
