class FibonnaciSequence
  def take_while
    return enum_for(:take_while) unless block_given?
      Enumerator.new do |y|
        a = b = 1
        loop do
          y << a
          a, b = b, a + ba
        end
      end
    end
  end
end

list = FibonnaciSequence.take_while { |n| n < 10 }

puts list
