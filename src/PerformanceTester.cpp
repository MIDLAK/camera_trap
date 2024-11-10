#include "../headers/PerformanceTester.h"
#include "../headers/SequentialBackgroundExtractor.h"
#include "../headers/ParallelBackgroundExtractor.h"

#include <iostream>
#include <random>

void PerformanceTester::runTests() {
    std::cout << "|\tКол. пикселей\t|\tПоследовательное\t|\tПараллельное\t|\n";
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    /* размеры генерируемых изображений */
    int testSizes[][2] = {{320, 240}, {640, 480}, {1280, 720}, {1920, 1080}, {3840, 2160}};
    int numTests = sizeof(testSizes) / sizeof(testSizes[0]);

    SequentialBackgroundExtractor seqExtractor;
    ParallelBackgroundExtractor parExtractor;

    for (int i = 0; i < numTests; ++i) {
        int width = testSizes[i][0];
        int height = testSizes[i][1];

        std::vector<std::vector<Pixel>> imagesPixels = generatePixelArray(width, height);

        /* последовательное выделение фона */
        std::chrono::high_resolution_clock::time_point startSeq = 
            std::chrono::high_resolution_clock::now();
        std::vector<Pixel> sequentialBackground = seqExtractor.extract(imagesPixels);
        std::chrono::high_resolution_clock::time_point endSeq = 
            std::chrono::high_resolution_clock::now();

        /* параллельное выделение фона */
        std::chrono::high_resolution_clock::time_point startPar = 
            std::chrono::high_resolution_clock::now();
        std::vector<Pixel> parallelBackground = parExtractor.extract(imagesPixels);
        std::chrono::high_resolution_clock::time_point endPar = 
            std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> seqDuration = endSeq - startSeq;
        std::chrono::duration<double> parDuration = endPar - startPar;

        std::cout << "|\t" << width * height << "\t\t|\t\t" 
                  << seqDuration.count() << "\t|\t" 
                  << parDuration.count() << "\t|" << std::endl;
    }
}


std::vector<std::vector<Pixel>> PerformanceTester::generatePixelArray(int width, int height) {
    std::vector<std::vector<Pixel>> pixels(height, std::vector<Pixel>(width));
    for (int i = 0; i < height; ++i) 
        for (int j = 0; j < width; ++j) 
            pixels[i][j] = {static_cast<u8>(rand() % 256),  
                            static_cast<u8>(rand() % 256),
                            static_cast<u8>(rand() % 256)};
    return pixels;
}
