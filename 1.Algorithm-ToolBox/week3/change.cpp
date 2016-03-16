#include <iostream>

int coins[3] = {10, 5, 1};

int get_change(int n) {
  //write your code here
  int ans = 0;
  while(n > 0){
  	for(int i = 0; i < 3; ++i){
  		int temp = n/coins[i];		
  		ans += temp;
  		n -= temp * coins[i];
  	}
  }
  return ans;
  //return n;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
