#ifndef SEQUENTIALBACKGROUNDEXTRACTOR_H
#define SEQUENTIALBACKGROUNDEXTRACTOR_H

#include "BackgroundExtractor.h"

class SequentialBackgroundExtractor : public BackgroundExtractor {
public:
    std::vector<Pixel> extract(const std::vector<std::vector<Pixel>>& imagesPixels) override;
};

#endif
