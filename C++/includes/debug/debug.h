#include <bits/stdc++.h>

template <class T>
inline std::ostream &operator<<(std::ostream &out, std::vector<T> v)
{
    for (auto c : v)
        out <<" "<< c << " ";
    return out;
}
template <class T>
inline std::ostream &operator<<(std::ostream &out, std::vector<std::vector<T>> v)
{
    for(int i = 0; i < v.size(); i++){
        out << i<< ": " << v[i] << "\n";
    }
    return out;
}

template <class arg1, class arg2>
inline std::ostream &operator<<(std::ostream &out, std::map<arg1, arg2> mp)
{
    for (auto c : mp)
        out << c.first << " " << c.second << "\n";
    return out;
}
template <class arg1,class arg2>
inline std::ostream &operator<<(std::ostream &out, std::pair<arg1,arg2> p)
{
    out << p.first << " " << p.second;
    return out;
}

template <typename __x>
void debug(__x arg)
{
    std::cerr << arg << "\n";
}
template <typename __x, typename... Args>
void debug(__x arg, Args... args)
{
    std::cerr << arg << " ";
    debug(args...);
}