// Copyright 2021 Rustamov Azer

#ifndef MODULES_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_H_
#define MODULES_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_H_

#include <string>
#include "include/polygon.h"

namespace Polygon {

class PolygonAreaCalculator {
 public:
    PolygonAreaCalculator() = default;;
    std::string operator()(int argc, const char* argv[],
                           int* retcode = nullptr) const;
 private:
    std::string help(const std::string& filename) const;
};

}

#endif  // MODULES_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_H_
