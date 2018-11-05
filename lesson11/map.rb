puts %w["Ruby", "Python", "PHP"].map { |str| str.length }

puts %w["Ruby", "Python", "PHP"].map(&:length)
