#include <cpplib_queue.h>

int test_queue()
{
    cpplib::queue<int> q;

    printf("testing queues\n");

    q.push(3);
    q.push(2);
    q.push(1);
    q.push(5);
    q.push(6);
    q.push(7);

    while (q.empty() != true) {
        int val = q.front();

        printf("Val %d\n", val);
        q.pop();
    }

    q.clear();

    q.push(2);

    printf("val %d\n", q.front());

    return 0;
}

