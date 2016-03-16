#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  if(a < b){
  	swap(a,b);
  }
  
  int current_gcd;
  while(a && b){
	int temp = a%b;
	a = b;
	b =temp;
  }
  current_gcd = a;
  return current_gcd;
}

long long lcm(int a, int b) {
  //write your code here
  int t = gcd(a,b);
  long long ans =(long long) a/t*b;	
  return ans;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a,b) << std::endl;
  cout << 1.0*3/4 <<endl;
  cout << sizeof(3/4*1.0) <<endl;
  return 0;
}
