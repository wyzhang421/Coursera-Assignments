#include <iostream>
#include <climits>
using namespace std;

int get_fibonacci_last_digit(int n) {
  //write your code here
  
  int a = 0, b = 1;
  int ans;
  int i = 2;
  while(i<=n){
  	ans = (a + b) % 10;
  	a = b;
  	b = ans;
  	++i;
  }
  
  ans = n<=1 ? n : ans;
  return ans;
  //return 0;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
