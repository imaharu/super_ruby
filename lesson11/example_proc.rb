require "rspec"

class Person
end

describe Person do
    it "should be a instance" do
      expect{ Person.new }.to be_a(Person)
    end

    it "should be a instance" do
      expect( Person.new ).to be_a(Person)
    end
end