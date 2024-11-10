#include "../headers/BackgroundExtractor.h"
#include "../headers/Pixel.h"
#include <vector>

void BackgroundExtractor::calculateBackground(
    const std::vector<std::vector<Pixel>>& imagesPixels,
    std::vector<Pixel>& background,
    int start, 
    int end
) {
    int numImages = imagesPixels.size();

    /* временные массивы для суммирования цветовых каналов */
    std::vector<int> redSum(end - start, 0);
    std::vector<int> greenSum(end - start, 0);
    std::vector<int> blueSum(end - start, 0);

    /* суммирование значений пикселей по каждому изображению */
    for (int i = 0; i < numImages; ++i) {
        for (int j = start; j < end; ++j) {
            redSum[j - start] += imagesPixels[i][j].red;
            greenSum[j - start] += imagesPixels[i][j].green;
            blueSum[j - start] += imagesPixels[i][j].blue;
        }
    }

    /* среднее значение для каждого пикселя и сохране в фон */
    for (int j = start; j < end; ++j) {
        background[j].red = redSum[j - start] / numImages;
        background[j].green = greenSum[j - start] / numImages;
        background[j].blue = blueSum[j - start] / numImages;
    }
}
