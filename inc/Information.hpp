#ifndef INFORMATION_HPP
# define INFORMATION_HPP

# define FIFO_PLAZZA "plazza"

# define REGEX_PHONE	"0[1-9]\\ ?[0-9]{2}\\ ?[0-9]{2}\\ ?[0-9]{2}\\ ?[0-9]{2}"
# define REGEX_IP		"([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])"
# define REGEX_MAIL		"[A-Z0-9a-z\\._\\-]+\\@[A-Za-z0-9\\.\\-]+\\.[A-Za-z]{2,}"

enum Information { NONE, PHONE_NUMBER, EMAIL_ADDRESS, IP_ADDRESS };

#endif /* !INFORMATION_HPP */
