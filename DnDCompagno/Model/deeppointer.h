#ifndef DEEOPOINTER_H
#define DEEOPOINTER_H

template<class T>
class DeepPointer
{
private:
    T *pted;

public:
    DeepPointer(T * = nullptr);
    DeepPointer(const DeepPointer &);
    DeepPointer &operator=(const DeepPointer &);
    T *operator->() const;
    T &operator*() const;

    ~DeepPointer();
    bool operator==(const DeepPointer &) const;
    bool operator!=(const DeepPointer &) const;
    bool operator>(const DeepPointer &) const;
    bool operator<(const DeepPointer &) const;
};

template<class T>
DeepPointer<T>::DeepPointer(T *itm) : pted(itm)
{}

template<class T>
DeepPointer<T>::DeepPointer(const DeepPointer &dptr)
{
    if (!dptr.pted)
        pted = nullptr;
    else
        pted = dptr.pted->clone();
}

template<class T>
DeepPointer<T> &DeepPointer<T>::operator=(const DeepPointer &dptr)
{
    if (this != &dptr) {
        if (pted)
            delete pted;
        pted = dptr.pted->clone();
    }
    return *this;
}

template<class T>
T *DeepPointer<T>::operator->() const
{
    return pted;
}

template<class T>
T &DeepPointer<T>::operator*() const
{
    return *pted;
}

template<class T>
DeepPointer<T>::~DeepPointer()
{
    if (pted)
        delete pted;
}

template<class T>
bool DeepPointer<T>::operator==(const DeepPointer &dptr) const
{
    return *pted == *(dptr.pted);
}

template<class T>
bool DeepPointer<T>::operator!=(const DeepPointer &dptr) const
{
    return *pted != *(dptr.pted);
}

template<class T>
bool DeepPointer<T>::operator<(const DeepPointer &dptr) const
{
    return *pted < *(dptr.pted);
}

template<class T>
bool DeepPointer<T>::operator>(const DeepPointer &dptr) const
{
    return *pted > *(dptr.pted);
}

#endif // DEEOPOINTER_H
