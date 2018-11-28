require 'sqlite3'
require 'csv'
## Table作成 ##
db = SQLite3::Database.new("kaken")
create_table_sql = <<-SQL
  create table nlp (
    id integer primary key,
    name text,
    type text,
    keyword text,
    organ text,
    start text,
    finish text
  );
SQL

begin
    db.execute(create_table_sql)
rescue SQLite3::SQLException
    puts "You already created kaken table"
end

## SQLiteへデータを流し込む##
CSV.foreach('data.csv', liberal_parsing: true, headers:true).each_with_index do | item, i |
    name = item["研究代表者"]
    type = item["研究種目"]
    keyword = item["キーワード"]
    organ = item["研究機関"]
    start = item["研究期間 (年度)"].split.first
    finish = item["研究期間 (年度)"].split.last
    insert_data_sql = <<-SQL
        insert into nlp values(
            ?,
            ?,
            ?,
            ?,
            ?,
            ?,
            ?
        );
    SQL
    db.execute(insert_data_sql, i + 1 , name, type, keyword, organ, start, finish)
end
db.close
