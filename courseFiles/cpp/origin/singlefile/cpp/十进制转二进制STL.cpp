#include <cstdio>
#include <bitset>
using namespace std;
unsigned a;
int main()
{
    scanf("%u",&a);
    bitset<8> b(a);
    printf("%s",b.to_string().c_str());
    return 0;
}