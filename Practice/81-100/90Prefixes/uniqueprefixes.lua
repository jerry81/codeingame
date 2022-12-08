--[[

	Goal
Find the shortest unique prefixes for each word of the given list of words.

That should look familiar for those who handled switches for their command-line scripts or maintained their completion tables.

Example

You are given a list of six different words: alphabet, book, carpet, cadmium, cadeau, alpine.

In this list, you can see that:
* only one word starts with the letter b, so its shortest prefix will be b
* two words start with the letter a, but also both continue with lp so their respective shortest prefixes will be alph and alpi (h and i making the differentiation)
* three words start with the letter c, but also continue with some common letters, like a for all of them, and then d for only two of them, so their respective shortest prefixes will be car, cadm and cade

Notes

* The prefixes will not necessarily be of the same length.
* A word can be given several times in the given list. All the occurences of this word will share the same prefix.
* Each given different word must have a distinctive prefix from the prefixes of the other given words.
* A prefix cannot be used by two different words.
* If a word shares all its prefixes with the other different words, then, to avoid starvation, its prefix will be itself, and all its prefixes cannot be used by other words.
* You can read detailed definition of prefix in https://en.wikipedia.org/wiki/String_operations#Prefixes

Acknowledgements

Mohammad Sajid Anwar (aka manwar) who nicely accepted that one puzzle of one of the weekly challenges, from his website https://perlweeklychallenge.org, could be transcribed into one CodinGame contribution.
Input
First line: The number N of given words
Following N lines: A word W on each line
Output
N lines: The shortest prefix P on each line
Constraints
2 ≤ N ≤ 200
1 ≤ length(W) ≤ 20
Example
Input
5
find
the
shortest
unique
prefix
Output
f
t
s
u
p

]]

-- build a crazy giant map
giantmap={}
N = tonumber(io.read())
words={}
function processword(word)
  cur = giantmap
  for i=1,#word do
    ch = string.sub(word,i,i)
    --  io.stderr:write("ch is "..ch.."\n")
    if not cur[ch] then cur[ch] = {["_LENGTH"]=0} end
    cur = cur[ch]
    cur["_LENGTH"]=cur["_LENGTH"]+1
  end
end

for i=0,N-1 do
    word = io.read()
    table.insert(words,word)
    processword(word)
end
prefixes = {}
function testgiantmap(map, accum)
  -- io.stderr:write("accum is "..accum.."\n")
  if not map then return end
  numItems = map["_LENGTH"] or 0
  -- if numItems == 1 then
  --   table.insert(prefixes, accum)
  --   return
  -- end
  -- io.stderr:write("map len is "..(tostring(map["_LENGTH"]) or "nil").."\n")
  for k,v in pairs(map) do
    if k == "_LENGTH" then goto continue end
    -- io.stderr:write("k is "..k.."\n")
    testgiantmap(v, accum..k)
    ::continue::
  end
end

testgiantmap(giantmap, "")
-- for i=1,#prefixes do
--   print(prefixes[i])
-- end

function findprefix(remainingSubstring, map, accum)
  if not map then
    print(accum)
    return
  end
  nextChar = string.sub(remainingSubstring, 1,1)
  rem = string.sub(remainingSubstring,2)
  num = map["_LENGTH"] or 0
  if num == 1 then
    print(accum)
    return
  end
  nmap = map[nextChar]
  naccum = accum..nextChar
  findprefix(rem, nmap, naccum)
end

for i=0,N-1 do
    w = words[i+1]
    -- print(w)
    -- Write an answer using print()
    -- To debug: io.stderr:write("Debug message\n")
    findprefix(w, giantmap, "")
end