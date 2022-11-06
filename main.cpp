#include <iostream>
#include "interface.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

int main(int argc, const char * argv[]) {
    interface Interface = interface();
    Interface.spell_check();

    return 0;
}
