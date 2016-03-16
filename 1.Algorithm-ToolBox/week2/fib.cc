#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

vector<int>& calc_fib(int n) {
	result.push_back(0);
	result.push_back(1);
	for(auto i = 2; i <= n; ++i){
		result.push_back(result[i-1]+result[i-2]); 
	}
	return result;
}

int main() {
    int n = 0;
    std::cin >> n;
	result = calc_fib(50);
	
	std::cout << result[n] << '\n';
	
    
    return 0;
}
