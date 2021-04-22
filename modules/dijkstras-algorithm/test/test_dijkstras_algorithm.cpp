// Copyright 2021 Rustamov Azer

#include <gtest/gtest.h>
#include <limits>
#include <vector>

#include "include/dijkstras_algorithm.h"

#define EPSILON 0.0001

TEST(Dijkstra_Algorithm, Incorrect_Verts_Throws_Exception) {
    double inf = std::numeric_limits<double>::infinity();
    int verts = 0;
    Matrix graph = {inf, inf, 7,   3,   9,
                    inf, inf, 2,   15,  4,
                    7,   2,   inf, 10,  inf,
                    3,   15,  10,  inf, inf,
                    9,   4,   inf, inf, inf };;
    ASSERT_ANY_THROW(dijkstras_algorithm(graph, verts, 0));
}

TEST(Dijkstra_Algorithm, Incorrect_Source_Throws_Exception) {
    double inf = std::numeric_limits<double>::infinity();
    int verts = 5;
    Matrix graph = {inf, inf, 7,   3,   9,
                    inf, inf, 2,   15,  4,
                    7,   2,   inf, 10,  inf,
                    3,   15,  10,  inf, inf,
                    9,   4,   inf, inf, inf };;
    ASSERT_ANY_THROW(dijkstras_algorithm(graph, verts, 100));
}

TEST(Dijkstra_Algorithm, Correct_Answer_Unoriented_5_Seq) {
    double inf = std::numeric_limits<double>::infinity();
    int verts = 5;
    Matrix graph = {inf, inf, 7,   3,   9,
                    inf, inf, 2,   15,  4,
                    7,   2,   inf, 10,  inf,
                    3,   15,  10,  inf, inf,
                    9,   4,   inf, inf, inf };
    Matrix expected_result = {0, 9, 7, 3, 13};
    /*
    Matrix expected_result = {inf, inf, 7,   3,   inf,
                              inf, inf, inf, inf, 4,
                              inf, 2,   inf, inf, inf,
                              inf, inf, inf, inf, inf,
                              inf, inf, inf, inf, inf };
    */
    Matrix result = dijkstras_algorithm(graph, verts, 0);
    for (int i = 0; i < verts; i++) {
        if ((result[i] != inf) || (expected_result[i] != inf)) {
            ASSERT_NEAR(result[i], expected_result[i], EPSILON);
        }
    }
    /*
    for (int pos = 0; pos < verts * verts; pos++) {
        if ((result[pos] != inf) || (expected_result[pos] != inf)) {
            ASSERT_NEAR(result[pos], expected_result[pos], EPSILON);
        }
    }
    */
}


