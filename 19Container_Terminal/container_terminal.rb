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
    STDERR.puts "processing #{l}"
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
    original = as_ord[start_idx..]

    while original.size > 0
      max_found = true
      cur_stack = []
      idx_to_delete = []
      max_search_start = 0
      max_i = -1
      c_max_i = - 1
      loop do # build a stack
        # currently the loop will add to the stack if the encountered item is greater than or equal to the found max 
        # this loop should find the index of the first largest with an empty stack - done i think?
        # then find the first occurence of the largest or equal to the top of the stack
        sl = original[max_search_start..]
        if sl.empty? 
          break
        end
        max_in_slice = sl.max 
        max_i = sl.find_index(max_in_slice)
        cur_stack << max_in_slice
        idx_to_delete << max_i+max_search_start
        max_search_start = max_i+max_search_start+1
      end
      stacks << cur_stack
      original = original.delete_if.with_index{|_, i| idx_to_delete.include?(i) } # it handles the resizing of array
      last_idx = original.size - 1
    end
    STDERR.puts "stacks is #{stacks}"
    stacks.size
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