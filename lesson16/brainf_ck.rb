class BrainF_ck
  def initialize(code)
    @tape = []
    @pc = 0
    @c_position = 0
    @code = code
    @jump_position = analyze_jump(@code)
  end

  def exec
    chars_code = @code.chars ## 入力を一文字ずつに区切る
    while @pc < chars_code.length
      case chars_code[@pc]
      when "+"
        inc
      when "-"
        dec
      when "."
        show
      when ">"
        right
      when "<"
        left
      when "["
        jump_right
      when "]"
        jump_left
      end
      @pc += 1
    end
  end

  private
  # inc means (+)
  def inc 
    @tape[@c_position] ||= 0
    @tape[@c_position] += 1
  end

  # dec means (-)
  def dec
    @tape[@c_position] ||= 0
    @tape[@c_position] -= 1
  end

  # show means (.)
  def show
    puts @tape[@c_position].chr
  end

  # right means (>)
  def right
    @c_position += 1
  end

  # right means (<)
  def left
    @c_position -= 1
  end

  def jump_right
    if @tape[@c_position] == 0
      @pc = @jump_position[@pc]
    end
  end

  def jump_left
    if @tape[@c_position] != 0
      @pc = @jump_position[@pc]
    end
  end

  def analyze_jump(code)
    stack = []
    chars_code = code.chars ## 入力を一文字ずつに区切る
    jump_p = {}
    chars_code.each_with_index do |word, current|
      if word == "["
        left = current
        right = current
        loop do
          if code[right] == "["
            stack.push(1)
          end
          if code[right] == "]"
            stack.pop()
          end
          if stack.length == 0
            break
          end
          right += 1
        end
        jump_p[left] = right
        jump_p[right] = left
      end
    end
    jump_p
  end

end

code = ARGF.read
brainf_ck = BrainF_ck.new(code)
brainf_ck.exec
