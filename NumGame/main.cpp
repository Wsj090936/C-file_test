#include <iostream>
#include"Type.h"
using namespace std;

int main()
{
    int times;
    srand(time(NULL));
    cout << "Input times:" << endl;
    cin>>times;
    t = times;
    Sleep(1000);
    Run game;
    game.init();
    game.import();
    game.run(times);
    return 0;
}
