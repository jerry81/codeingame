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
  sign = winner == i1 ? s1 : s2 
  {:n=>winner, :s=>sign}
end

participants = []
n.times do
  numplayer, signplayer = gets.split(" ")
  numplayer = numplayer.to_i
  participants << {:n=>numplayer, :s=>signplayer}
end

until participants.size < 2 do 
  new_participants = []
  for i in 0..(participants.size/2) - 1
    j = i * 2
    part1 = participants[j]
    part2 = participants[j+1]
    winner = play(part1[:n], part2[:n], part1[:s], part2[:s])
    new_participants << winner
    STDERR.puts "participants is #{new_participants}"
  end
  participants = new_participants
end
# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts participants.first[:n]
