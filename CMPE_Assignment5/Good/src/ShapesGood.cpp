#include "ShapesGood.h"
#include <iostream>


/* Filled */
Filled::Filled(std::string fc) : fillColor(fc) {}

/* Labled */
Labled::Labled(std::string tl) : textLabel(tl) {}

/* Shape */
Shape::Shape(int length_, int width_, std::string borderColor_) 
    : length(length_), width(width_), borderColor(borderColor_) {}

/* Square */
Square::Square(int length, int width, std::string borderColor) :
    Shape(length, width, borderColor) {}

void Square::drawBorder() {
    std::cout << "\nDrawing a " + borderColor + " square.";
}

/* Filled Square */
FilledSquare::FilledSquare(int length, int width, std::string borderColor, std::string fillColor) :
    Square(length, width, borderColor), Filled(fillColor) {};

void FilledSquare::fill() {
    std::cout << " With " + fillColor + " fill.";
}

FilledTextSquare::FilledTextSquare(
        int length, 
        int width, 
        std::string borderColor, 
        std::string fillColor,
        std::string textLabel) :
    FilledSquare(length, width, borderColor, fillColor), Labled(textLabel) {};

void FilledTextSquare::drawText() {
    std::cout << " Containing the text: \"" << textLabel << "!\"";
}

/* Circle */
void Circle::drawBorder() {
    std::cout << "\nDrawing a " + borderColor + " circle.";
}

/* FilledCircle */
void FilledCircle::fill() {
    std::cout << " With " + fillColor + " fill.";
}

/* Arc */
void Arc::drawBorder() {
    std::cout << "\nDrawing a " + borderColor + " arc.";
}
