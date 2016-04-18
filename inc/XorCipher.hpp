#ifndef XORCIPHER_HPP_
# define XORCIPHER_HPP_

# include <string>

class XorCipher {
private:
    std::string			str;
    std::string			firstStr;
    int					key;
public:
    XorCipher (std::string &);
    virtual ~XorCipher ();
    void				uncipher();
    const std::string	&getString() const;
    void				setString(std::string);
    const std::string	&getOriginalString() const;
    void				setOriginalString(std::string &);
    void				resetKey();
};

#endif /* !XORCIPHER_HPP_ */
