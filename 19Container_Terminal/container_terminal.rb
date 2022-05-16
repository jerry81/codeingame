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
end

lines.each do |l|
    outputs << solve(l)
end

outputs.each do |o|
  puts o
end


# A - one single stack

# CBACBACBACBA -> 
# CBA
# C -> pop off CBA
# CB 
# A
# C
# CBB
# A
# C
# CBB
# AA
# C
# CBBB
# AAA
# CC

# CCCBBBAAA - already stacked perfectly for us
# CCCBBB
# AAA

# BDNIDPD
# B
# DD
# NI  # D - why not straight here?

# CODINGAME
# CA
# OI
# NG
# ME


# HIBERNATE
# HBA
# IEE
# RN
# T