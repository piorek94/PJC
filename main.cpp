#include <iostream>

#include "gwindow.h"

int main( int argc, char* args[] )
{
    const char *a="trawa.bmp";
    GWindow* mainWindow = new GWindow(a);
    delete mainWindow;
    return 0;
}
