#include <bits/stdc++.h>
using namespace std;
class choices
{
public:
    // Data member
    int dx;
    int dy;
    char dir;
};
class Solution
{
public:
    bool is_valid(int x, int y, vector<vector<int>> &maze,
                  vector<vector<int>> &visited)
    {
        int n = maze.size();
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        if (maze[x][y] == 0 || visited[x][y] == 1)
            return false;
        return true;
    }

    void solve(vector<vector<int>> &maze,
               vector<string> &ans,
               string &path,
               int x, int y,
               vector<choices> &choice,
               vector<vector<int>> &visited)
    {

        int n = maze.size();
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        for (auto i : choice)
        {
            int nx = x + i.dx;
            int ny = y + i.dy;

            if (is_valid(nx, ny, maze, visited))
            {
                visited[nx][ny] = 1;
                path.push_back(i.dir);

                solve(maze, ans, path, nx, ny, choice, visited);

                path.pop_back();
                visited[nx][ny] = -1;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        vector<string> ans;
        int n = maze.size();
        if (maze[0][0] == 0)
            return ans;

        vector<vector<int>> visited(n, vector<int>(n, -1));
        string path = "";
        vector<choices> choice = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};

        visited[0][0] = 1;
        solve(maze, ans, path, 0, 0, choice, visited);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        // problem link -https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    }
}
