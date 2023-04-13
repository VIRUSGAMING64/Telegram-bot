#include <iostream>
template <typename __x>
void debug(__x arg)
{
    std::cout << arg << "\n";
}
template <typename __x, typename... Args>
void debug(__x arg, Args... args)
{
    std::cout << arg << " ";
    debug(args...);
}
