//
// Created by Austin B. on 2/22/23.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "iostream"
#include <string>
#include <fcntl.h>
#include <fstream>

using std::cout; using std::fstream;
using std::endl; using std::string;

int main() {

    string filename("outputLab4.txt");
    fstream file;

    file.open(filename, std::ios_base::app | std::ios_base::in);
    if (file.is_open())
        file <<  "This is a test for opening, writing, and closing a file!" << endl;
    file.close();

    return EXIT_SUCCESS;

}