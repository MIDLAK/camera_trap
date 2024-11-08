#include "../headers/ImageReader.h"
#include "../headers/SequentialBackgroundExtractor.h"
#include "../headers/ParallelBackgroundExtractor.h"
#include "../headers/ImageSaver.h"
#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::path resourcesPath = std::filesystem::current_path() / "resources/images";
    ImageReader reader(resourcesPath);

    std::vector<std::vector<Pixel>> imagesPixels = reader.readImages();

    // Предполагается, что все изображения имеют одинаковый размер
    int width = 640;
    int height = 298;

    // Последовательное извлечение фона
    SequentialBackgroundExtractor seqExtractor;
    std::vector<Pixel> sequentialBackground = seqExtractor.extract(imagesPixels);
    ImageSaver::saveImage("sequential_background.png", sequentialBackground, width, height);

    // Параллельное извлечение фона
    ParallelBackgroundExtractor parExtractor;
    std::vector<Pixel> parallelBackground = parExtractor.extract(imagesPixels);
    ImageSaver::saveImage("parallel_background.png", parallelBackground, width, height);

    return 0;
}
