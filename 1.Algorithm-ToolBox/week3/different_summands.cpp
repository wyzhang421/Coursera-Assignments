#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n < 1) return summands;
  int left = n;
  for(auto i = 1; i <= left; ++i){
  	if(i == left){
  	  summands.push_back(i);
  	  break;
  	}
  	else if( 2 * i < left){
  	  summands.push_back(i);
  	  left -= i;
  	}
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
