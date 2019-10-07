#include<iostream>
#include<time.h>
using namespace std;
int main(){
        srand48(time(0));
        int method =abs(mrand48() % 5);
        int length = abs(mrand49() % 40);
        cout << method << endl;
        cout << length << endl;
        for (int j = 0; j < length; j++) {
                cout << mrand48() % 3000 << endl;
        }
}
