import sys 
obj = []
a, b = [int(i) for i in input().split()]
mark_indexes = []
for i in range(a):
    object_line = input()
    for idx,j in enumerate(list(object_line)):
        if j == "*":
            mark_indexes.append({"y": i, "x":idx})

print(f"object is {obj}", file=sys.stderr, flush=True)
print(f"mark_indexes is {mark_indexes}", file=sys.stderr, flush=True)
grid = []
c, d = [int(i) for i in input().split()]
for i in range(c):
    grid_line = input()
    grid.append(grid_line)

# for each subblock, try to transpose the object onto it
count = 0
for i in range(c-a):
    for j in range(d-b):
        fits = True
        for k in mark_indexes:
            dx = k["x"]
            dy = k["y"]
            if grid[i+dy][j+dx] != '.':
                fits = False
                break
        if fits:
            count += 1
        
print(f"grid is {grid}", file=sys.stderr, flush=True)

print(count)
