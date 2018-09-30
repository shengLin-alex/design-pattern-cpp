#ifndef PROXY_H
#define PROXY_H

#include <cstring>
#include <iostream>

// A interface for Image
class Image
{
    public:
        virtual void draw() = 0;
};

// This is some class that use system resource.
class RealImage : public Image
{
    public:
        RealImage(int);
        ~RealImage();
        void draw();

    private:
        int _id;
};

class ProxyImage : public Image
{
    public:
        ProxyImage(int);
        ~ProxyImage();
        void draw();

    private:
        int _id;
        RealImage* _realImage;
};

#endif