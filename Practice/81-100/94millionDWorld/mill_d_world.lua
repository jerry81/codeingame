--[[

Goal
You are in 1000000000D World!
In 1000000000D World all vectors consist of exactly one billion integers.

People of 1000000000D World are quite smart and they know that due to low entropy and "curse of dimensionality" most of their billion-dimensional vectors have a lot of consequent repetitions. So they always store their vectors in a compressed form.

For example consider a vector in canonical form:

[1 1 1 2 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 ... (999999995 times 3)]

In compressed form it will become just:

[3 1 2 2 999999995 3]    (which stands for 3 times 1 and 2 times 2 and 999999995 times 3)


Given two 1000000000D vectors A and B in compressed form.
Find a dot product of two vectors

Dot product definition:
For two vectors a = [a_1 a_2 ... a_n] and b = [b_1 b_2 ... b_n] dot product "a • b" = a_1 * b_1 + a_2 * b_2 + ... + a_n * b_n
Input
Line 1 Compressed Vector A
Line 2 Compressed Vector B
Output
Dot product of A and B
Constraints
The absolute values of the final result and all intermediate results are less than 2^40
Example
Input
500000001 1 499999999 -1
1000000000 1
Output
2

]]--

-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.

a = io.read()
b = io.read()
function split (inputstr, sep)
  if sep == nil then
     sep = "%s"
  end
  local t={}
  for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
     table.insert(t, str)
  end
  return t
end

function parse(str)
  return split(str, " ")
end
aa = parse(a)
bb = parse(b)

function dot(a,b)
  local ea = #a / 2
  local eb = #b / 2

  local ptr1 = 1
  local ptr2 = 1
  local sum = 0
  while ptr1 <= ea and ptr2 <= eb do
    acount = tonumber(a[ptr1*2-1])
    avalue = tonumber(a[ptr1*2])
    bcount = tonumber(b[ptr2*2-1])
    bvalue = tonumber(b[ptr2*2])
    multiplier = acount
    difference = bcount - acount
    if acount > bcount then
      multiplier = bcount
      difference = acount - bcount
      a[ptr1*2-1] = difference
      ptr2=ptr2+1

    elseif acount == bcount then
        ptr1 = ptr1+1
        ptr2 = ptr2+1
    else
      ptr1=ptr1+1
      b[ptr2*2-1] = difference
    end
    sum = sum + ((avalue * bvalue) * multiplier)
  end
  return sum
end

sum = dot(aa,bb)

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print(sum)