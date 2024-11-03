#include "../headers/ImageReader.h"
#include <iostream>
#include <filesystem>

ImageReader::ImageReader(const std::string& directoryPath) : directoryPath(directoryPath) {}

std::vector<std::vector<Pixel>> ImageReader::readImages() {
    std::vector<std::vector<Pixel>> imagesPixels;
    /* итерация по всем изображениям в директории */
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        std::vector<Pixel> pixels = readImage(entry.path().string());
        imagesPixels.push_back(pixels);
    }
    return imagesPixels;
}

std::vector<Pixel> ImageReader::readImage(const std::string& filePath) {
    cv::Mat image = cv::imread(filePath);
    if (image.empty()) 
        throw std::runtime_error("[err]: Невозможно загрузить изображение " + filePath);
    return convert(image);
}

std::vector<Pixel> ImageReader::convert(const cv::Mat& image) {
    std::vector<Pixel> pixels;
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            cv::Vec3b colors = image.at<cv::Vec3b>(y, x);
            /* в OpenCV применяется BGR, а не RGB */
            pixels.push_back(Pixel(colors[2], colors[1], colors[0]));
        }
    }
    return pixels;
}
