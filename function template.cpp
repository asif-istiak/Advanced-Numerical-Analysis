#include <iostream>
using namespace std;

template<typename T>

T getMax (T x, T y){
    return x>y? x:y;
}



int main() {
    int x=1000, y=100;
    cout <<  getMax<int>(x,y) << endl;

    char a1= 'w', a2='s';
    cout <<  static_cast<char>(getMax<char>(a1,a2)) << endl;
}