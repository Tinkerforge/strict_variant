/**
 * @file main.cpp
 * @author Vinicius de Sa
 * @brief This is a basic example using strict_variant.
 * @version 0.1
 * @date 2019-11-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <Arduino.h>
#include "strict_variant/variant.hpp"

using namespace strict_variant;

std::string getString(variant<int, std::string> v);
int getInt(variant<int, std::string> v);
void printParams(std::vector<variant<int, std::string>> params);

void setup()
{
    Serial.begin(115200);

    printf("Starting ...");

    std::vector<variant<int, std::string>> params;

	variant<int, std::string> param1;
	param1 = "1031001";

	variant<int, std::string> param2;
	param2 = 60;
	
	params.push_back(param1);
	params.push_back(param2);
	
	printParams(params);

    while (1);
}

void loop()
{
}

void printParams(std::vector<variant<int, std::string>> params)
{
    printf("Printing parameters...\n");

    variant<int, std::string> param1 = params[0];
    printf("Param1: %s\n", getString(param1).c_str());

    variant<int, std::string> vlimCurva;
    vlimCurva = params[1];
    printf("Param2: %d\n", getInt(vlimCurva));
}

int getInt(variant<int, std::string> v)
{
    return *(get<int>(&v));
}

std::string getString(variant<int, std::string> v)
{
    return *(get<std::string>(&v));
}