//
//  day2.h
//  advent-of-code
//
//  Created by Rasmus Anthin on 2024-12-02.
//

#pragma once
#include <Core/TextIO.h>
#include <Core/StlUtils.h>
#include <Core/Math.h>
#include <vector>
#include <string>
#include <sstream>

namespace aoc_2024
{

  void day2()
  {
    std::vector<std::string> lines;
//#define TEST
#ifndef TEST
    TextIO::read_file("2024/day2/data.txt", lines);
#else
    lines = {
      "7 6 4 2 1",
      "1 2 7 8 9",
      "9 7 6 2 1",
      "1 3 2 4 5",
      "8 6 4 4 1",
      "1 3 6 7 9"
    };
#endif
    
    int num_safe = 0;
    int num_safe_pd = 0;
    std::vector<int> vec;
    std::istringstream iss;
    for (const auto& str : lines)
    {
      vec.clear();
      iss.clear();
      iss.str(str);
      while (!iss.eof())
      {
        int v = 0;
        iss >> v;
        vec.emplace_back(v);
      }
      auto vec_diff = stlutils::diff(vec);
      if (!vec_diff.empty())
      {
        auto Ndiff = stlutils::sizeI(vec_diff);
        auto first_sgn = math::sgn(vec_diff.front());
        auto f_is_safe = [first_sgn](const std::vector<int>& diff_v)
        {
          if (!stlutils::contains_if(diff_v, [first_sgn](int dv) { return first_sgn != math::sgn(dv);  }))
            if (!stlutils::contains_if(diff_v, [](int dv) { return std::abs(dv) > 3; }))
              return true;
          return false;
        };
        
        if (f_is_safe(vec_diff))
        {
          num_safe++;
          num_safe_pd++;
        }
        else
        {
          for (int i = 0; i < Ndiff; ++i)
          {
            auto vec_diff2 = vec_diff;
            stlutils::erase_at(vec_diff2, i);
            if (f_is_safe(vec_diff2))
            {
              //std::cout << str << std::endl;
              num_safe_pd++;
              break;
            }
          }
        }
      }
    }
    std::cout << "Part 1 : # safe = " << num_safe << std::endl;
    std::cout << "Part 2 : # safe (with problem dampener) = " << num_safe_pd << std::endl;
  }

}
