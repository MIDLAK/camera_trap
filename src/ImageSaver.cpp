#include "../headers/ImageSaver.h"

void ImageSaver::saveImage(const std::string& filePath, const std::vector<Pixel>& pixels, int width, int height) {
    /* созадние изображения OpenCV с заданным размером */
    cv::Mat image(height, width, CV_8UC3);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Pixel& pixel = pixels[y * width + x];
            /* в OpenCV BGR, а не RGB формат */
            image.at<cv::Vec3b>(y, x) = cv::Vec3b(pixel.blue, pixel.green, pixel.red);
        }
    }

    /* сохранение изображения на диск */
    if (!cv::imwrite(filePath, image)) {
        throw std::runtime_error("[err]: Ошибка сохранения изображения " + filePath);
    }
}
