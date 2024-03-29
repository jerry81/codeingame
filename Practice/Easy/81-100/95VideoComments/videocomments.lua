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

function parseTime(time)
  local spl = split(time, ":")
  local hr = spl[1]
  local min = spl[2]
  return hr,min
end

PRIORITIES = { Followed = 2, Pinned = 3, none = 1 }

function compareComments(c2,c1)
  pcomp = PRIORITIES[c1.priority] - PRIORITIES[c2.priority]
  if pcomp ~= 0 then
    return pcomp < 0
  end

  lcomp = c1.likes - c2.likes
  if lcomp ~= 0 then
    return lcomp < 0
  end

  hcomp = tonumber(c1.hr) - tonumber(c2.hr)
  if hcomp ~= 0 then
    return hcomp < 0
  end

  mcomp = tonumber(c1.min) - tonumber(c2.min)
  if mcomp ~= 0 then
    return mcomp < 0
  end

  return c1.idx > c2.idx
end

Comment = {name = "", likes = 0, hr = 0, min = 0, idx = 0, replies = {}}

function Comment:new (name,time,likes,priority,idx)
   local lcomment = {}
   setmetatable(lcomment, self)
   self.__index = self
   hr,min = parseTime(time)
   lcomment.hr = hr or "00"
   lcomment.min = min or "00"
   lcomment.name = name or ""
   lcomment.likes = likes or 0
   lcomment.priority = priority or "none"
   lcomment.idx = idx
   lcomment.replies = {}
   return lcomment
end

function Comment:pr()
  print(self.name.."|"..self.hr..":"..self.min.."|"..self.likes.."|"..self.priority)
  for _,v in ipairs(self.replies) do
    v:pr()
  end
end

-- Derived class method printArea

function Comment:addReply (commReply)
   table.insert(self.replies, commReply)
end


allcomments = {}
function applyComment(commentstr, curcomment, idx)
  local spl = split(commentstr,"|")
  local newComment = Comment:new(spl[1], spl[2], spl[3], spl[4], idx)
  if string.sub(commentstr, 1,1) == " " then
    curcomment:addReply(newComment)
    return curcomment
  end
  table.insert(allcomments, newComment)
  return newComment
end

cur = {}
n = tonumber(io.read())
for i=0,n-1 do
    comment = io.read()
    cur = applyComment(comment, cur, i)
end

table.sort(allcomments, compareComments)

for k,c in ipairs(allcomments) do
   table.sort(c.replies, compareComments)
   c:pr()
end