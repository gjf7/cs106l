/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>
#include <random>

std::set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::set<std::string> ret;

    std::string line;
    std::ifstream file(filename);
    while(getline(file, line)) {
      std::cout << line << std::endl;
      ret.insert(line);
    }
    return ret;
}

std::queue<const std::string*> find_matches(std::set<std::string> &students) {
    std::queue<const std::string*> ret;
    // TODO: Implement this function.
    for (const auto &name : students) {
      std::istringstream iss(name);
      std::string first_name;
      getline(iss, first_name, ' ');
      std::string last_name;
      getline(iss, last_name, ' ');
      
      if (first_name[0] == 'S' && last_name[0] == 'G')
        ret.push(&name);
    }
    return ret;
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    std::set<std::string> students = get_applicants("students.txt");
    std::queue<const std::string*> queue =  find_matches(students);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, queue.size()); // define the range
    
    for (int i = 0; i < distr(gen); i++) {
        queue.pop();
    }
    
    std::cout << "one true match:" << *(queue.back()) << std::endl;

    return 0;
}
