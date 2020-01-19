import http.server
import socketserver

ROUTES = [('/api/retrieve')]

class Handler(http.server.SimpleHTTPRequestHandler):
    def do_POST(self):
        body = self.rfile.read(int(self.headers['Content-Length']))
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(body)
        return

print('Server listening on port 80...')
httpd = socketserver.TCPServer(('', 80), Handler)
httpd.serve_forever()