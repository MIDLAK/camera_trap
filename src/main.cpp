#include "../headers/ImageReader.h"
#include "../headers/OpenMPBackgroundExtractor.h"
#include "../headers/SequentialBackgroundExtractor.h"
#include "../headers/ParallelBackgroundExtractor.h"
#include "../headers/ImageSaver.h"
#include "../headers/PerformanceTester.h"
#include <iostream>
#include <filesystem>
#include <chrono>

int main() {
    std::filesystem::path resourcesPath = std::filesystem::current_path() / "resources/images";
    ImageReader reader(resourcesPath);

    std::vector<std::vector<Pixel>> imagesPixels = reader.readImages();

    int width = 640;
    int height = 298;

    /* последовательное выделение фона */
    SequentialBackgroundExtractor seqExtractor;
    std::vector<Pixel> sequentialBackground = seqExtractor.extract(imagesPixels);

    /* параллельное выделение фона */
    ParallelBackgroundExtractor parExtractor;
    std::vector<Pixel> parallelBackground = parExtractor.extract(imagesPixels);

    /* вычисление фона с помощью OpenMP */
    OpenMPBackgroundExtractor ompExtractor;
    std::vector<Pixel> ompBackground = ompExtractor.extract(imagesPixels);

    ImageSaver::saveImage("sequential_background.png", sequentialBackground, width, height);
    ImageSaver::saveImage("parallel_background.png", parallelBackground, width, height);
    ImageSaver::saveImage("omp_background.png", ompBackground, width, height);

    /* тесты */
    PerformanceTester perfTester;
    perfTester.runTests();

    return 0;
}
