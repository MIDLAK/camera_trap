#ifndef OPENMPBACKGROUNDEXTRACTOR_H
#define OPENMPBACKGROUNDEXTRACTOR_H

#include "BackgroundExtractor.h"
#include <thread>

class OpenMPBackgroundExtractor: public BackgroundExtractor {
public:
    std::vector<Pixel> extract(const std::vector<std::vector<Pixel>>& imagesPixels) override;
private:
    void extractPixels(
        const std::vector<std::vector<Pixel>>& imagesPixels, 
        std::vector<Pixel>& background, 
        int start, 
        int end
    );
};
#endif
