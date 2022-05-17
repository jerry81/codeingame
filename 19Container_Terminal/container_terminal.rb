# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = gets.to_i
lines = []
n.times do
  line = gets.chomp
  lines << line 
end

outputs = []

# stack test
st = [0,1]
st << 5
STDERR.puts "stack should be [0,1,5] #{st}"
STDERR.puts "last is (expect 5) #{st.last}"
st.pop
st.pop 
STDERR.puts "stack should be [0] #{st}"
str="hello"
str << 'o'
# str only has push, no pop 
arr = str.split('')
arr.pop
arr.pop
STDERR.puts "arr should be hell #{arr}"
# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

def solve(l)
    arr = l.split('')
    if arr.size == 1
        return 1
    end

    as_ord = arr.map do |x| 
        x.ord 
    end
    stacks = []
    last_idx = as_ord.size - 1
    start_idx = 0
    remaining = as_ord[start_idx..]
    max_in_remaining = -1 
    max_found = true
    cur_stack = []
    idx_to_delete = []
    max_search_start = 0
    while max_found do 
      max_found = false
      STDERR.puts "remaining before is now #{remaining}"
      remaining.each_with_index do |x,i|
        if x >= max_in_remaining
          max_in_remaining = x 
          idx_to_delete << i
          max_search_start = i + 1
          max_found = true 
        end
      end
      
      cur_stack << max_in_remaining.chr
      STDERR.puts "curstack is #{cur_stack}"
      remaining = remaining[max_search_start..]
      STDERR.puts "remaining is now #{remaining}"
    end
    STDERR.puts "max is #{max_in_remaining} as ch is #{max_in_remaining.chr}"
    2
end

lines.each do |l|
    outputs << solve(l)
end

outputs.each do |o|
  puts o
end


# A - one single stack

# CBACBACBACBA -> 3
# if there is stack whose last is is equal or greater use that
# else start a new stack 
# CBA
# CBA
# CBA
# attempt consolidation
# pop smallest 


# CCCBBBAAA - already stacked perfectly for us - 1
# CCC
# BBB
# AAA


# BDNIDPD - 4
# B
# D
# NID
# PD

# CODINGAME - 4 
# C
# OD
# I
# NGA
# ME


# HIBERNATE - 4