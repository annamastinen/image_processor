#pragma once
#include "Image.h"
#include <iostream>

class Filter {
public:
    Filter(){};

    virtual ~Filter() {
    }

    virtual void Change(Image& image, const std::vector<std::string>& params) {
    }
};

class Negative : public Filter {
public:
    Negative();

    ~Negative() override {
    }

    void Change(Image& image, const std::vector<std::string>& params) override;
};