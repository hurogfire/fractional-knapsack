#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using std::vector;
using namespace std;
bool cmp(const pair<int, int>  &p1, const pair<int, int> &p2)
{
    return p1.second > p2.second;
}


double get_optimal_value(int n,int capacity, vector<int> weights, vector<int> values) {


  map<int,double> valueIndex ;
  for(int i = 0; i<n;i++){
    double ratio = (double)values[i]/(double)weights[i];
    valueIndex[i] = ratio;
    //cout << valueIndex[i] << "\n";

  }

    vector<pair<int, double> > v;
    copy(valueIndex.begin(), valueIndex.end(), back_inserter(v));

    sort(v.begin(), v.end(), cmp);
    double value = 0.0;
    int cur_capacity = capacity;
    for(int i = 0; i < v.size(); i++){
        //cout << v[i].first << " : " << v[i].second << v.size()<< endl;
         if (i == (v.size()-1)){
            value  += (double)cur_capacity / (double)weights[v[i].first] * (double)values[v[i].first];
         }
         else{

        int count = cur_capacity / weights[v[i].first];
        value += (double)count * (double)values[v[i].first];
        cur_capacity = cur_capacity % weights[v[i].first];
         }

    }
  return value;
}

int main() {
  int n;
  int capacity;
  double test = 180.00000000;
  cout<< test;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n, capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
