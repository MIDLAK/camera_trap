#include "../headers/ImageReader.h"
#include "../headers/BackgroundExtractor.h"
#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::path resourcesPath = std::filesystem::current_path() / "resources/images";
    ImageReader reader(resourcesPath);

    std::vector<std::vector<Pixel>> imagesPixels = reader.readImages();

    for (const auto& pixels : imagesPixels) {
        BackgroundExtractor::extract(pixels);
    }
    return 0;
}
