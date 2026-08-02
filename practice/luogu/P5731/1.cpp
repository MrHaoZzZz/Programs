#include <iostream>

using namespace std ;

int main()
{
    int n , map[10][10] = { 0 } , now = 1 , x = 1 , y = 0 ;
    cin >> n;
    
    while (now <= n * n)
    {
        while (y + 1 <= n && map[x][y + 1] == 0)
        {
            y++;
            map[x][y] = now;
            now++;
        }
        
        while (x + 1 <= n && map[x + 1][y] == 0)
        {
            x++;
            map[x][y] = now;
            now++;
        }
        
        while (y - 1 >= 1 && map[x][y - 1] == 0)
        {
            y--;
            map[x][y] = now;
            now++;
        }

        while (x - 1 >= 1 && map[x - 1][y] == 0)
        {
            x--;
            map[x][y] = now;
            now++;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%3d", map[i][j]);
        }
        cout << endl;
    }
    
    return 0 ;
}