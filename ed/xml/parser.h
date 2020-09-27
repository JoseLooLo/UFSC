#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "xmlelement.h"
#include "linked_queue.h"
#include "linked_stack.h"

namespace parser {

class Parser {
    public:
        Parser(std::string filename);
        ~Parser();
        int parseFile();
        elements::XMLElement* getNextElement();
        bool hasNextElement();

    private:
        structures::LinkedStack<std::string> stack;
        structures::LinkedQueue<elements::XMLElement*> queue;
        std::string filename_;
        std::string name_;
        std::size_t width_;
        std::size_t height_;
};

}

#endif