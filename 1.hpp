#ifndef HPP_1
#define HPP_1
template<class T>
T gcd(T a,T b)
{
    return b ? a : gcd(b, a % b);
}
template <class T>
inline T max(T a,T b)
{
    return a > b ? a : b;
}
#endif