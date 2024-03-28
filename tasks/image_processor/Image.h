#pragma once
#include <vector>
#include "RGB.h"

class Image {
private:
    int width_ = 0;
    int height_ = 0;
    int x_pixels_ = 0;
    int y_pixels_ = 0;
    std::vector<std::vector<RGB>> pixels_;

public:
    Image();
    Image(int width, int height);

    RGB GetMatrix(int x, int y) const;

    void Update(RGB rgb, int x, int y);

    int GetColumnPixels() const;

    int GetRowPixels() const;

    int Width() const;

    int Height() const;

    friend void Save(const char* path, Image& image);

    void Read(const char* path);
};
