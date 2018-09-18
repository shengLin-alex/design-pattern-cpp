#include "proxy.h"

int main(int argc, char** argv)
{
    ProxyImage* image = new ProxyImage(1);
    image->draw();

    delete image;

    return 0;
}