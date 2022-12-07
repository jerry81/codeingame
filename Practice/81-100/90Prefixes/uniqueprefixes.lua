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

-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.

N = tonumber(io.read())
for i=0,N-1 do
    word = io.read()
end
for i=0,N-1 do

    -- Write an answer using print()
    -- To debug: io.stderr:write("Debug message\n")

    print("<word_prefix>")
end