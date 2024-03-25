#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <climits>

using namespace std;

int split_min_words(string str, unordered_set<string> words) {
  if (str.size() == 0) {
    return 0;
  }
  string prefix = "";
  int min_words = INT_MAX;
  for (int i = 0; i < str.size(); i++) {
    prefix += str[i];
    if (words.find(prefix) != words.end()) {
      min_words = min(min_words, 1 + split_min_words(str.substr(i + 1), words));
    }
  }
  return min_words;
}

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  string str;
  unordered_set<string> words;
  for (int i = 0; i < N; i++) {
    cin >> str;
    int words_n;
    cin >> words_n;
    for (int j = 0; j < words_n; j++) {
      string word;
      cin >> word;
      words.insert(word);
    }
    cout << split_min_words(str, words) << endl;
  }
  return 0;
}
