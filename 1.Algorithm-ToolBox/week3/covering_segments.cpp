#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

//using std::vector;
using namespace std;

struct Segment {
  int start, end;
};


bool comp(Segment a, Segment b){
	if(a.end == b.end){
		return a.start < b.start;
	}
	return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  	sort(segments.begin(), segments.end(), comp);

  	vector<int> ans;
  	int tail = INT_MIN;
  	for(auto i = 0; i < segments.size(); ++i){
  		if(tail < segments[i].start){
  			tail = segments[i].end;
  			ans.push_back(tail);
  		}
	}
  	return ans;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  
  vector<int> points = optimal_points(segments);
  
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
