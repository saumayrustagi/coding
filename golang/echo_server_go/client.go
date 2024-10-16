package main

import (
	"fmt"
	"syscall"
)

func main() {
	sock, err := syscall.Socket(syscall.AF_INET, syscall.SOCK_STREAM, 0)
	if err != nil {
		panic("Socket() failed")
	}

	sock_addr := syscall.SockaddrInet4{}
	sock_addr.Port = 8080
	sock_addr.Addr = [4]byte{127, 0, 0, 1}

	if syscall.Connect(sock, &sock_addr) != nil {
		panic("Connect() failed")
	}

	p := make([]byte, 2)
	syscall.Recvfrom(sock, p, 0)
	fmt.Printf("%q\n", p)

	if syscall.Close(sock) != nil {
		panic("Close() failed")
	}
	sock = 0
}
