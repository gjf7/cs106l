#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User() = default;
    User(const User& u);
    User(User &&rhs);
    User& operator=(User&& rhs);
    User(std::string name);

    // getter functions
    std::string getName() const;
    std::set<User>& getFriends();
    const std::set<User>& getFriends() const;

    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    bool operator<(const User& u) const;
    
    friend void operator+(User& u1, User& u2);

private:
    std::string name;
    std::set<User> friends;

};
