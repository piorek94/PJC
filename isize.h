#ifndef ISIZE_H
#define ISIZE_H


class ISize
{
public:
    ISize();
    virtual ~ISize();
    virtual int getWidth()=0;
    virtual int getHeight()=0;
    virtual void setWidth(int _width)=0;
    virtual void setHeight(int _height)=0;

};

#endif // ISIZE_H
