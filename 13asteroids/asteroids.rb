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

def makeNewMap(o1,o2,dt,dt2, h, w)
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
        dx = ((x2 - x1) / dt.to_f) * dt2
        dy = ((y2 - y1) / dt.to_f) * dt2
        newx = dx + x2
        newy = dy + y2
        if k == 'V' 
            STDERR.puts "moving v x2 is #{x2} y2 #{y2} dx #{dx} #{dy} newx #{newx} newy #{newy}"
        end
        if newx < w && newx >= 0 && newy >= 0 && newy < h
          returned[k] = {:x => newx, :y => newy }
        end
    end
    returned
end

objs1 = findObjects p1
objs2 = findObjects p2
dt = t2 - t1
dt2 = t3 - t2
newMap = makeNewMap(objs1,objs2,dt,dt2, h, w)

def buildNewArray(newMap, h, w)
    # init array 
    ret = Array.new(h) { Array.new(w, '.') }

    newMap.each do |k,v|
        x = v[:x]
        y = v[:y]
        STDERR.puts "iterating #{x} #{y}"
        ret[v[:y]][v[:x]] = k
    end
    ret
end

STDERR.puts "objs1 is #{objs1}"
STDERR.puts "objs2 is #{objs2}"
STDERR.puts "dt is #{dt}"
STDERR.puts "d2 is #{dt2}"
STDERR.puts "changemap is #{newMap}"
newMap = newMap.sort.reverse.to_h # this sorts the hash by keys 
STDERR.puts "reverse sorted is #{newMap}"
newArr = buildNewArray(newMap, h, w)

STDERR.puts "newpict is  is #{newArr}"

newArr.each do |line|
    puts "#{line.join('')}"
end
