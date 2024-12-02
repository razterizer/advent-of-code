//
//  day1.h
//  advent-of-code
//
//  Created by Rasmus Anthin on 2024-12-02.
//

#pragma once
#include <Core/TextIO.h>
#include <vector>
#include <string>

namespace aoc_2024
{

  void day1()
  {
    std::vector<std::string> lines;
    TextIO::read_file("2024/day1/data.txt", lines);
  }

}
