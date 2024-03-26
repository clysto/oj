#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  string s;
  string key;
  while (getchar() != '\n')
    ;
  for (int i = 0; i < T; i++) {
    getline(cin, s);
    getline(cin, key);
    cout << "case #" << i << ":" << endl;
    char current_key_index = 0;
    string encoded_str(s.size(), ' ');
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == ' ') continue;
      encoded_str[j] = 'A' + ((s[j] - 'A') + (key[current_key_index] - 'A')) % 26;
      current_key_index = (current_key_index + 1) % key.size();
    }
    cout << encoded_str << endl;
  }
  return 0;
}