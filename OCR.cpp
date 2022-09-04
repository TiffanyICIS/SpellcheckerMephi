#include <iostream>
#include <fstream>
#include "string"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>


char* OCR(int argc, char* argv) {
    tesseract::TessBaseAPI tessBaseApi;
    tessBaseApi.Init("/usr/local/share/tessdata", "rus");
    char *filename = NULL;
    if (argc > 1){
        PIX *pix = pixRead(argv);
        tessBaseApi.SetImage(pix);
        std::string text = tessBaseApi.GetUTF8Text();
        long prefixLength;
        const char* lastDotPosition = strchr(argv, '.');
        if (lastDotPosition != NULL){
            prefixLength = lastDotPosition - argv;
            filename = new char[prefixLength + 5];
            strncpy(filename, argv, prefixLength);
            strcpy(filename + prefixLength, ".txt\0");
        } else{
            exit(1);
        }
        std::fstream fs;
        fs.open(filename, std::fstream::out);
        if (!fs.is_open()){
            std::cout << "Ошибка открытия файла!" << std::endl;
        } else{
            fs << text;
        }
        fs.close();
        pixDestroy(&pix);
        delete [] filename;
    }
    return filename;
}
