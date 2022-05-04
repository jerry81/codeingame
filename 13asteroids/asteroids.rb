# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w, h, t1, t2, t3 = gets.split(" ").collect { |x| x.to_i }
# w width
# h height
# t1 time 1 
# t2 time 2
# t3 time 3
# output the picture 
# store the first picture
p1 = []
p2 = []
# store the second picture 
h.times do
  first_picture_row, second_picture_row = gets.split(" ")
  p1 << first_picture_row
  p2 << second_picture_row 
end
STDERR.puts "p1 #{p1}"
STDERR.puts "p2 #{p2}"

# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

def findObjects(p)
    # step thru
    # returns map of objects and their positions
    returned = {}
    p.each_with_index do |l,idx|
        STDERR.puts "line is #{l}"
        for i in 0..l.length-1
            ch = l[i]
            if ch != '.'
                if returned[ch].nil?
                    returned[ch] = { :x => i, :y => idx}
                end
            end
        end
    end
    returned
end

def makeChangeMap(o1,o2,dt)
    # given objs1 is {"A"=>{:x=>0, :y=>0}}
    # objs2 is {"A"=>{:x=>1, :y=>0}}
    # return {"A"=> {;dx=>1 :dy=>0 }}
    returned = {}
    o1.each do |k,v|
        x1 = v[:x]
        y1 = v[:y]
        o = o2[k]
        x2 = o[:x]
        y2 = o[:y]
        returned[k] = {:dx => ((x2 - x1) / dt), :dy => ((y2 - y1) / dt) }
    end
end

objs1 = findObjects p1
objs2 = findObjects p2
dt = t2 - t1
changeMap = makeChangeMap(objs1,objs2,dt)
STDERR.puts "objs1 is #{objs1}"
STDERR.puts "objs2 is #{objs2}"
STDERR.puts "dt is #{dt}"
STDERR.puts "changemap is #{changeMap}"
puts "answer"
