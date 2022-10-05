//
// Created by ilyakudryavtsev on 9/4/22.
//
#ifndef OCR_H
#define OCR_H

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include <fstream>
#include "string"

std::string OCR(char* image);

#endif //OCR_H
