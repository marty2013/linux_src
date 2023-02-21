#include <iostream>
#include <vector>

void Fun(std::vector<int>& v)
{
  std::cout << "by ref\n";
}

void Fun(const std::vector<int>& v)
{
  std::cout << "by const ref\n";
}

void Fun(std::vector<int>&& v)
{
  std::cout << "by move ref\n";
}

void Use()
{
  std::vector<int> v{2, 3, 4};
  const std::vector<int> cv{5, 6, 7};

  Fun(v);           // We pass a lvalue
  Fun(cv);          // We pass a const lvalue
  Fun({3, 5, 6});   // We pass a temporary - will trigger the move overload...
  
  std::vector<int> vv{2, 3, 4};
  Fun(static_cast<std::vector<int>&&>(vv)); // Will pass by rvalue ref...

  std::vector<int> vv2{4, 5, 6};
  Fun(std::move(vv2));  // Same as previous essentially...
  // as above - it is really just changing the value category such that
  // the correct overload of Fun is being called. 

  // std::move is only a cast. The overloads can move if they exist.
  // Temporary objects are picked up by default using move operations.
  // *Only* if we have an object *we* no longer want to use we can say std::move
  // Move semantics is nothing else than  an additional overload that is allowed
  // and *expected* to steal data from a source object.
  // Move sementics is just "stealing".
  //

}

int main()
{
  Use();
}

