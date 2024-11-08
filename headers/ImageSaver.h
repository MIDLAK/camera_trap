#ifndef IMAGESAVER_H
#define IMAGESAVER_H

#include <vector>
#include <string>
#include "Pixel.h"
#include <opencv4/opencv2/opencv.hpp>

class ImageSaver {
public:
    static void saveImage(const std::string& filePath, const std::vector<Pixel>& pixels, int width, int height);
};

#endif
