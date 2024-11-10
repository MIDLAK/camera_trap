#ifndef BACKGROUNGEXTRACTOR_H
#define BACKGROUNGEXTRACTOR_H

#include "Pixel.h"
#include <vector>

class BackgroundExtractor {
public:
    /* выделение фона на изображении */
    virtual std::vector<Pixel> extract(const std::vector<std::vector<Pixel>>& imagesPixels) = 0;
    virtual ~BackgroundExtractor() = default;
protected:
    /* функция для вычисления среднего фона по изображениям */
    void calculateBackground(
        const std::vector<std::vector<Pixel>>& imagesPixels,
        std::vector<Pixel>& background,
        int start, 
        int end
    );
};

#endif
