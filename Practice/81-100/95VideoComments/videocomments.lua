--[[
Goal
You are responsible for the making of a comments system for a newly made videos app. There is one problem, what's the point if comments are randomly shown? And here comes your job, you need to design a priority system for comments.

There are n comments given to you in random order. Each comment contains comment data (name, date, likes, priority) separated by a | character. You are not given the content for comments because it is unnecessary for the sorting process. And for simplicity, we are going to assume all comments are made in the same day, so you only have to look at the time in 24-hour format.

You need to sort the comments in a way such that:
- Pinned comment appears first, there is only one of such comment, and its priority is Pinned.
- Followed people's comments appear second, and their priority is Followed.
- Comments with most likes appear third, regardless of their date, they have priority none.
- Newer comments appear fourth, they have priority none.
- in a case of more than 1 followed accounts, they would be ordered by their likes and date as said.
- in case of a tie between two users, the one given in input first is outputted first, e.g. user1 is given before user2, so you output user1 then user2.

none priority means it is not a pinned nor followed comment.

Comments may contain replies, A reply starts with 4 spaces, and is under the comment it belongs to.

The replies of a comment are also sorted based on the above said priorities, there will not be a pinned reply.
Input
Line 1: An integer n for the amount of comments
Next n lines: A comment, split by a vertical bar (|): name, date, likes, priority
Output
The comments after being sorted
Constraints
2 ≤ n ≤ 13
There will not be nested replies, i.e. a reply to another reply
Names will only consist of user and a number, and are not necessarily in order
Example
Input
2
user1|05:00|0|none
user2|06:00|0|none
Output
user2|06:00|0|none
user1|05:00|0|none
]]--

--[[
comment:
  time:
  name:
  likes:
  replies: {...} -- comment objects
]]--

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

n = tonumber(io.read())
for i=0,n-1 do
    comment = io.read()
    spl = split(comment,"|")
    for k,v in pairs(spl) do
      io.stderr:write("k is "..k.." and v is "..v.."\n")
    end
end

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print("answer")