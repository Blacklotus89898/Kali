#include <iostream>
#include <string>
#include <vector>


using namespace std ;

int main() {
  int t = 0;
  cin >> t;

  vector<string> s;
  for( int i = 0; i < t; ++i) {

    for( int j = 0; j < 3; ++j) {
      string ss;
      cin >> ss;
      s[i].push_back(ss[0]);
    }
  }

  for (int i = 0; i < t; ++i) {
    cout << s[i] << endl;
  }


  return 0;
}
