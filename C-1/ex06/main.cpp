#include "Harlfilter.hpp"

int main(int argc, char **argv){
    if (argc != 2)
        return 1;
    Harlfilter h;
    h.complain(argv[1]);
    return 0; 
}