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

    int recursive_array_sum_positive(const int a[], int n)
    {
        if (n == 0) return 0;
        else if (a[n-1] < 0) return recursive_array_sum_positive(a, n-1);
        else return (recursive_array_sum_positive(a, n-1) + a[n-1]);
    };

    bool parity_is_odd_iterative(const bool b[], unsigned int n)
    {
        bool odd = false;
        for (int i = 0; i < n; i++)
        {
            if (b[i])
            {
                if (not odd) odd = true;
                else odd = false;
            }
        }
        return odd;
    };

    bool parity_is_odd_recursive(const bool b[], unsigned int n)
    {
        if (n == 1) return b[n-1];
        const bool parity = parity_is_odd_recursive(b, n-1);
        if (b[n-1])
        {
            if (parity) return false;
            return true;
        };
        return parity;

    };

    int count_integer_iterative(const int integers[], int length, int target)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (integers[i] == target) count++;
        }
        return count;
    };

    int count_integer_recursive(const int integers[], int length, int target)
    {
        if (length == 0) return 0;
        int count = 0;
        if (integers[length-1] == target) count = 1;
        return count + count_integer_iterative(integers, length-1, target);
    };

}