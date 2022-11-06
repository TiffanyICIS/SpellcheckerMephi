cmake_minimum_required(VERSION 3.23)
project(SpellingChecker)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/share/tesseract)


add_executable(SpellingChecker main.cpp BKTree.cpp OCR.cpp interface.hpp)

target_link_libraries (SpellingChecker -llept -ltesseract)