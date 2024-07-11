/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 5/10/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <algorithm>
#include <fstream>
#include <numeric>  


// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template<typename T>
requires std::integral<T> || std::floating_point<T>
double convert_f_to_c(const T &fahrenheit){
  return (fahrenheit - 32 * 5 / 9);
}

template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<double>> readings, Function fn) {
    // TODO: write get_forecast here!
  std::vector<double> ret;
  for (auto &day_of_temperature : readings) {
    ret.push_back(fn(day_of_temperature));
  }
  return ret;
}

void print(std::vector<double> v, std::ofstream &file) {
  for (auto it = v.begin(); it < v.end(); it++) {
    file << *it;
    if (it != v.end()) {
      file << " ";
    }
  }
  file << std::endl;
}

int main() {
    std::vector<std::vector<double>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    // TODO: Convert temperatures to Celsius and output to output.txt
    std::ofstream file("output.txt");
    for (auto& v : readings) {
      std::transform(v.begin(), v.end(), v.begin(), convert_f_to_c<double>);
      print(v, file);
    }
    // TODO: Find the maximum temperature for each day and output to output.txt
    auto find_max = [](std::vector<double> v) {
      double ret = -1;
      for (double value: v) {
        ret = value > ret ? value : ret;
      }
      return ret;
    };
    print(get_forecast(readings, find_max), file);
    // TODO: Find the minimum temperature for each day and output to output.txt
    auto find_min = [](std::vector<double> v) {
      double ret = 999999;
      for (double value: v) {
        ret = value < ret ? value : ret;
      }
      return ret;
    };
    print(get_forecast(readings, find_min), file);
    
    // TODO: Find the average temperature for each day and output to output.txt
    auto find_average = [](std::vector<double> v) {
      return std::reduce(v.begin(), v.end()) / v.size();
    };
    print(get_forecast(readings, find_average), file);

    return 0;
}
