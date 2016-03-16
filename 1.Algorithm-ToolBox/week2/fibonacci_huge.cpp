#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> p;

int get_periodic(long long m, vector<long long>& p){
	p.clear();
	p.push_back(0);
	p.push_back(1);
	
	bool flag = false;
	while(1){
		int i = p.size()-1;
		
		long long temp = ((p[i]%m) + (p[i-1]%m))% m;
		
		p.push_back(temp);
		
		if(!(p.size()&1) ){
			for(int i = 0; i<p.size()/2; ++i){
				if(p[i] != p[i+p.size()/2]){
					flag = false;
					break;
				}
				else{
					flag = true;
				}
			}
			if(flag){
				return p.size()/2;
			}
		}
	}
	
}



long long get_fibonaccihuge(long long n, long long m) {
  //write your code here
  	int peroid = get_periodic(m,p);
  	//cout << "peroid = " << peroid << endl;
	return p[n%peroid];
  
}

int main() {
    long long n, m;

    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';

}
