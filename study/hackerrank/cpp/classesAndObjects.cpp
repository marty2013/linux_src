#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Student
{
  private:
    vector<int> scores = vector<int>(5);

  public:
    void input();
    int calculateTotalScore();
};

void Student::input()
{
  for(int i = 0; i < 5; i++)
    cin >> scores[i];
}

int Student::calculateTotalScore()
{
  return accumulate(scores.begin(), scores.end(),0);
}

int main()
{
  int n;
  cin >> n;

  auto students = vector<Student>(n);

  for(int i = 0; i < n; i++)
    students[i].input();

  int total_score = students[0].calculateTotalScore();

  int count = 0;
  for( int i = 1; i < n; i++)
  {
    int total = students[i].calculateTotalScore();
    if( total > total_score)
      count++;
  }

  cout << count;

}
