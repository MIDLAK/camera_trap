#ifndef H_PERFORMANCETESTER
#define H_PERFORMANCETESTER

#include "Pixel.h"
#include <vector>

class PerformanceTester {
public:
    PerformanceTester() = default;

    void runTests();

private:
    /* генерация массива пикселей заданного размера */
    std::vector<std::vector<Pixel>> generatePixelArray(int width, int height);
};

#endif
