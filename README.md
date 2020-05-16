# aplot
Library for Dynamic and Animated Plots from C/C++. 

Library is self contained with two files:

1. aplot.h
2. aplot.cc

General instructions for use:

A. Download these files to any directory.

B. Include the header in the main program.
#include<path./././aplot.h>
int main()
{
/// check the aplot_test1.cc/aplot_test2.cc/aplot_test.cc for usage
.......
.........
return 0;
}

C. Compilation
$ g++ -c  path./././aplot.cc

D. Execution
$ g++ test_aplot1.cc aplot.o -o test_aplot1.exe (for example).
$ ./test_aplot1.exe

BINGO! See the REULTS!



