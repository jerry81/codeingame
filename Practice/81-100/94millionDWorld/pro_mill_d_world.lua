function read_vec()
  local vec = {}
  for rep, val in io.read():gmatch("(-?[0-9]+) (-?[0-9]+)") do -- super pro
          table.insert(vec, {rep = tonumber(rep), val = tonumber(val)})
  end
  return vec
end

Vec_A, Vec_B = read_vec(), read_vec()
dot_product = 0

do
  local index_A, index_B = 1, 1
  while index_A <= #Vec_A do
          local A, B = Vec_A[index_A], Vec_B[index_B] -- pro
          local min_rep = math.min(A.rep, B.rep) -- pro
          dot_product = dot_product + A.val * B.val * min_rep
          A.rep = A.rep - min_rep
          if A.rep == 0 then index_A = index_A + 1 end -- pro
          B.rep = B.rep - min_rep
          if B.rep == 0 then index_B = index_B + 1 end
  end
end

print(dot_product)
