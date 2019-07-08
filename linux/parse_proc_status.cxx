#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


using token_t = std::pair<std::string, unsigned long>; 

bool parse_and_update(const std::string line, std::vector<token_t>& tokens);


int main(int argc, char **argv)
{
  std::vector< token_t > tokens{
    {"VmPeak",   0},
    {"VmSize",   0},
    {"VmHWM",    0},
    {"VmRSS",    0},
    {"RssAnon",  0},
    {"RssFile",  0},
    {"RssShmem", 0}
  };

  std::ifstream procfile("/proc/self/status");

  std::string line;
  while (std::getline(procfile, line))
  {
    parse_and_update(line, tokens);
  }

  for (auto& token : tokens)
  {
    std::cout << "result: " << token.first << ", " << token.second << '\n';
  }

  return EXIT_SUCCESS;
}


bool parse_and_update(const std::string line, std::vector<token_t>& tokens)
{
  std::string label;
  std::istringstream iss(line);

  iss >> label;

  for (token_t& token : tokens)
  {
    if (label.find(token.first) != std::string::npos) {
      iss >> token.second;
      std::cout << "found token: " << token.first << " = " << token.second << " kB\n";
      return true;
    }
  }

  return false;
}
