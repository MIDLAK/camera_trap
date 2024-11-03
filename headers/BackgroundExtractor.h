#ifndef BACKGROUNGEXTRACTOR_H
#define BACKGROUNGEXTRACTOR_H

#include "Pixel.h"
#include <vector>

class BackgroundExtractor {
public:
    /* выделение фона на изображении */
    static void extract(const std::vector<Pixel>& pixels);
};

#endif
