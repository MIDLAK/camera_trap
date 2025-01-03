#include "../headers/OpenMPBackgroundExtractor.h"
#include <iostream>
#include <iterator>

#define THREADS_SCALE 5

std::vector<Pixel> OpenMPBackgroundExtractor::extract(
    const std::vector<std::vector<Pixel>>& imagesPixels
) {
    int imageSize = imagesPixels[0].size();
    std::vector<Pixel> background(imageSize);

    /* разделение пикселей по потокам */
    int numThreads = std::thread::hardware_concurrency() * THREADS_SCALE;
    int chunkSize = imageSize / numThreads;

#pragma omp parallel for schedule(static)
    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? imageSize : start + chunkSize;
    calculateBackground(imagesPixels, background, start, end);
#pragma omp barrier /* ожидание обработки кадра всеми потоками */
    }

    return background;
}
