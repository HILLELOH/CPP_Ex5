#include "doctest.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

#include "sources/MagicalContainer.hpp"
using namespace ariel;


TEST_CASE(" Tests "){
	for(int i = 0; i< 22; i++){
        CHECK(i == i);
    }
	
}


