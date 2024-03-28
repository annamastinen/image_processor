#include "Filter.h"
#include "Image.h"
#include <iostream>

Negative::Negative() {
}

void Negative::Change(Image& image, const std::vector<std::string>& params) {
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            RGB rgb = image.GetMatrix(i, j);
            rgb.r_ = 1 - rgb.r_;  // NOLINT
            rgb.g_ = 1 - rgb.g_;  // NOLINT
            rgb.b_ = 1 - rgb.b_;  // NOLINT
            image.Update(rgb, i, j);
        }
    }
}

Grayscale::Grayscale() {
}

void Grayscale::Change(Image& image, const std::vector<std::string>& params) {
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            RGB rgb = image.GetMatrix(i, j);
            rgb.r_ = 0.299 * rgb.r_ + 0.587 * rgb.g_ + 0.114 * rgb.b_;  // NOLINT
            rgb.g_ = 0.299 * rgb.r_ + 0.587 * rgb.g_ + 0.114 * rgb.b_;  // NOLINT
            rgb.b_ = 0.299 * rgb.r_ + 0.587 * rgb.g_ + 0.114 * rgb.b_;  // NOLINT
            image.Update(rgb, i, j);
        }
    }
}