#ifndef INFORMATION_HPP
# define INFORMATION_HPP

# define FIFO_PLAZZA "plazza"

# define REGEX_PHONE	"[0|+33|0033)[ ]*[1-9][ ]*([0-9][ ]*){7}[0-9]"
# define REGEX_IP		"\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b"
# define REGEX_MAIL		"[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+"

enum Information { NONE, PHONE_NUMBER, EMAIL_ADDRESS, IP_ADDRESS };

#endif /* !INFORMATION_HPP */
