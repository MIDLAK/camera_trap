#ifndef PARALLELBACKGROUNDEXTRACTOR_H
#define PARALLELBACKGROUNDEXTRACTOR_H

#include "BackgroundExtractor.h"
#include "Barrier.h"
#include <thread>

class ParallelBackgroundExtractor : public BackgroundExtractor {
public:
    std::vector<Pixel> extract(const std::vector<std::vector<Pixel>>& imagesPixels) override;

private:
    void extractPixels(
        const std::vector<std::vector<Pixel>>& imagesPixels, 
        std::vector<Pixel>& background, 
        int start, 
        int end,
        Barrier& barrier
    );
};

#endif
