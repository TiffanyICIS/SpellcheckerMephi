#include <iostream>
#include <fstream>
#include "string"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>


int main(int argc, char* argv[]) {
    tesseract::TessBaseAPI tessBaseApi;
    tessBaseApi.Init("/usr/local/share/tessdata", "rus");
    if (argc > 1){
        PIX *pix = pixRead(argv[1]);
        tessBaseApi.SetImage(pix);
        std::string text = tessBaseApi.GetUTF8Text();
        char *filename = NULL;
        long prefixLength;
        const char* lastDotPosition = strchr(argv[1], '.');
        if (lastDotPosition != NULL){
            prefixLength = lastDotPosition - argv[1];
            filename = new char[prefixLength + 5];
            strncpy(filename, argv[1], prefixLength);
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
    return 0;
}
