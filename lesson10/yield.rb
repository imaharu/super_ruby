def cheak_yield
    yield
end
cheak_yield { puts "pass check_yield" }

def check_yield_argvs
    yield(1)
end

puts check_yield_argvs { | x | x + 2 }