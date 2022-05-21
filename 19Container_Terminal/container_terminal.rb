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
    original = as_ord[start_idx..]

    while original.size > 0
      max_in_remaining = -1 
      max_found = true
      max_i = -1
      cur_stack = []
      idx_to_delete = []
      max_search_start = 0
      while max_found do # unnecessarily introducing a flag 
        peeked = cur_stack.empty? ? -1 : cur_stack.last
        # currently the loop will add to the stack if the encountered item is greater than or equal to the found max 
        max_found = false
        # this loop should find the index of the first largest with an empty stack
        # then find the first occurence of the largest or equal to the top of the stack
       
        for i in max_search_start..last_idx do
          x = original[i]
          if peeked == -1
            if x > max_in_remaining
              max_in_remaining = x 
              max_i = i
              max_search_start = i + 1
              max_found = true 
            end
          else
            if !max_found 
              if x > max_in_remaining && x <= peeked
                idx_to_delete << i 
                max_i = i
                max_in_remaining = x 
                max_search_start = i + 1 
              end
            else 
              if x > max_in_remaining && x < peeked
                idx_to_delete << i 
                max_i = i
                max_in_remaining = x 
                max_search_start = i + 1 
              end
            end
          end
        end
        if max_found 
          cur_stack << max_in_remaining.chr
          idx_to_delete << max_i
        end
      end
      stacks << cur_stack
      STDERR.puts("about to delete #{idx_to_delete}")
      original.delete_if.with_index{|_, i| idx_to_delete.include?(i) } # it handles the resizing of array
      STDERR.puts "original is now #{original}"
      STDERR.puts "stacks is now #{stacks}"
      last_idx = original.size - 1
    end
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