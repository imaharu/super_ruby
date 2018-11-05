# for

for i in [1, 2, 3, 4, 5]
	for_last = i
end
puts "for #{for_last}"

# iterator
[1, 2, 3, 4, 5].each do | num |
	last = num
end
puts "iterator #{last}"
