#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main() {
  std::cout << "What's name of the file containing the graph to visualize?" << std::endl;

  while (true) {
    std::string filename;
    getline(std::cin, filename);
    std::ifstream file(filename);

    if (!file.is_open()) {
      std::cout << "File:" << filename << "isn't exist, please input filename again" << std::endl;
      continue;
    }

    
    std::string line;
    getline(file, line);
    int n = std::stoi(line);
    
    std::cout << n << std::endl;

    /* const double kPi = 3.14159265358979323; */
    /* for (int i = 0; i < n; i++) { */
    /*   double x = 2 * kPi * n / n; */
    /*   Node node = { std::cos(x), std::sin(x) }; */
    /*   nodes.push_back(node); */
    /* } */

    /* std::vector<Edge> edges; */
    while (getline(file, line)) {
      std::stringstream ss(line);
      std::string item;

      getline(ss, item, ' ');
      size_t left = std::stoi(item);

      getline(ss, item, ' ');
      size_t right = std::stoi(item);

      /* Edge edge = { left, right }; */
      std::cout << left << ", " << right << std::endl;
    }

  }
}
