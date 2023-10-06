//
// Created by Rodrigo Salazar on 10/6/23.
//

#include <iostream>

#include "abi.h"

__attribute__((constructor))
static void printWidgetSize() {
  std::cout << "New abi size: " << sizeof(create_widget()) << std::endl;
}