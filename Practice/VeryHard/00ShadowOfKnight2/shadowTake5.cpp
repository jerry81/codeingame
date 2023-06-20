#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();
    int py = y0;
    int px = x0;
    int cy = y0;
    int cx = x0;
    int ymax = h-1;
    int ymin = 0;
    int xmax = w-1;
    int xmin = 0;
    // game loop
    while (1) {
        bool yfound = ymin == ymax;
        bool xfound = xmin == xmax;
        if (xfound && yfound) {
            cout << xmin << " " << xmax << endl;;
        }
        
        string bomb_dir; // Current distance to the bomb compared to previous distance (COLDER, WARMER, SAME or UNKNOWN)
        cin >> bomb_dir; cin.ignore();
        // find y 
        if (bomb_dir == "UNKNOWN") {
          int ny = ymax - cy;
          cy = ny;
          cout << cx << " " << cy << endl;
          continue;
        } 

       

        int ymid = (py + cy) / 2;
        

 cerr << "max " << ymax << " min " << ymin << " mid " << ymid << endl;

        if (bomb_dir == "WARMER") {
          if (py < cy) { // take buttom
            ymin = ymid;
            if ((py+cy)%2 == 1) ymin++;
          } else { // take top
            ymax = ymid;
          } 
        }

        if (bomb_dir == "COLDER") {
          cerr << "colder case previous " << py << " now " << cy << endl;
          if (py < cy) {
            ymax = ymid;
          } else {
            cerr << "moved up got colder, take bottom half" << endl; // take bottom
            ymin = ymid;
            if ((py+cy)%2 == 1) ymin++;
          } 
        }

        if (bomb_dir == "SAME") {
          ymax = ymid;
          ymin = ymid;
        }

        int ny = (ymin+ymax)/2;
        if ((ymin+ymax) %2 == 1) ny++;
        py = cy;
        cy = ny;
        cout << cx << " " << cy << endl;
    }
}