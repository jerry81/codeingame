--[[

	Goal
You are going to write a program to predict whether a specific usage pattern of electrical appliances will cause the main fuse to blow.

You have three pieces of data.
1. There are n appliances in a room, each of them has an electrical current consumption value.
2. A usage pattern. You will click the power buttons of a list of appliances in a sequence, at most m clicks. Each click on a button will toggle the power status, which means when the power is OFF, a click will turn it ON. Clicking it again will turn it OFF.
3. The capacity of the main fuse c in amperes [A].

The fuse will be blown if the sum of the consumed current of turned-on devices at some point exceeds the capacity of the main fuse c.

At the beginning, all appliances are OFF.
Input
Line 1: Integers n m c, separated by a space
n is the number of devices, assume the devices have IDs from 1 to n
m is the number of button-clicking going to happen
c is the capacity of the main fuse in amperes [A]

Line 2: n integers, space separated, representing the electrical current consumption value of each appliance, listed from ID 1 to n

Line 3: m integers, space separated - a sequence of ID# you are going to click power buttons, that will toggle the device status in that exact sequence.
Output
If the fuse was blown during the operation sequence, output one line:
Fuse was blown.

If the fuse did not blow, find the maximal consumed power by turned-on devices that occurred during the sequence. Output two lines:
Fuse was not blown.
Maximal consumed current was ? A.

Follow examples of test cases for the expected format.
Constraints
n and m are below 100
c is below 10000
Example
Input
5 2 10
11 6 11 10 10
3 3
Output
Fuse was blown.

]]--

-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.
current_load = 0
next_token = string.gmatch(io.read(), "[^%s]+")
n = tonumber(next_token()) -- num of devices
m = tonumber(next_token()) -- toggle count
c = tonumber(next_token()) -- capacity

function overload()
    return current_load > c
end

function pblown()
    print("Fuse was blown.")
end

function p(maxpower)
  print("Fuse was not blown.")
  print("Maximal consumed current was "..maxpower.." A.")
end

next_token = string.gmatch(io.read(), "[^%s]+")
dpower = {}
dstatus = {}
for i=0,n-1 do
    nx = tonumber(next_token())
    table.insert(dpower,nx)
    table.insert(dstatus,false)
end
next_token = string.gmatch(io.read(), "[^%s]+")
maxpow = 0
for i=0,m-1 do
    mx = tonumber(next_token())
    newstatus = not dstatus[mx]
    dstatus[mx] = newstatus
    if newstatus then
        current_load = current_load + dpower[mx]
        if overload() then
            pblown()
            return
        end
        if current_load > maxpow then
            maxpow = current_load
        end
    else
        current_load = current_load - dpower[mx]
    end
end

p(maxpow)
