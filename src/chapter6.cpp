#include "chapter6.h"

namespace chapter6
{
    void hello_world()
    {
        std::cout << "Hello World 6\n";
    }

    int iterative_array_sum(const int a[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        return sum;

    };

    int recursive_array_sum(const int a[], int n)
    {
        if (n == 0) return 0;
        else return (recursive_array_sum(a, n-1) + a[n-1]);
    };

    int gauss_array_sum(const int a[], int n)
    {
        return n*(n+1)/2;
    };

}