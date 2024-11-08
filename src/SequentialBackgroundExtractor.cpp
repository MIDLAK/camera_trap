#include "../headers/SequentialBackgroundExtractor.h"
#include "../headers/Pixel.h"
#include <vector>

std::vector<Pixel> SequentialBackgroundExtractor::extract(const std::vector<std::vector<Pixel>>& imagesPixels) {
    int imageSize = imagesPixels[0].size();
    int numImages = imagesPixels.size();
    std::vector<Pixel> background(imageSize);
    calculateBackground(
        imagesPixels, 
        background, 
        0, 
        imageSize
    );
    return background;
}
