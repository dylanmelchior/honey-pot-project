# honey-pot-project

## Overview
- This project is a simple honeypot server. It currently can only handle one connection at a time listening on port 4444. It appends to a simple log file with the client IP Address, source port, and destination port. It has room for expansion to create an elaborate honeypot server. Dependencies are as follows: 
- netinet/in.h
- arpa/inet.h
- sys/socket.h
- unistd.h
- cstring
- iostream
- fstream

- The honeypot must be ran on an Ubunutu host. This tool is not for production usage, and is merely a development/practice tool.

## Ethical Considerations and Misuse
- This tool is a defensive tool and thus misuage is unlikely. It does give a false sense of security, as 
this tool is not designed for professional use and should not be used in a production environment. It is likely it could be modified for malicious purposes, although I am unaware as to how that would be done.


## References:
- https://www.geeksforgeeks.org/cpp/socket-programming-in-cpp/
- https://www.man7.org/linux/man-pages/man2/listen.2.html
- https://www.man7.org/linux/man-pages/man2/accept.2.html
- https://www.baeldung.com/cs/socket-api-accept
- https://learn.microsoft.com/en-us/windows/win32/winsock/sockaddr-2
- https://cplusplus.com/doc/tutorial/files/
- https://stackoverflow.com/questions/5328070/how-to-convert-string-to-ip-address-and-vice-versa
- https://www.geeksforgeeks.org/cpp/opening-modes-in-standard-i-o-in-c-c-with-examples/
- Utilized Claude LLM for brainstorming project ideas and potential project expansions outside of this     assignment.
