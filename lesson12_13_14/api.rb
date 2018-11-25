require 'json'
puts "Content-Type: application/json\n"
puts "\n"
puts 123
puts JSON.generate({"foo" => "bar"})
