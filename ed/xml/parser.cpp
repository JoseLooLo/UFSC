#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "xmlelement.h"
#include "linked_queue.h"
#include "linked_stack.h"
#include "parser.h"

parser::Parser::Parser(std::string filename) {
    filename_ = filename;
}

parser::Parser::~Parser() {
    stack.~LinkedStack();
    queue.~LinkedQueue();
}

int parser::Parser::parseFile() {
    std::ifstream file;
    file.open(filename_);
    if (!file.is_open()) return 1; //A error has occurred opening the file

    std::string line;
    while (std::getline(file, line)) {
        std::string tag = "";
        std::string txt = "";
        bool inTag = false;
        bool openTag = true;
        for (std::string::iterator i = line.begin(); i < line.end(); i++) {

            switch (*i) {
                case '<':
                    inTag = true;
                    openTag = true;
                    if (!txt.empty()) {
                        std::string temp = stack.top();
                        if (temp == "name") {
                            std::cout << "[DEBUG] Set name " << txt << std::endl;
                            name_ = txt;
                        } else if (temp == "height") {
                            std::cout << "[DEBUG] Set height " << txt << std::endl;
                            std::istringstream iss(txt);
                            if (iss.fail()) {
                                std::cout << "[ERROR] Inválid height: " << txt << std::endl;
                                return 1;
                            }
                            iss >> height_;
                        } else if (temp == "width") {
                            std::cout << "[DEBUG] Set width " << txt << std::endl;
                            std::istringstream iss(txt);
                            if (iss.fail()) {
                                std::cout << "[ERROR] Inválid width: " << txt << std::endl;
                                return 1;
                            }
                            iss >> width_;
                        }
                    }
                    break;
                case '/':
                    openTag = false;
                    break;
                case '>':
                    inTag = false;
                    if (openTag) {
                        stack.push(tag);
                        std::cout << "[DEBUG] Push Stack " << tag << std::endl;
                        if (tag == "data") {
                            elements::XMLElement* new_element = new elements::XMLElement(name_, width_, height_);
                            queue.enqueue(new_element);
                            std::cout << "[DEBUG] Create a new XMLElement: Name " << name_ << " Width: " << width_ << " Height: " << height_ << std::endl;
                        }
                    }
                    else {
                        std::string temp = stack.pop();
                        if (temp != tag) {
                            std::cout << "[ERROR] Inválid tag " << tag << "! Expected " << temp << " got " << tag << std::endl;
                            return 1;
                        } else {
                            std::cout << "[DEBUG] Pop Stack " << temp << std::endl;
                        }
                    }
                    tag = "";
                    txt = "";
                    break;
                default:
                    if (inTag) tag += *i;
                    else txt += *i;
                    break;
            }
        }
        if (!txt.empty()) {
            std::string temp = stack.top();
            if (temp == "data") {
                queue.back()->addLine(txt);
            }
        }
    }

    if (!stack.empty()) {
        std::cout << "[ERROR] Stack is not empty! Some tag has not been closed." << std::endl;
        return 1;
    }

    while (hasNextElement()) {
        elements::XMLElement* temp = queue.dequeue();
        temp->runMatriz();
        temp->printElement();
    }

    file.close();
    return 0;
}

bool parser::Parser::hasNextElement() {
    return !queue.empty();
}

elements::XMLElement* parser::Parser::getNextElement() {
    return queue.dequeue();
}