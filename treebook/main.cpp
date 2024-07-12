#include <iostream>
#include "user.h"

// TODO: Implement the non-member function + operator overload here!

void operator+(User& u1, User& u2) {
  u1.friends.insert(u2);
  u2.friends.insert(u1);
}

void printFriends(const User& user) {
    std::cout << user.getName() << " is friends with: " << std::endl;
    for(auto& user : user.getFriends()) {
        std::cout << "  " << user.getName() << std::endl;
    }
}

int main() {
    // create a bunch of users
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");
    User dave("Dave");

    // make them friends
    alice + bob;
    alice + charlie;

    dave + bob;
    charlie + dave;


    // print out their friends
    printFriends(alice);
    printFriends(bob);
    printFriends(charlie);
    printFriends(dave);



    return 0;

}
