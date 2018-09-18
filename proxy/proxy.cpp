#include "proxy.h"

RealImage::RealImage(int id) : _id(id)
{
}

RealImage::~RealImage()
{
}

void RealImage::draw()
{
    std::cout << "Image: " << this->_id << " drawing." << std::endl;
}

ProxyImage::ProxyImage(int id) : _id(id)
{
    this->_realImage = new RealImage(id);
}

ProxyImage::~ProxyImage()
{
    delete this->_realImage;
}

void ProxyImage::draw()
{
    this->_realImage->draw();
}