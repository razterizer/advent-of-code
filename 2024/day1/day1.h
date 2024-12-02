//
//  day1.h
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

  void day1()
  {
    std::vector<std::string> lines;
    TextIO::read_file("2024/day1/data.txt", lines);
    std::istringstream iss;
    std::vector<int> vec1, vec2;
    int val1 = 0, val2 = 0;
    for (const auto& str : lines)
    {
      iss.clear();
      iss.str(str);
      iss >> val1 >> val2;
      vec1.emplace_back(val1);
      vec2.emplace_back(val2);
    }
    stlutils::sort(vec1);
    stlutils::sort(vec2);
    auto n = std::min(stlutils::sizeI(vec1), stlutils::sizeI(vec2));
    auto dist_sum = 0;
    for (int i = 0; i < n; ++i)
    {
      val1 = vec1[i];
      val2 = vec2[i];
      auto d = std::max(val1, val2) - std::min(val1, val2);
      dist_sum += d;
    }
    std::cout << "Part 1 : dist sum = " << dist_sum << std::endl;
    
    auto sim_sum = 0;
    for (auto v1 : vec1)
      sim_sum += v1 * stlutils::count(vec2, v1);
    std::cout << "Part 2 : sim sum = " << sim_sum << std::endl;
  }

}
