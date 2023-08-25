#ifndef ACWING_HEAPSORT_H
#define ACWING_HEAPSORT_H

/**  index = [1,2,3,....,size]
 * 1、插入一个数  heap[++size] = x; up(size);
 * 2、求集合中的最小值 heap[1]
 * 3、删除最小值 heap[1] = heap[size]; size--; down(1);
 * 4、删除任意一个元素 heap[k] = heap[size]; size--; down(k); up(k);
 * 5、修改任意一个元素 heap[k] = x; down(k); up(k);
 */
#include <iostream>
#include <algorithm>
using namespace std;

class HeapSort
{
private:
    static const int N = 100010;
    int n, m;
    int h[N], h_size;

public:
    void down(int u)
    {
        int t = u;
        if (2 * u <= h_size && h[2 * u] < h[t])
            t = 2 * u;
        if (2 * u + 1 <= h_size && h[2 * u + 1] < h[t])
            t = 2 * u + 1;
        if (u != t)
        {
            swap(h[u], h[t]);
            down(t);
        }
    }

    void up(int u)
    {
        int t = u;
        if (2 * u <= h_size && h[2 * u] > h[t])
            t = 2 * u;
        if (2 * u + 1 <= h_size && h[2 * u + 1] > h[t])
            t = 2 * u + 1;
        if (u != t)
        {
            swap(h[u], h[t]);
            up(t);
        }
    }

    int heapSortMain()
    {
        cin >> n >> m;
        h_size = n;
        for (int i = 1; i <= n; i++)
            cin >> h[i];

        for (int i = n / 2; i; i--)
            down(i);

        while (m--)
        {
            cout << h[1] << ' ';
            h[1] = h[h_size];
            h_size--;
            down(1);
        }
        return 0;
    }
};

#endif