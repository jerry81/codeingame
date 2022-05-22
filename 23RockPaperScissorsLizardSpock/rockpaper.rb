# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = gets.to_i
def play(i1,i2,s1,s2)
  # returns the winner 
  winner = i1 < i2 ? i1 : i2
  case s1 
  when 'R'
    case s2 
    when 'L'
      winner = i1
    when 'C'
      winner = i1
    when 'P'
      winner = i2
    when 'S'
      winner = i2
    end
  when 'P'
    case s2 
    when 'S'
      winner = i2
    when 'C'
      winner = i1
    when 'R'
      winner = i1
    when 'L'
      winner = i2
    end
  when 'C'
    case s2 
    when 'P'
      winner = i1
    when 'L'
      winner = i1
    when 'S'
      winner = i2
    when 'R'
      winner = i2
    end
  when 'L'
    case s2 
    when 'S'
      winner = i1
    when 'P'
      winner = i1
    when 'R'
      winner = i2
    when 'S'
      winner = i2
    end
  else # spock
    case s2 
    when 'C'
      winner = i1
    when 'R'
      winner = i1
    when 'L'
      winner = i2
    when 'P'
      winner = i2
    end
  end
  winner
end

STDERR.puts "expect 1 #{play(1,2,'R','C')}"
n.times do
  numplayer, signplayer = gets.split(" ")
  numplayer = numplayer.to_i
end

# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts "WHO IS THE WINNER?"
