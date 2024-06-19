#include "MyCollection.h"
#include <iostream>
#include <string>

struct User {
  std::string name;
  int age;
};

int main() {
  {
    Collection<int> intArr = Array<unsigned int>();
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    std::cout << "enter " << n << "positive integers: " << std::endl;
    for (int i = 0; i < n; ++i) {
      int a;
      std::cin >> a;
      intArr.add(a);
    }
    Collection<int> intArr2 = Array<unsigned int>();
    int m;
    std::cout << "enter m: ";
    std::cin >> m;
    std::cout << "enter " << m << "positive integers: " << std::endl;
    for (int i = 0; i < m; ++i) {
      int a;
      std::cin >> a;
      intArr2.add(a);
    }

    intArr.addAll(intArr2);
    if (intArr.equals(intArr2)) {
      std::cout << "looks like n is zero" << std::endl;
    }

    bool exit_loop = false;
    while (!exit_loop) {
      int a;
      std::cout << "enter a number to check if intArr contains it or not (-1 "
                   "to exit): ";
      std::cin >> a;
      if (a >= 0) {
        if (intArr.contains((unsigned int)a)) {
          std::cout << "intArr contains " << a << std::endl;
        } else {
          std::cout << "intArr does not contain " << a << std::endl;
        }
      } else {
        exit_loop = true;
      }
    }
    // check if intArr contains all intArr2 elements
    if (intArr.containsAll(intArr2)) {
      std::cout << "intArr contains all of intArr2 elements" << std::endl;
    } else {
      std::cout << "intArr does not contain all of intArr2 elements"
                << std::endl;
    }
    std::cout << "intArr size: " << intArr.size() << std::endl;
    for (int i = 0; i < intArr.size(); ++i) {
      std::cout << intArr[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "increase all of intArr elements by one" << std::endl;
    for (int i = 0; i < intArr.size(); ++i) {
      intArr[i]++;
    }
    intArr.clear();
    std::cout << "intArr size after clear(): " << intArr.size()
              << (intArr.isEmpty() ? " & as expected, intArr is empty"
                                   : "weird world!")
              << std::endl;
  }
  {
    Collection<int> charArr = Array<char>();
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    std::cout << "enter " << n << "characters: " << std::endl;
    for (int i = 0; i < n; ++i) {
      char a;
      std::cin >> a;
      charArr.add(a);
    }
    // remove all a from array
    if (charArr.remove('b')) {
      std::cout << "b removed from array" << std::endl;
    } else {
      std::cout << "there were no b in array" << std::endl;
    }
    char vowelsArr[] = {'a', 'e', 'i', 'o', 'u'};
    Collection<char> vowels = Array<char>(vowelsArr);
    charArr.removeAll(vowels);
    std::cout << "all vowels removed: ";
    for (int i = 0; i < charArr.size(); ++i) {
      std::cout << charArr[i];
    }
    std::cout << std::endl;
  }
  {
    Collection<User> *users = new LinkedList<User>();
    User mammad = User{
        .age = 18,
        .name = "mammad",
    };
    User reza = User{
        .age = 19,
        .name = "reza",
    };
    User hossein = User{
        .age = 19,
        .name = "hossein",
    };
    User nima = User{
        .age = 19,
        .name = "nima",
    };
    users->add(mamad);
    users->add(reza);
    LinkedList<Users> *usersLinkedList =
        dynamic_cast<LinkedList<Uers> *>(users);
    users->AddFirst(reza);
    users->AddLast(mammad);
    Collection<User> newUsers = Array<User>();
    newUsers.add(reza);
    newUsers.add(nima);
    users->addAll(newUsers);
    for (int i = 0; i < users.size(); ++i) {
      std::cout << "user " << i + 1 << "name is " << users->at(i).name
                << " and age is " << users->at(i).age << std::endl;
    }
    delete users;
  }
  return 0;
}