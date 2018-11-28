require 'json'
puts "Content-Type: application/json\n"
puts "\n"
puts JSON.generate({"foo" => "bar"})
