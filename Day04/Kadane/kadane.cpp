#include <cstdio>
#include <algorithm>
#define size 1000010
using namespace std;
int n, sum, a[size], af[size], ab[size], mf[size], mb[size];
int getmin(int *arr, int l)
{
    mf[1] = arr[1];
    for (int i = 2; i <= l; i++)
        mf[i] = min(mf[i - 1] + arr[i], min(arr[i], 0)); // 可以为0
    for (int i = 2; i <= l; i++)
        mf[i] = min(mf[i - 1], mf[i]);
    mb[l] = arr[l];
    for (int i = l - 1; i > 0; i--)
        mb[i] = min(mb[i + 1] + arr[i], min(arr[i], 0)); // 可以为0
    for (int i = l - 1; i > 0; i--)
        mb[i] = min(mb[i + 1], mb[i]);
    int ans = (1ll << 31ll) - 1ll; // 2^31-1，即 int 的最大值
    for (int i = 2; i < l; i++)
        ans = min(ans, mf[i - 1] + mb[i + 1]); // 这里必须被分开
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        sum += a[i];
    }
    af[1] = a[1];
    for (int i = 2; i <= n; i++)
        af[i] = max(af[i - 1], 0) + a[i];
    for (int i = 2; i <= n; i++)
        af[i] = max(af[i - 1], af[i]);
    ab[n] = a[n];
    for (int i = n - 1; i > 0; i--)
        ab[i] = max(ab[i + 1], 0) + a[i];
    for (int i = n - 1; i > 0; i--)
        ab[i] = max(ab[i + 1], ab[i]);
    int ans = 1ll << 31ll; // 溢出为负数
    for (int i = 1; i < n; i++)
        ans = max(ans, af[i] + ab[i + 1]); // 可以不被分开
    ans = max(ans, sum - getmin(a, n - 1));
    ans = max(ans, sum - getmin(a + 1, n - 1));
    printf("%d\n", ans);
    return 0;
}