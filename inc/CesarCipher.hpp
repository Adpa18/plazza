#ifndef CESAR_HPP_
# define CESAR_HPP_

# include <string>

class Cesar {
private:
    std::string			str;
    unsigned char		c;
public:
    Cesar (std::string &);
    virtual ~Cesar ();
    void				uncipher();
    const std::string	&getStr() const;
    void				setStr(std::string &);
    void				resetChar();
    bool				isEnd();
};

#endif /* !CESAR_HPP_ */
