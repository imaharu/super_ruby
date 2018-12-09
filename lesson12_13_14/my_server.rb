require 'webrick'
module WEBrick::HTTPServlet
  FileHandler.add_handler('rb', CGIHandler)
end
server = WEBrick::HTTPServer.new({ :DocumentRoot => './',
                                :BindAddress => '127.0.0.1',
                                :Port => 8080})
server.mount('/api', WEBrick::HTTPServlet::CGIHandler, 'api.rb')
trap("INT"){ server.shutdown }
server.start
