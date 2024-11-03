#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include "Pixel.h"
#include <vector>
#include <string>
#include <opencv4/opencv2/opencv.hpp>

class ImageReader {
public:
    ImageReader(const std::string& directoryPath);
    /* чтение изображений из указанной директории */
    std::vector<std::vector<Pixel>> readImages();

private:
    /* путь до директории с серией изображений */
    std::string directoryPath;

    /* чтение изображения по указанному пути */
    std::vector<Pixel> readImage(const std::string& filePath);
    /* преобразование внешнего OpenCV формата изображения во внутренний */ 
    std::vector<Pixel> convert(const cv::Mat& image);
};

#endif
