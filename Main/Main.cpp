#include <iostream>
#include "TStackList.h"
#include "TQueueList.h"

int main()
{
    TStackList<int> s;
    TQueueList<int> q;    

    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    s.pop();
    cout << s << endl;

    for (int i = 0; i < 5; ++i) {
        q.push(i);
    }
    q.pop();
    q.push(6);
    cout << q << endl;

    return 0;
}