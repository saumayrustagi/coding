package main

import (
	"syscall"
)

func main() {
	listening_sock, err := syscall.Socket(syscall.AF_INET, syscall.SOCK_STREAM, 0)
	if err != nil {
		panic("Socket() failed")
	}

	sock_addr := syscall.SockaddrInet4{}
	sock_addr.Port = 8080
	sock_addr.Addr = [4]byte{127, 0, 0, 1}
	if syscall.Bind(listening_sock, &sock_addr) != nil {
		panic("Bind() failed")
	}

	if syscall.Listen(listening_sock, 1024) != nil {
		panic("Listen() failed")
	}

	sock, client_in, err := syscall.Accept(listening_sock)
	if err != nil {
		panic("Accept() failed")
	}

	if syscall.Close(listening_sock) != nil {
		panic("Close() failed")
	}
	listening_sock = 0

	textmsg := "Ok"
	if syscall.Sendto(sock, ([]byte)(textmsg), 0, client_in) != nil {
		panic("Send() failed")
	}

	if syscall.Close(sock) != nil {
		panic("Close() failed")
	}
	sock = 0
}
