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
291.16 €
14.29 €
57.82 €
892.97 €
229.93 €
-8.78 €
5034.10 €
-56.35 €
-1876.12 €
-0.61 €
-14.24 €
8.50 €
571.58 €
1036.00 €
854.65 €
-82.98 €
288.58 €
-6.50 €
-36.09 €
-41.41 €
-45.71 €
-19.22 €
-9.76 €
0.30 €
-844.25 €
163.42 €
0.67 €
-121.43 €
13.06 €
282.67 €
1175.42 €
2103.37 €
2.07 €
161.96 €
-249.24 €
2.18 €
-2006.31 €
-3639.75 €
-35.12 €
-34.67 €
45.16 €
-7.39 €
-25.35 €
-128.56 €
24.69 €
-327.30 €
-256.43 €
16.74 €
-27.12 €
17.41 €
-3.10 €
-34.43 €
2127.38 €
9.17 €
14.53 €
67.79 €
4.96 €
482.01 €
-45.86 €
680.30 €
-4.84 €
166.66 €
-3.58 €
0.84 €
284.17 €
231.61 €
-5.05 €
-119.01 €
-5.18 €
-3.21 €
-15.67 €
155.57 €
-37.67 €
116.71 €
25.63 €
-17.24 €
-66.30 €
-5.43 €
-27.06 €
-26.75 €
-87.23 €
-50.62 €
519.04 €
-1.31 €
-15.62 €
11.18 €
170.76 €
3318.20 €
-179.71 €
1302.45 €
0.21 €
323.19 €
-57.37 €
2.47 €
327.85 €
1.09 €
-100.25 €
121.28 €
131.45 €
-0.14 €
-795.08 €
336.13 €
-5.78 €
-28.73 €
-23.78 €
0.34 €
0.99 €
-7.29 €
-23.21 €
-308.76 €
0.76 €
-195.52 €
19.39 €
-55.17 €
6.90 €
29.22 €
-227.66 €
1.47 €
-17.94 €
0.14 €
-467.35 €
-796.61 €
-69.93 €
7.91 €
-3.28 €
11.52 €
0.51 €
1273.92 €
79.01 €
-5.73 €
1.07 €
207.85 €
62.71 €
-3180.01 €
-46.97 €
9.15 €
-827.95 €
-28.88 €
-58.60 €
-63.22 €
2.85 €
5259.60 €
-4.03 €
2610.42 €
-1816.81 €
1.00 €
-1.16 €
671.43 €
-5.53 €
-102.23 €
-21.96 €
7.00 €
164.42 €
-16.34 €
-1276.85 €
-2.58 €
1114.43 €
0.61 €
5.03 €
-266.52 €
-814.93 €
38.95 €
19.90 €
214.44 €
150.01 €
78.18 €
-573.79 €
1.43 €
71.98 €
4.35 €
-267.04 €
-136.43 €
952.80 €
-1167.48 €
9.35 €
-475.18 €
1.71 €
-270.14 €
5.73 €
2.37 €
-12.68 €
57.36 €
347.10 €
108.82 €
42.49 €
5.91 €
312.05 €
-46.81 €
-9.82 €
-247.66 €
-261.80 €
3587.66 €
-58.85 €
1.03 €
-6.08 €
84.81 €
-25.26 €
-34.49 €
-203.87 €
-6.23 €
0.81 €
-42.20 €
-164.10 €
-1142.11 €
-963.36 €
430.95 €
1.23 €
1022.04 €
-9.86 €
7.47 €
-664.35 €
2452.51 €
11.13 €
-130.04 €
-91.15 €
14.29 €
-30.55 €
-12.13 €
1717.72 €
0.94 €
-611.43 €
78.09 €
48.47 €
-3.46 €
355.08 €
312.88 €
0.26 €
-14.34 €
-380.76 €
78.28 €
-8.02 €
1569.26 €
5.85 €
-1.20 €
2727.81 €
-3.70 €
-42.26 €
368.12 €
8.58 €
-2290.21 €
-1.29 €
-2720.38 €
-5.77 €
-521.46 €
128.22 €
-107.30 €
-5.39 €
13.80 €
-105.88 €
5.48 €
248.13 €
-3914.41 €
-129.90 €
62.55 €
1579.30 €
-74.28 €
114.50 €
0.68 €
-170.22 €
1419.46 €
15.05 €
-3146.15 €
92.50 €
-7.58 €
14.53 €
-4409.47 €
-1482.47 €
34.06 €
-92.25 €
-108.03 €
84.09 €
-2195.36 €
142.28 €
20.29 €
-21.86 €
58.45 €
855.23 €
99.69 €
-5.04 €
-86.26 €
350.80 €
0.25 €
22.80 €
-223.84 €
25.38 €
-3.77 €
-12.79 €
70.11 €
-261.89 €
330.03 €
56.23 €
23.94 €
-295.41 €
-4.27 €
16.32 €
-11.11 €
15.28 €
80.26 €
-4386.62 €
241.13 €
-27.49 €
3.41 €
1237.60 €
-0.70 €
271.64 €
78.13 €
361.40 €
70.54 €
76.60 €
-11.82 €
-1.98 €
8.20 €
-9.77 €
269.39 €
190.93 €
-1.40 €
-247.07 €
154.68 €
-864.38 €
-1537.84 €
31.13 €
-23.47 €
-28.56 €
-5556.28 €
-8.11 €
-72.70 €
-0.54 €
3.82 €
13.70 €
28.13 €
12.08 €
0.45 €
42.54 €
951.28 €
64.41 €
1623.34 €
-194.44 €
-1079.70 €
-10.38 €
16.48 €
26.44 €
294.69 €
-6.64 €
-26.96 €
1.08 €
677.92 €
7.57 €
1661.78 €
215.61 €
8.16 €
139.91 €
0.54 €
-1809.90 €
6.37 €
43.75 €
171.60 €
3932.52 €
-4.08 €
1158.66 €
-6.98 €
2668.96 €
27.13 €
-75.39 €
4.05 €
1640.05 €
-27.18 €
0.69 €
3856.95 €
22.17 €
411.90 €
2274.61 €
41.37 €
8.80 €
80.49 €
39.26 €
3.00 €
2.07 €
-403.89 €
15.63 €
-18.53 €
148.12 €
456.87 €
8.36 €
4.51 €
73.14 €
-747.95 €
200.73 €
656.81 €
-2.77 €
40.86 €
6.48 €
-660.70 €
-46.31 €
10.51 €
-67.30 €
-30.97 €
1608.65 €
-45.58 €
22.66 €
-1040.14 €
2.24 €
7084.39 €
10.64 €
-3809.63 €
-7.41 €
-56.38 €
-941.35 €
2477.50 €
-153.48 €
-99.72 €
-0.01 €
640.81 €
53.77 €
184.19 €
-148.95 €
-1.65 €
7.62 €
114.18 €
-559.86 €
3451.30 €
-2.16 €
-84.96 €
5612.52 €
184.73 €
1079.94 €
-25.25 €
-3213.08 €
-174.97 €
19.95 €
-326.95 €
0.66 €
30.29 €
16.52 €
-428.81 €
222.44 €
422.46 €
-5.78 €
337.29 €
-143.89 €
-135.71 €
59.44 €
-19.35 €
-4.48 €
4732.11 €
34.54 €
-302.17 €
9.85 €
-524.06 €
95.19 €
232.77 €
86.58 €
42.76 €
77.79 €
-14.26 €
-36.30 €
-3054.99 €
-30.02 €
-6.13 €
100.77 €
-15.76 €
-44.71 €
2.97 €
-131.64 €
-1.47 €
150.26 €
-0.07 €
14.18 €
1772.02 €
6.39 €
169.37 €
51.33 €
1960.90 €
8.16 €
-40.55 €
14.54 €
3.51 €
103.33 €
0.54 €
-54.41 €
-113.39 €
-23.31 €
3201.98 €
126.36 €
-8.94 €
-89.27 €
-66.54 €
-3820.87 €
5.41 €
61.66 €
-838.68 €
-7173.88 €
-176.80 €
756.36 €
-513.18 €
8.05 €
249.85 €
5.57 €
-94.99 €
874.66 €
6.09 €
70.17 €
-7.78 €
21.51 €
1.57 €
36.81 €
-4398.23 €
-0.01 €
-5266.53 €
-146.59 €
19.46 €
14.41 €
81.36 €
14.09 €
53.86 €
272.22 €
-27.75 €
932.52 €
0.08 €
-0.64 €
-23.23 €
-34.99 €
37.49 €
84.08 €
-2113.38 €
-1.79 €
-435.09 €
-8.02 €
0.49 €
-45.39 €
2022.53 €
1694.70 €
-58.46 €
225.83 €
-479.98 €
-1142.31 €
-10.68 €
-1914.47 €
-5820.09 €
26.23 €
-735.83 €
5927.91 €
210.55 €
-3010.30 €
284.00 €
-17.33 €
-2.51 €
12.40 €
-2718.20 €
-8.27 €
-1742.09 €
24.90 €
-316.81 €
0.84 €
1.57 €
-172.84 €
-18.70 €
44.47 €
4.12 €
2.94 €
-51.08 €
24.09 €
2837.62 €
30.79 €
-1.03 €
-3.90 €
1.95 €
-772.44 €
0.42 €
-1655.97 €
135.55 €
131.74 €
81.81 €
-57.09 €
19.51 €
-295.37 €
18.87 €
-3084.44 €
14.78 €
37.54 €
-334.53 €
1004.23 €
2439.70 €
3406.62 €
6.22 €
6.34 €
-5.93 €
-855.79 €
127.32 €
63.33 €
-1.02 €
-5.59 €
10.54 €
303.02 €
-33.96 €
-50.36 €
-4.84 €
8.87 €
403.14 €
-338.54 €
3074.96 €
552.32 €
65.18 €
4.15 €
958.08 €
388.04 €
-5.25 €
13.28 €
-1774.61 €
-920.05 €
-9.86 €
11.56 €
53.84 €
0.07 €
-119.14 €
-0.21 €
7188.49 €
1859.66 €
488.78 €
5358.34 €
165.10 €
558.75 €
-6422.83 €
-40.39 €
1102.23 €
-535.75 €
-30.28 €
-153.88 €
-390.86 €
76.35 €
4.49 €
-3.52 €
29.74 €
-5.84 €
-263.23 €
546.69 €
28.25 €
-765.89 €
606.73 €
-14.39 €
-3.20 €
341.84 €
-546.27 €
105.58 €
630.06 €
-287.82 €
-661.14 €
266.63 €
60.57 €
-2.24 €
1015.27 €
-1.65 €
7.50 €
421.54 €
-36.97 €
-93.66 €
-5.90 €
98.20 €
146.33 €
-179.24 €
-203.68 €
196.38 €
26.78 €
379.18 €
1703.90 €
104.48 €
-7.28 €
15.59 €
30.11 €
7.31 €
-1815.90 €
-4916.38 €
-5.71 €
1.64 €
6.46 €
-1231.98 €
62.42 €
5991.44 €
8.88 €
10.86 €
237.26 €
-8.06 €
-1610.05 €
-2.17 €
-216.95 €
-155.87 €
95.99 €
-68.15 €
-710.26 €
4032.21 €
238.66 €
-6.56 €
5435.96 €
-2580.52 €
-481.60 €
-41.78 €
1774.35 €
76.66 €
-3.56 €
-705.50 €
-1568.47 €
9.37 €
2.12 €
7.50 €
18.36 €
63.70 €
-70.84 €
-149.72 €
-257.72 €
330.28 €
-5.18 €
-572.05 €
-102.97 €
-15.15 €
1067.69 €
-1.52 €
8.60 €
1331.21 €
-25.26 €
506.89 €
235.36 €
19.43 €
-262.12 €
-1.84 €
-5.46 €
0.63 €
250.80 €
25.62 €
21.70 €
-81.03 €
-62.96 €
-0.49 €
-152.38 €
-12.67 €
39.65 €
274.03 €
-523.73 €
0.23 €
-5.21 €
7.31 €
755.78 €
689.33 €
94.47 €
421.00 €
-662.89 €
-381.57 €
5.15 €
-44.86 €
1.46 €
293.06 €
127.66 €
240.88 €
33.55 €
2625.32 €
9.24 €
204.07 €
-69.40 €
10.62 €
-1.34 €
-1909.49 €
-147.22 €
13.43 €
202.95 €
4.20 €
-2.51 €
19.10 €
-12.17 €
-26.03 €
-3.49 €
59.69 €
-17.19 €
-13.24 €
3.01 €
0.03 €
3633.83 €
-5.16 €
-290.11 €
-2209.62 €
11.35 €
-2983.25 €
11.75 €
107.49 €
-93.16 €
-172.05 €
13.14 €
-2.83 €
-27.70 €
578.16 €
-93.73 €
736.85 €
-36.98 €
4450.10 €
28.42 €
-883.22 €
404.14 €
-11.20 €
286.25 €
1.93 €
33.46 €
8.01 €
17.26 €
9.98 €
-0.33 €
-17.66 €
-9.35 €
-0.74 €
176.41 €
-364.61 €
24.92 €
-15.06 €
-0.42 €
1.79 €
3.82 €
410.94 €
46.22 €
531.08 €
-0.51 €
358.36 €
777.18 €
-15.98 €
152.50 €
1141.59 €
3.50 €
0.97 €
9.69 €
549.92 €
188.39 €
1519.28 €
6.57 €
0.52 €
-717.88 €
-4.30 €
26.52 €
-1942.86 €
-1.53 €
19.50 €
-368.66 €
2.38 €
10.53 €
2435.23 €
104.51 €
1.29 €
-399.54 €
4.92 €
-11.41 €
40.60 €
-11.85 €
137.41 €
8.47 €
5.10 €
-3253.78 €
-16.41 €
-663.09 €
130.99 €
45.19 €
244.30 €
-13.82 €
-1.55 €
1.53 €
579.98 €
-59.41 €
1.96 €
4.09 €
252.89 €
0.48 €
0.98 €
108.37 €
17.20 €
-67.48 €
-711.08 €
12.08 €
-40.98 €
0.26 €
-206.06 €
10.06 €
38.05 €
458.72 €
39.41 €
-3.61 €
78.27 €
-0.90 €
126.88 €
1.15 €
1.69 €
-262.26 €
747.26 €
-657.02 €
-271.03 €
6.67 €
48.52 €
201.08 €
1.35 €
-5.44 €
-2.22 €
266.40 €
2894.39 €
58.13 €
-23.80 €
-314.31 €
103.50 €
-0.85 €
-37.64 €
24.56 €
-35.82 €
30.23 €
-142.13 €
-1.71 €
2.35 €
-68.65 €
66.00 €
-54.73 €
-85.78 €
-325.33 €
14.50 €
32.78 €
-4449.51 €
104.72 €
123.93 €
-0.41 €
17.05 €
-371.42 €
-1.56 €
125.63 €
1934.84 €
0.18 €
0.70 €
-228.71 €
38.58 €
3.94 €
-3.13 €
222.60 €
1.69 €
7.84 €
-4.85 €
3.67 €
-106.22 €
623.01 €
0.88 €
20.35 €
6.64 €
-86.54 €
-2.35 €
-12.71 €
0.14 €
345.45 €
-614.32 €
26.60 €
127.15 €
-17.08 €
16.59 €
-249.49 €
33.63 €
8.74 €
186.50 €
-20.36 €
-2.10 €
977.44 €
161.15 €
285.61 €
2.03 €
-10.94 €
-221.93 €
-3.55 €
-14.42 €
-718.92 €
30.07 €
6975.10 €
0.64 €
496.83 €
1.13 €
180.22 €
101.11 €
0.39 €
38.51 €
35.20 €
-3379.57 €
-3723.75 €
131.39 €
-714.39 €
-25.60 €
272.23 €
-340.31 €
-34.87 €
41.56 €
98.03 €
24.24 €
-62.79 €
7.15 €
0.42 €
1.86 €
567.37 €
1736.73 €
608.51 €
-372.28 €
-0.69 €
0.60 €
18.25 €
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
    c = string.sub(str,i,1)
    num = tonumber(c)
    if num then
      io.stderr:write("number! "..tostring(tonumber(c)).."\n")
    else
      io.stderr:write("not a num\n")
    end
  end
end

N = tonumber(io.read())
for i=0,N-1 do
    transaction = io.read()
    getFirstNumber(transaction)
end

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print("false")