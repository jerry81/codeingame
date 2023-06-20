# trilateration

- using distances from 3 known points to a point to calculate point's location.

- doesn't help us greatly because distances are not known.

# idea

- if a jump to b gives warmer
- we can eliminate points closer to a than to b
- to flesh out: what are points closer to a than to b?
- brute force: we can plug in each possible point into the distance equation
- how do we eliminate the most amount of points at each step?

# big hint given in example

- blue squares are the possible squares
- white squares are eliminated

# picking the best square

- get average x of all unvisited squares
- get avg y of all unvisited squares
- mid x = (curx + tgtx) / 2
- tgtx = midx \* 2 - curx

# optimizing

- initial avg calc unnecessary - done
- only store remaining possibilities - doesn't help the biggest loops
- cut only one axis per turn - makes calculations much easier
- you find midpoint and then you have 2 rectangles
- instead of updating item by item you update the bounds
- with 2 axis jumps, you can also update the bounded polygon and only need to store points of edges
  - revisit this with point-in-polygon algorithm

```
To determine if a point is inside a polygon, you can use the "point-in-polygon" algorithm. Here's a general approach you can follow:

Input the polygon with its vertices and the point you want to test.

Determine the number of sides, n, in the polygon.

Create a line segment from the given point to a point located outside the polygon, such as a point with coordinates (-infinity, y) or (max_x + 1, y), where max_x is the maximum x-coordinate of any vertex in the polygon. This line segment will be used for intersection tests.

Initialize a count variable to 0.

Iterate through each side of the polygon:

a. Get the current side's vertices.

b. Check if the line segment intersects the current side. You can use a line segment intersection algorithm for this check.

c. If the line segment intersects the side, increment the count variable.

After checking all the sides, if the count variable is odd, the point is inside the polygon. Otherwise, it's outside the polygon.

Note: If the polygon has overlapping sides or self-intersections, the algorithm may not work correctly. In such cases, you may need to preprocess or handle the polygon differently.

There are several algorithms available for line segment intersection tests and point-in-polygon checks, such as the ray casting algorithm or the winding number algorithm. You can choose an algorithm based on your requirements and the programming language you're using.
```

- and centroid of polygon algorithm

```
To find the centroid of a polygon, you can use the following steps:

Input the polygon with its vertices.

Determine the number of sides, n, in the polygon.

Initialize variables for the centroid's x-coordinate (Cx) and y-coordinate (Cy) to 0.

Iterate through each side of the polygon:

a. Get the current side's vertices.

b. Calculate the cross product of the current vertex and the next vertex:

cross_product = (x[i] * y[i+1]) - (x[i+1] * y[i])

c. Update the centroid variables:

Cx += (x[i] + x[i+1]) * cross_product
Cy += (y[i] + y[i+1]) * cross_product

After iterating through all the sides, divide the centroid variables by 6 times the signed area of the polygon to get the centroid coordinates:

Cx /= (6 * polygon_area)
Cy /= (6 * polygon_area)

Note: The signed area of the polygon can be calculated using the shoelace formula or any other method suitable for your programming language.

The resulting Cx and Cy values represent the coordinates of the centroid of the polygon.

Please note that this method assumes the polygon is not self-intersecting and has a non-zero area.
```

# first bsearch attempt ended up as flaming ball of shit

- choose an axis and zero in
```
.          same

      t

.

.          warmer


      t
.


.        colder

      t


.

there is a flaw:  midpoint between 5 and 10 is 7.5, not 7...
- we cannot just discount the row/col at mid because it could have gone to both points of reference are equidistant from that row/col.

5

6

7.5  - new range colder - 5 to 7 warmer 8 to 10 so if odd add the modifier
  - same is impossible here

8

9

10


6

7

8          6 to 8 8 to 10  same case is 16/2 = 8

9

10


```

- so the new algorithm works and doesn't time out but isn't eliminating enough squares quickly enough.
- new idea
- shrink the "box" down to a manageable threshold, X*Y
- then use the thorough distance algorithm that worked originally
- there is an awkward moment when transitioning from y to x or vice versa when y or x is not determined yet
- in this case, if the last jump was colder you are jumping out of the min/max for the dimension you left
  - that is ok as long as you are in bounds
- there is another similar jump when you are done shrinking the remaining dimension and transitioning to the diagnoal jump algorithm
- at this point, we initialize a map of possibilities (bounding box) and start jumping diagonally

- extract both algorithms into managable functions