class Ls

    def initialize(opt)
        if check_opt(opt)
            @opt = true
        else
            @opt = false
        end
    end
    private

    def check_opt
        
    end
end

class Ls_dir
end

class Ls_file
end

require 'optparse'
option = {
    l: false
}
OptionParser.new do |opt|
    opt.on("-l") {|v| option[:l] = v}

    opt.parse!(ARGV)
end

myls = myls.new(option)
