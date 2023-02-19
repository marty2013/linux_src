#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  // lambda expression
  // [](parameters){body of lambda that uses parameters and possibly other values}

  auto isOdd = [](int candidate){ return candidate % 2 != 0;};
  // usage
  bool is3Odd = isOdd(3); // returns true
  bool is4Odd = isOdd(4); // returns false
  vector<int> nums {2,3,4,-1,1}; 
  int odds = count_if(begin(nums),end(nums),isOdd); // returns 3
  
  // more often used...
  int evens = count_if(begin(nums),end(nums),[](int candidate){ return candidate % 2 == 0;});

  cout << is3Odd << " " << is4Odd << " " << odds << " " << evens << endl;

  // notes...
  // [](){} - this is a valid lambda expression !
  // [] - capture clause makes variables from the calling scope available in the lambda
  // () - parameters just like you have for a function
  // {} - body just like a mini function
  // The compiler generates an anonymous function object ( a class and an instance of that
  // class that uses what went into its definition. So it is a class - it has members functions
  // and member variables.
  // One of the member functions it has is the function call operator override ().
  // When the compiler generates this function object instance it puts the parameters into
  // the () override.
  // The member variables of the function object are controlled by the capture clause..const
  // by default. Capture any variables that are needed from the calling scope.
  // [] - empty - captures nothing, use only the function parameters.
  // [x,y] - capture x and y by value where x and y are from the calling scope. These copies are
  //         into member variables of the lambda.
  //         !! These copies remain in the lambda (the function objext ) even when x and y go out of scope.
  // [x&,y&] - capture x and y by reference. Changes now effect the original. But dangling references
  //           are a big issue if the x and y go out of scope !!
  // [x=a+1, y=std::move(b)] - alias or move capture. Useful when you need it.
  // [=] - copy "everything" from the calling scope by value. Not everything is captured -
  //       just those variables in the calling scope that are used in the lambda body will be captured.
  // [&] - copy "everything" from the calling scope by reference. As above for what gets captured.
  // Mutable - allows you to change values captured by reference.
  //
  // How to capture ?
  // If the lambda is not being stored, capture by value or reference.
  // If it is being stored, then capture by value only ( if used after the things that have been
  // captured go out of scope ).
  // Use the "everything" notation above as much as possible. Easier for maintenance and readability.
  //

  int x = 3;
  int y = 7;
  string message = "elements between ";
  message += to_string(x) + " and " + to_string(y) + " inclusive: ";
  
  for_each(begin(nums), end(nums),
      [x, y, &message](int n)
      {
        if( n >= x && n <= y)
          message += " " + to_string(n);
      });

  cout << message << endl;

  x = y = 0;
  // x by value, rest by reference. So y will be updated as it is
  // being passed by ref but x will not be as the lambda has a copy
  // of x and not the actual x from the calling scope. The mutable
  // keyword avoids an error that would result from x+= as the
  // copy of x would be considered const. By-value capture cannot be
  // modified in a non-mutable lambda.ie the captured variable is
  // essentially captured as a const and mutable keywork allows
  // it to be captured as non-const.
  // see: https://stackoverflow.com/questions/5501959/why-does-c11s-lambda-require-mutable-keyword-for-capture-by-value-by-defau
  //
  for_each(begin(nums),end(nums),
      [&, x](int element) mutable {
        x += element;
        y += element;
      });

  cout << x << " " << y << endl;

  // Lambdas can return values. Usually the compiler can deduce the return
  // type from the return type of the expression that is being returned.
  // If the compiler cannot deduce the return type then we can specify 
  // that explicitly.
  // Syntax is eg "[](int n) -> double {...}"
  //
  // Parameters.
  // What to take. Generally imposed by the place you are using it. Like writing any
  // other predicate.

  // Sort of syntactic sugar - could use function objects (functors) wherever you can
  // use lambdas. And in many case ( eg standard algos like sort ) you can use a 
  // function pointer.
  // But using a lambda is better for readability as it is at the call site.
  // Also expressive.
  // If local then it cannot be changed and used differently somewhere else.
  // Function pointers and functors are difficult to implement and better
  // avoided if not necessary.
  //



}
