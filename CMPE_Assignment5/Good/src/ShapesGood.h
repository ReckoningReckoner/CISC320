/*
 * Polymorphism for assignment 5
 *
 * Viraj Bangari
 */

#ifndef SHAPES_GOOD_H
#define SHAPES_GOOD_H

#include <string>

class Filled {
    public:
        Filled(std::string);
        virtual ~Filled() {};

    protected:
        std::string fillColor;
        virtual void fill() = 0;
};

class Labled {
    public:
        Labled(std::string);
        virtual ~Labled() {};

    protected:
        std::string textLabel;
        virtual void drawText() = 0;
};

class Shape {
    private:
        int length;
        int width;

    public: 
        Shape(int, int, std::string);
        virtual ~Shape() {};
        int getLength() const { return length; }
        int getWidth() const { return width; }
        virtual void draw() = 0;

    protected:
        std::string borderColor;
        virtual void drawBorder() = 0;
};

class Square : public Shape {
    public:
        Square(int, int, std::string);
        virtual void draw() {
            drawBorder();
        }

    protected:
        virtual void drawBorder();
};

class FilledSquare : public Square, Filled {
    public:
        FilledSquare(int, int, std::string, std::string);
        virtual void draw() {
            drawBorder();
            fill();
        }

    protected:
        virtual void fill();
};

class FilledTextSquare : public FilledSquare, Labled {
    public:
        FilledTextSquare(int, int, std::string, std::string, std::string);
        virtual void draw() {
            drawBorder();
            fill();
            drawText();
        }

    protected:
        virtual void drawText();
};

class Circle : public Shape {
    public:
        Circle(int length, int width, std::string borderColor) :
            Shape(length, width, borderColor) {}
        virtual void draw() {
            drawBorder();
        }

    protected:
        virtual void drawBorder();
};

class FilledCircle : public Circle, Filled {
    public:
        FilledCircle(
            int length, 
            int width,
            std::string borderColor, 
            std::string fillColor) :
        Circle(length, width, borderColor), Filled(fillColor) {};
        virtual void draw() {
            drawBorder();
            fill();
        }

    protected:
        virtual void fill();
};

class Arc : public Shape { 
    public:
        Arc(int length, int width, std::string borderColor) :
            Shape(length, width, borderColor) {}
        virtual void draw() {
            drawBorder();
        }
    protected:
        virtual void drawBorder();
};

#endif
