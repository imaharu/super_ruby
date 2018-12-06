#!/usr/bin/env ruby
require 'webrick/cgi'
require 'json'
require 'sqlite3'

class YesCGI < WEBrick::CGI
  def do_GET(req, res)
    res['content-type'] = "application/json"
    name = req.query['name']
    if name.nil?
        res.body = 1
    else
        res.body = name
    end
  end
end
YesCGI.new.start()
