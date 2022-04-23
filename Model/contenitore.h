#ifndef CONTENITORE
#define CONTENITORE
#include "personaggio.h"

template<class T>
class Contenitore
{
    class Nodo;

public:
    Contenitore();
    Contenitore(const Contenitore<T> &);
    Contenitore &operator=(const Contenitore &);

    void push_front(const T &);
    void remove(T &data);
    void remove(int it);

    int size() const;
    bool empty() const;
    void clear();

    class Iteratore;
    class ConstIteratore;

    Iteratore begin();
    Iteratore end();
    ConstIteratore begin() const;
    ConstIteratore end() const;

    ~Contenitore();

    class Iteratore
    {
        friend class Contenitore<T>;

    private:
        Contenitore::Nodo *Pointer;

    public:
        Iteratore(Nodo * = nullptr);
        T &operator*() const;
        T *operator->() const;
        bool operator==(const Iteratore &) const;
        bool operator!=(const Iteratore &) const;
        Iteratore &operator++();
        Iteratore operator++(int);
    };

    class ConstIteratore
    {
        friend class Contenitore<T>;

    private:
        const Contenitore::Nodo *CPointer;

    public:
        ConstIteratore(Nodo * = nullptr);
        const T &operator*() const;
        const T *operator->() const;
        bool operator==(const ConstIteratore &) const;
        bool operator!=(const ConstIteratore &) const;
        ConstIteratore &operator++();
        ConstIteratore operator++(int);
    };

private:
    class Nodo
    {
    public:
        Nodo();
        Nodo(const T &, Nodo * = nullptr);
        Nodo(const Nodo &);
        void distruggi();
        ~Nodo();

        static Nodo *clone(Nodo *);

        T Info;
        Nodo *Next;
    };
    Nodo *First;
    int Size;
};

template<class T>
Contenitore<T>::Contenitore() : First(nullptr), Size(0)
{}

template<class T>
Contenitore<T>::Contenitore(const Contenitore<T> &q)
{
    if (q.first) {
        First = Nodo::clone(q.first);
    }
}

template<class T>
Contenitore<T> &Contenitore<T>::operator=(const Contenitore<T> &q)
{
    if (this == &q) {
        delete First;
        First = Contenitore<T>::Nodo::clone(q.first);
    }
    return *this;
}

template<class T>
void Contenitore<T>::push_front(const T &x)
{
    First = new Nodo(x, First);
    Size++;
}

template<class T>
void Contenitore<T>::remove(T &data)
{
    if (empty())
        return;

    if (data == First->Info) {
        Nodo *tmp = First;
        First = First->Next;

        if (!First) {
            Size = 0;
            return;
        }
        tmp->Next = nullptr;
        delete tmp;
        Size--;

        return;
    }

    Nodo *nav = First;
    Nodo *prev = nullptr;

    while (nav && data != nav->Info) {
        prev = nav;
        nav = nav->Next;
    }

    if (nav) {
        prev->Next = nav->Next;
        nav->Next = nullptr;
        delete nav;
        Size--;
    }
}

template<class T>
void Contenitore<T>::remove(int it)
{
    Nodo *p = First, *prec = nullptr;
    for (int i = 0; i < it; i++) {
        prec = p;
        p = p->Next;
    }

    if (p) {
        if (!prec)
            First = First->Next;
        else
            prec->Next = p->Next;

        Size--;
        p->Next = nullptr;
        delete p;
    }
}

template<class T>
int Contenitore<T>::size() const
{
    return Size;
}

template<class T>
bool Contenitore<T>::empty() const
{
    return Size == 0;
}

template<class T>
void Contenitore<T>::clear()
{
    Size = 0;
    delete First;
    First = nullptr;
}

template<class T>
Contenitore<T>::~Contenitore()
{
    delete First;
}

template<class T>
typename Contenitore<T>::Iteratore Contenitore<T>::begin()
{
    return Iteratore(First);
}

template<class T>
typename Contenitore<T>::ConstIteratore Contenitore<T>::begin() const
{
    return ConstIteratore(First);
}

template<class T>
typename Contenitore<T>::Iteratore Contenitore<T>::end()
{
    return Iteratore();
}

template<class T>
typename Contenitore<T>::ConstIteratore Contenitore<T>::end() const
{
    return ConstIteratore();
}

template<class T>
Contenitore<T>::Iteratore::Iteratore(Contenitore<T>::Nodo *n) : Pointer(n)
{}

template<class T>
T &Contenitore<T>::Iteratore::operator*() const
{
    return Pointer->Info;
}

template<class T>
T *Contenitore<T>::Iteratore::operator->() const
{
    return Pointer;
}

template<class T>
typename Contenitore<T>::Iteratore &Contenitore<T>::Iteratore::operator++()
{
    if (Pointer)
        Pointer = Pointer->Next;
    return *this;
}

template<class T>
typename Contenitore<T>::Iteratore Contenitore<T>::Iteratore::operator++(int)
{
    Iteratore tmp = *this;
    if (Pointer)
        Pointer = Pointer->Next;
    return tmp;
}

template<class T>
bool Contenitore<T>::Iteratore::operator==(const Contenitore<T>::Iteratore &i) const
{
    return Pointer == i.Pointer;
}

template<class T>
bool Contenitore<T>::Iteratore::operator!=(const Contenitore<T>::Iteratore &i) const
{
    return Pointer != i.Pointer;
}

template<class T>
Contenitore<T>::ConstIteratore::ConstIteratore(Contenitore<T>::Nodo *n) : CPointer(n)
{}

template<class T>
const T &Contenitore<T>::ConstIteratore::operator*() const
{
    return CPointer->Info;
}

template<class T>
const T *Contenitore<T>::ConstIteratore::operator->() const
{
    return CPointer;
}

template<class T>
typename Contenitore<T>::ConstIteratore &Contenitore<T>::ConstIteratore::operator++()
{
    if (CPointer)
        CPointer = CPointer->next;
    return *this;
}

template<class T>
typename Contenitore<T>::ConstIteratore Contenitore<T>::ConstIteratore::operator++(int)
{
    ConstIteratore tmp = *this;
    if (CPointer)
        CPointer = CPointer->Next;
    return tmp;
}

template<class T>
bool Contenitore<T>::ConstIteratore::operator==(const Contenitore<T>::ConstIteratore &i) const
{
    return CPointer == i.CPointer;
}

template<class T>
bool Contenitore<T>::ConstIteratore::operator!=(const Contenitore<T>::ConstIteratore &i) const
{
    return CPointer != i.CPointer;
}

template<class T>
Contenitore<T>::Nodo::Nodo() : Next(nullptr)
{}

template<class T>
Contenitore<T>::Nodo::Nodo(const T &info, Contenitore::Nodo *n) : Info(info), Next(n)
{}

template<class T>
Contenitore<T>::Nodo::~Nodo()
{
    delete Next;
}

template<class T>
typename Contenitore<T>::Nodo *Contenitore<T>::Nodo::clone(Contenitore<T>::Nodo *n)
{
    if (!n)
        return nullptr;
    return new Nodo(n->Info, Nodo::clone(n->Next));
}

#endif // CONTENITORE
