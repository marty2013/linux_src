// utils.h
// Usefull utility code
//
// Author: Martin Gay
// Date: Feb-2023

#ifndef __MGUTILS__
#define __MGUTILS__

#include <iostream>
#include <vector>

namespace mg
{
  template<typename T>
  void print_vector( std::vector<T> v, bool single_line = true)
  {
    for( T i: v)
    {
      std::cout << i;
      if(single_line)
        std::cout << " ";
      else
        std::cout << "\n";
    }
  
    std::cout << "\n";

  } 

}

#endif

