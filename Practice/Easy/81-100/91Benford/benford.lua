--[[
Goal
In this puzzle that shows a real-life phenomenon, you have to detect whether a bank account have a high risk to contain fraudulent transactions.

The Benford law is used on real anti-fraud systems to detect frauds about government accounting fraud, fiscal fraud, or even election cheating.

See the Wikipedia page about the Benford law: https://en.wikipedia.org/wiki/Benford%27s_law

Your program receives in input a list of transactions, like:
+1122.85 $
-10.69 $
-21.79 $
+12.08 $

You have to count how much transactions start with "1", "2", ...

For example:
"+1122.85 $" starts with 1
"-0.50" starts with 5
"$ 242.00" starts with 2

And you must output "true" if the bank account seems fraudulent, or "false" if it seems regular.

For this puzzle, your program will naively output whether a bank account seems fraudulent or not. You will be given the Benford law percentages:
1: 30.1%
2: 17.6%
3: 12.5%
4: 9.7%
5: 7.9%
6: 6.7%
7: 5.8%
8: 5.1%
9: 4.6%

An account is considered regular if the account starting numbers percentage follow these percentages, with a margin of 10 percent. Which means that you may find:

transactions starting with 1: 30.1%, so between 20.1% and 40.1%
transactions starting with 2: 17.6%, so between 7.6% and 27.6%
...

If at least one of these percentage is outside the expected range, the account is considered as fraudulent, you must then output "true".

Note that transactions may be formatted like this:
-48.12$
- 5,00 €
+0.99
350.10
-25 €
$ 500.00
42 £

It can be any currency.
Input
Line 1: The number of transactions N.
Next N lines: The transaction. Can be formatted like "-48.12$", "- 5,00 €", "+0.99", "350.10", "-25 €", ...
Output
One line: "true" if the account seems fraudulent, "false" if it seems regular.
Constraints
0 < N ≤ 1000
Example
Input
1000
1808.13 €
-54.84 €
-123.34 €
-2455.42 €
etc...
Output
false
]]--

benford = {
  30.1,
  17.6,
  12.5,
  9.7,
  7.9,
  6.7,
  5.8,
  5.1,
  4.6
}

freq = {0,0,0,0,0,0,0,0,0}

function getFirstNumber(str)

  for i=1,#str do
    c = string.sub(str,i,i)
    num = tonumber(c)

    if num ~= nil and num~=0 then return num end
  end
end

N = tonumber(io.read())
for i=0,N-1 do
    transaction = io.read()
    n = getFirstNumber(transaction)
    freq[n] = freq[n]+1
end

function inThreshold(startingNumber, frequency)
  basethresh = benford[startingNumber]
  return frequency >= math.max(0,basethresh-10) and frequency <= math.min(100, basethresh+10)
end

for i,v in ipairs(freq) do
  f = v/N * 100
  if not inThreshold(i,f) then print("true") return end
end

print("false")