#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Function>
void iter(T *array, size_t length, Function func)
{
    size_t  i;

    i = 0;
    while (i < length)
    {
        func(array[i]);
        i++;
    }
}

#endif