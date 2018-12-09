#!/usr/bin/env ruby
require 'webrick/cgi'
require 'sqlite3'
require 'json'
class YesCGI < WEBrick::CGI
  def do_GET(req, res)
    res['content-type'] = "application/json"
    type = req.query['type']
    if type.nil?
      result = get_json
      res.body = result
    else
      result = get_json_with_type(type)
      res.body = result
    end
  end

  def get_json
    db = SQLite3::Database.new("kaken")
    db.results_as_hash = true

    json_data = []
    db.execute('select * from nlp') do |row|
      remove_extra_column = Hash[*row.to_a.shift(row.length / 2 ).flatten!]
      json_data << JSON.dump(remove_extra_column)
    end
    db.close
    json_data.join(",")
  end

  def get_json_with_type(type)
    db = SQLite3::Database.new("kaken")
    db.results_as_hash = true

    json_data = []
    sql = "select * from nlp where type like '%#{type}%'"
    db.execute(sql) do |row|
      remove_extra_column = Hash[*row.to_a.shift(row.length / 2 ).flatten!]
      json_data << JSON.dump(remove_extra_column)
    end
    db.close
    json_data.join(",")
  end

end

YesCGI.new.start()
