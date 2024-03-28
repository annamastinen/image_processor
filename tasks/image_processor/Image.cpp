#include "Image.h"
#include "RGB.h"

Image::Image() {
}

Image::Image(int width, int height) : width_(width), height_(height), pixels_(height_, std::vector(width_, RGB())) {
}

int Image::Width() const {
    return width_;
}

int Image::Height() const {
    return height_;
}

int Image::GetRowPixels() const {
    return y_pixels_;
}

int Image::GetColumnPixels() const {
    return x_pixels_;
}

RGB Image::GetMatrix(int x, int y) const {
    return pixels_[y][x];
}

void Image::Update(RGB rgb, int x, int y) {
    pixels_[y][x] = rgb;
}