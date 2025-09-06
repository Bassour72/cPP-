#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__
class Fixed
{
private:
    /* data */
    int _integer;
    static int const _staticConstantInteger;
public:
    Fixed(/* args */);
    Fixed(Fixed &fixed);
    void  operator=(Fixed &fixed) ;
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed();
};

#endif /* __FIXED_H__ */