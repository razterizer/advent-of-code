//
//  day2.h
//  advent-of-code
//
//  Created by Rasmus Anthin on 2024-12-02.
//

#pragma once
#include <Core/TextIO.h>
#include <Core/StlUtils.h>
#include <vector>
#include <string>
#include <sstream>

namespace aoc_2024
{

  void day2()
  {
    std::vector<std::string> lines;
    TextIO::read_file("2024/day2/data.txt", lines);
  }

}
