#!/usr/bin/ruby

require 'matrix'

m = File.readlines('matrix.txt').map do |line|
  line.split.map(&:to_i)
end

answer = 0

(0..16).each do |x|
    (0..19).each do |y|
        product = m[x][y] * m[1+x][y] * m[2+x][y] * m[3+x][y]
        answer = product if product > answer
    end
end

(0..19).each do |x|
    (0..16).each do |y|
        product = m[x][y] * m[x][1+y] * m[x][2+y] * m[x][3+y]
        answer = product if product > answer
    end
end

(0..16).each do |x|
    (0..16).each do |y|
        product = m[x][y] * m[1+x][1+y] * m[2+x][2+y] * m[3+x][3+y]
        answer = product if product > answer
    end
end

(0..16).each do |x|
    (0..16).each do |y|
        product = m[3+x][y] * m[2+x][1+y] * m[1+x][2+y] * m[x][3+y]
        answer = product if product > answer
    end
end

puts answer
