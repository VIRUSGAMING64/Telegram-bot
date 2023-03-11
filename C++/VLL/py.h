
template <class T>
void print(T a)
{
    printf(a);
}
template <class T, class... res>
void print(T a, res... R)
{
    printf(a);
    print(R...);
}

