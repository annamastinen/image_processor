#include "Filter.h"
#include "Image.h"

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