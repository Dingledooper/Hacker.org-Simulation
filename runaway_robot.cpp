#include <iostream>
#include <cstdlib>
#include <string>

#define is_bit_set(x, i) ((x >> i) & 1)

using namespace std;

const int SZ = 16, LEFT = 6, RIGHT = 9;
bool grid[SZ][SZ] = 
{
    {0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,0},
    {0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0},
    {1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0},
    {0,0,0,0,0,0,0,1,0,1,0,1,1,0,1,0},
    {0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,1,0,1,1,0,0,0},
    {0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

bool is_valid_path(int n, int len)
{
    string rule = "";
    for (int i = len - 1; i >= 0; i--) rule += is_bit_set(n, i) ? "R" : "D";

    int x = 0, y = 0;
    while (true)
    {
        for (char c : rule)
        {
            if (c == 'R') ++x;
            else          ++y;

            if (x == SZ - 1 || y == SZ - 1) return true;
            if (grid[y][x]) return false;
        }
    }
}

void solve()
{
    for (int i = LEFT; i <= RIGHT; i++)
    {
        for (int j = 0; j <= (1 << i) - 1; j++)
        {
            if (is_valid_path(j, i))
            {
                for (int k = i - 1; k >= 0; k--) putchar(is_bit_set(j, k) ? 'R' : 'D');
                return;
            }
        }
    }
}

int main()
{
    solve();
}
