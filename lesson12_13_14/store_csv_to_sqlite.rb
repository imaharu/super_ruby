require 'sqlite3'
require 'csv'
db = SQLite3::Database.new("kaken")

if not File.exists?("kaken")
    sql = <<-SQL
      create table nlp (
        id integer primary key,
        name text
        type text,
        keyword text,
        organ text,
        start text
        end text
      );
    SQL
    db.execute(sql)
else
    puts "You already created kaken database"
end
db.close

#csv_data = CSV.read('data.csv', 'r:BOM|UTF-8', headers: true)
CSV.foreach('data.csv', liberal_parsing: true, headers:true).each_with_index do | item, i |
    puts item["キーワード"]
    if i == 2
        break
    end
end
