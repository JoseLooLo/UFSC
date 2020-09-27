#include <iostream>
#include "xmlelement.h"

elements::XMLElement::XMLElement(std::string name, std::size_t width, std::size_t height) {
    name_ = name;
    width_ = width;
    height_ = height;
    elements = 0;
    line_ = 0;
    matriz = (int**) malloc(sizeof(int*)*height_);
    if (matriz == nullptr)
        std::cout << "Failed to malloc " << std::endl;
    for (int i = 0; i < height_; i++) {
        matriz[i] = (int*) malloc(sizeof(int)*width_);
        if (matriz[i] == nullptr)
            std::cout << "Failed to malloc " << std::endl;
    }
}

elements::XMLElement::~XMLElement() {
    for (int i = 0; i < width_; i++)
        free(matriz[i]);
    free(matriz);
}

std::string elements::XMLElement::getName() const {
    return name_;
}

std::size_t elements::XMLElement::getWidth() const {
    return width_;
}

std::size_t elements::XMLElement::getHeight() const {
    return height_;
}

std::size_t elements::XMLElement::getElements() const {
    return elements;
}

void elements::XMLElement::addElement() {
    elements++;
}

void elements::XMLElement::runMatriz() {
    for (int i = 0; i < height_; i++)
        for (int j = 0; j < width_; j++)
            if (matriz[i][j] == 1) {
                recursive(i,j);
                addElement();
            }
}

void elements::XMLElement::recursive(int line, int collun) {
    matriz[line][collun] = getElements() + 2;
    if (line +1 < height_) 
        if (matriz[line+1][collun] == 1) recursive (line+1, collun);
    if (line -1 >= 0)
        if (matriz[line-1][collun] == 1) recursive (line-1, collun);
    if (collun + 1 < width_)
        if (matriz[line][collun+1] == 1) recursive (line, collun+1);
    if (collun - 1 >= 0) 
        if (matriz[line][collun-1] == 1) recursive (line, collun-1);
}

void elements::XMLElement::addLine(std::string line) {
    //std::cout << line.length() << " - " << line_ << std::endl;
    char* str = const_cast<char*>(line.c_str());
    for (int i = 0; i < width_; i++) {
        matriz[line_][i] = (int) str[i] - 48;
        //std::cout << matriz[line_][i];
    }
    //std::cout << std::endl;
    line_++;
}

void elements::XMLElement::printElement() {
    std::cout << name_ << " " << getElements() << std::endl;
    return;
    std::cout << "============================" << std::endl;
    std::cout << "Element " << name_ << std::endl;
    std::cout << "Height " << height_ << std::endl;
    std::cout << "Width " << width_ << std::endl;
    std::cout << "Nº Elements " << getElements() << std::endl;
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++)
            std::cout << "" << matriz[i][j];
        std::cout << std::endl;
    }
    std::cout << "============================" << std::endl;
}