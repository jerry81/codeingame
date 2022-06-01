import sys 
obj = []
a, b = [int(i) for i in input().split()]
for i in range(a):
    object_line = input()
    obj.append(object_line)
print(f"object is {obj}", file=sys.stderr, flush=True)
grid = []
c, d = [int(i) for i in input().split()]
for i in range(c):
    grid_line = input()
    grid.append(grid_line)

# for each subblock, try to transpose the object onto it
for i in range(c-a):
    grid_line = grid[i:i+a]
    for j in range(d-b):
        sub_grid = grid[j:j+b]
        print(f"sub is {sub_grid}", file=sys.stderr, flush=True)
        
print(f"grid is {grid}", file=sys.stderr, flush=True)

print("answer")
