#include "OCR.h"

using namespace std;

string OCR(char* image) {
    tesseract::TessBaseAPI tessBaseApi;
    tessBaseApi.Init("/usr/local/share/tessdata", "eng");
    PIX *pix = pixRead(image);
    tessBaseApi.SetImage(pix);
    string text = tessBaseApi.GetUTF8Text();
    pixDestroy(&pix);
    return text;
}
