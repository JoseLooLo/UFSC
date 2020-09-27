#ifndef ELEMENTS_XML_ELEMENTS_H
#define ELEMENTS_XML_ELEMENTS_H

#include <iostream>
namespace elements {
class XMLElement {
    public:
        XMLElement(std::string name, std::size_t width, std::size_t height);
        ~XMLElement();
        std::string getName() const;
        std::size_t getWidth() const;
        std::size_t getHeight() const;
        std::size_t getElements() const;
        void addElement();
        void printElement();
        void runMatriz();
        void addLine(std::string line);
        void recursive(int line, int collun);
    private:
        std::string name_;
        std::size_t width_;
        std::size_t height_;
        std::size_t elements;
        std::size_t line_;
        int** matriz;
};

}

#endif