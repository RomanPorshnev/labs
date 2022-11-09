#include "ExtendedControllerFile.h"
#include <fstream>
#include <string>
#include <iostream>
ExtendedControllerFile::ExtendedControllerFile()
{
    id = 0;
}

int ExtendedControllerFile::execute()
{
    std::ifstream fin("FileSourceController.txt");
    std::getline(fin, buff_controller);
    fin.close();
    if (id != buff_controller.length()) {
        id++;
        return buff_controller[id - 1];
    }
    else {
        return -1;
    }
}
