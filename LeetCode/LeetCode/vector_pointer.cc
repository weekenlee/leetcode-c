#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{1,3,2,4,5};
    int *p = &v[2]; // not safe , will change value
    cout << *p <<endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    cout << *p <<endl;
    cout << endl;
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    cout << *p <<endl;
    cout << endl;
    return 0;
}
