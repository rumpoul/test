#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "intersect_realization.h"

int main()
{
    srand(time(NULL));

    std::vector<int> array1;
    randomShaffle(array1, 10);
    output(array1);

    std::vector<int> array2;
    randomShaffle(array2, 15, 25, 10);
    output(array2);

    std::cout<<"\n\n*******************INSERTION START*************************";
    std::vector<int> inser = intersection(array1, array2);
    output(inser);
    std::cout<<"*******************INSERTION END***************************";

    return 0;
}

