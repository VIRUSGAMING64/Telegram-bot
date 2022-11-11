import socket as sk
cli = sk.socket()
cli.connect(('localhost',8082))
cli.send(b'holaaaa')