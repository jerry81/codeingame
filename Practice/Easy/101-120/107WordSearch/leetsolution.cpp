#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;


int main()
{
    const vector<int> DX { 1, 1, 0, -1, -1, -1,  0,  1 };
    const vector<int> DY { 0, 1, 1,  1,  0, -1, -1, -1 };
    locale loc("C");
    int height, y, x, _y, _x, dx, dy, len, i, j;
    cin >> height; cin.ignore();
    vector<string> data(height);
    for (string& s : data) cin >> s;
    const int width = static_cast<int>(data.front().size());
    vector<string> out(height, string(width, ' '));
    string clue;
    bool found;

    while (cin >> clue)
    {
        found = false;
        len = static_cast<int>(clue.size());
        for (char& c : clue) c = toupper(c, loc);
        for (y = 0; y < height && !found; ++y) for (x = 0; x < width && !found; ++x) if (data[y][x] == clue.front())
        {
            found = false;
            for (i = 0; !found && i < 8; ++i)
            {
                dx = DX[i]; dy = DY[i]; _x = x + dx * len; _y = y + dy * len;
                if (_x >= -1 && _x <= width && _y >= -1 && _y <= height)
                {
                    found = true;
                    for (j = 0, _x = x, _y = y; found && j < len; ++j, _x += dx, _y += dy) found &= clue[j] == data[_y][_x];
                    if (found) for (j = 0, _x = x, _y = y; j < len; ++j, _x += dx, _y += dy) out[_y][_x] = data[_y][_x];
                }
            }
        }
    }

    for (const string& s : out) cout << s << "\n";
    return 0;
}