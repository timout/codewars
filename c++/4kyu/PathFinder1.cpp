#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

// TODO: Determine whether one can reach the exit at (n - 1, n - 1)
// starting from (0, 0) in a n × n maze (represented as a string)
// and return a boolean value accordingly
//You are at position [0, 0] in maze NxN and you can only move in one of the four cardinal directions
// (i.e. North, East, South, West). Return true if you can reach position [N-1, N-1] or false otherwise.
// Empty positions are marked .. Walls are marked W. Start and exit positions are empty in all test cases.

struct Pos {
    const int x;
    const int y;
    Pos(int x, int y) : x(x), y(y) {}
};

bool path_finder(string maze) {
    if ( maze.empty() ) return false;
    int ssize = maze.size();
    int msize = ( ssize == 1 ) ? 1 : sqrt(ssize);
    vector<vector<int>> field(msize, vector<int>(msize));
    //cout << "maze size: " << ssize << ":" << msize << endl;
    int i = 0;
    int j = 0;
    for ( char a : maze ) {
        if ( a == '\n' ) {
            i += 1;
            j = 0;
        } else {
            if ( a == 'W' ) field[i][j] = -1;
            j += 1;
        }
    }
    if ( field[0][0] < 0 ) return false;
    list<Pos> q;
    q.push_back(Pos(0,0));
    while ( q.size() > 0 ) {
        const Pos cur = q.front();
        if ( field[cur.y][cur.x] == 0 ) {
            //cout << "  cur " << ssize << ":" << msize << endl;
            field[cur.y][cur.x] = 1;
            if ( cur.y-1 >= 0 && field[cur.y-1][cur.x] == 0 ) q.push_back(Pos(cur.x, cur.y-1));
            if ( cur.x-1 >= 0 && field[cur.y][cur.x-1] == 0 ) q.push_back(Pos(cur.x-1, cur.y));
            if ( cur.y+1 < msize && field[cur.y+1][cur.x] == 0 ) q.push_back(Pos(cur.x, cur.y+1));
            if ( cur.x+1 < msize && field[cur.y][cur.x+1] == 0 ) q.push_back(Pos(cur.x+1, cur.y));
        }
        q.pop_front();
    }  
    return field[msize-1][msize-1] > 0;
}

int main()
{
    cout << path_finder(".W.\n.W.\n...") << endl;
    cout << path_finder(".W.\n.W.\nW..") << endl;
    cout << path_finder("......\n......\n......\n......\n......\n......") << endl;
    cout << path_finder("......\n......\n......\n......\n.....W\n....W.") << endl;
}