#include<iostream>
#include<time.h>
using namespace std;
int main(){
        srand48(time(0));
        int method =abs(mrand48() % 5);
        int length = abs(mrand48() % 40);
        int index = abs(mrand48() % length);
        cout << method << endl;
        cout << length << endl;
        cout << index << endl;
        for (int j = 0; j < length; j++) {
                cout << mrand48() % 3000 << endl;
        }
}
