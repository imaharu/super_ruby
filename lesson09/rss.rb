require "rss"
#pass_url:"https://www.edsurge.com/articles_rss.rss"
#error_url:"https://qiita.com/tags/ruby/feed"
rss_url = ARGV[0]
begin
    rss = RSS::Parser.parse(rss_url)
rescue RSS::InvalidRSSError => ex
    puts "error message: " + ex.message
    rss = RSS::Parser.parse(rss_url, false)
    puts
end

rss.items.each do | item |
    begin
        puts item.title
        puts item.link
        puts item.description
        puts
    rescue StandardError => ex
        puts "error class: "+ ex.class.to_s
        puts "error message: " + ex.message
        puts "error backtrace: " + ex.backtrace.to_s
    end
    break
end
