#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::pair;
using std::vector;

bool comp(pair<double, int> i, pair<double, int> j) { return i.first > j.first; }

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<pair<double, int>> per(n);

  for(int i =0; i < n; ++i){
  	double f = (double) values[i]/weights[i];
  	per[i] = std::make_pair(f, weights[i]);
  }
  sort(per.begin(), per.end(), comp);
  /*
  for(int i = 0; i < n; ++i){
  	std::cout << per[i].first <<" " << per[i].second << std::endl;
  }
  std::cout << std::endl;
  */
  for(int i = 0; i < n && capacity > 0; ++i){	
  	//std::cout << capacity << " " << per[i] << " " << value << std::endl;	
  	//std :: cout <<"capacity: "<<capacity << std::endl;
  	if(capacity - per[i].second <= 0){
  		value += per[i].first * capacity;
  	}
  	else{
  		value += per[i].first * per[i].second;
  	}
  	capacity = capacity > per[i].second ? capacity - per[i].second : 0;
  }	
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
