class Ls
    attr_reader :puts_info
    #attr_reader :directorys
    #attr_reader :files
    def initialize(option, current_path)
        @current_path = current_path
        @directorys = []
        @files = []

        Dir.children(@current_path).each { |item| @directorys << item if File.directory?(item) }
        Dir.children(@current_path).each { |item| @files << item if File.file?(item) }

        @puts_info = @directorys + @files

        exec_option(option)
    end

    def show()
        @puts_info.each do |info|
            puts "File_name: #{info} size: #{File.size(info)}"
        end
    end

    private

    def exec_option(option)
        if option.has_key?(:S)
            exec_S
        end

        if option.has_key?(:r)
            exec_r
        end
    end

    def exec_S
        @puts_info.sort! { | a, b | File.size(b) <=> File.size(a) }
    end

    def exec_r
        @puts_info.reverse!
    end

end


require 'optparse'

option = {}
OptionParser.new do |opt|
    opt.on("-r", "", "Reverse the order of the sort to get reverse
lexicographical order or the oldest entries first"  ) { |v| option[:r] = v }
    opt.on("-S", "", "Sort files by size" ) { |v| option[:S] = v }
    opt.parse!(ARGV)
end

myls = Ls.new(option, Dir.pwd)
myls.show()
