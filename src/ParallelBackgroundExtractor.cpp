#include "../headers/ParallelBackgroundExtractor.h"
#include <iostream>
#include <iterator>

void ParallelBackgroundExtractor::extractPixels(
    const std::vector<std::vector<Pixel>>& imagesPixels, 
    std::vector<Pixel>& background, 
    int start, 
    int end,
    Barrier& barrier
) {
    int numImages = imagesPixels.size();
    calculateBackground(
        imagesPixels, 
        background, 
        start, 
        end
    );

    /* ожидание обработки кадра всеми потоками */
    barrier.arrive_and_wait();
}

std::vector<Pixel> ParallelBackgroundExtractor::extract(
    const std::vector<std::vector<Pixel>>& imagesPixels
) {
    int imageSize = imagesPixels[0].size();
    std::vector<Pixel> background = imagesPixels[0];

    /* разделение пикселей по потокам */
    int numThreads = std::thread::hardware_concurrency();
    int chunkSize = imageSize / numThreads;
    std::vector<std::thread> threads;

    std::cout << "[info]: кол-во потоков: " << numThreads
        << " (" << chunkSize << " пикселей на поток)" << std::endl;

    Barrier barrier(numThreads);

    for (int i = 0; i < numThreads; ++i) {
        /* индексы начала и конца обрабатываемого участка */
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? imageSize : start + chunkSize;

        /* создание потока и выполнение обработки пикселей */
        threads.emplace_back(
            &ParallelBackgroundExtractor::extractPixels, 
            this, 
            std::cref(imagesPixels), /* ссылка только на чтение */
            std::ref(background), 
            start, 
            end,
            std::ref(barrier)
        );
    }

    /* ожидание завершения всех потоков */
    for (auto& thread : threads) {
        thread.join();
    }

    return background;
}
