#include <iostream>
#include <cstdlib>
#include <string>

#define is_bit_set(x, i) ((x >> i) & 1)

using namespace std;

bool grid[500][500];
int boardX, boardY, insMin, insMax;

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

            if (x == boardX || y == boardY) return true;
            if (grid[y][x]) return false;
        }
    }
}

void solve()
{
    for (int i = insMin; i <= insMax; i++)
    {
        for (int j = 0; j <= (1 << i) - 1; j++)
        {
            if (is_valid_path(j, i))
            {
                printf("http://www.hacker.org/runaway/index.php?path=");
                for (int k = i - 1; k >= 0; k--) putchar(is_bit_set(j, k) ? 'R' : 'D');
                return;
            }
        }
    }
}

int main()
{
    string terrain;
    cin >> terrain;
    
    insMax = stoi(terrain.substr(terrain.find("&FVinsMax=") + 10, terrain.find("&FVinsMin=") - terrain.find("&FVinsMax=") - 10));
    insMin = stoi(terrain.substr(terrain.find("&FVinsMin=") + 10, terrain.find("&FVboardX=") - terrain.find("&FVinsMin=") - 10));
    boardX = stoi(terrain.substr(terrain.find("&FVboardX=") + 10, terrain.find("&FVboardY=") - terrain.find("&FVboardX=") - 10));
    boardY = stoi(terrain.substr(terrain.find("&FVboardY=") + 10, terrain.find("&FVlevel=") - terrain.find("&FVboardY=") - 10));
    
    for (int i = 0; i < boardX; i++)
    {
        for (int j = 0; j < boardY; j++)
        {
            grid[i][j] = terrain[i * boardX + j] == 'X';
        }
    }
    solve();
}
