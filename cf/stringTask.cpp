
#include <iostream>
#include <string>
#include <cctype>
#include <set>
typedef long long ll;

using namespace std;

int main() {
  set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'Y',
    'A', 'E', 'I', 'O', 'U'};
  string s = "", result = "";
  cin >> s;
  int len = s.size();

  for (int i = 0; i < len; ++i) {
    if(!vowels.count(s[i])) {
      result += ".";
      result += (char)tolower(s[i]);
    }
  } 

  cout << result;

  return 0;
}
