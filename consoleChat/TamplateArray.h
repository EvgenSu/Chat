#pragma once

using namespace std;

template <typename X> class Array
{
    int _length = 0;
    X* _data = nullptr;

public:
    Array() = default;

    Array(int length)
    {
        if (length <= 0)
        {
            throw "Wrong array length";
        }

        this->_length = length;
        _data = new X[length];
    }

    ~Array()
    {
        delete[] _data;
    }

    X& operator[](int index) const
    {
        if (index < 0 || index >= _length)
        {
            throw "Out of bounds of array";
        }
        return _data[index];
    }

    int getLength() const
    {
        return _length;
    }

    void erase()
    {
        delete[] _data;

        _data = nullptr;
        _length = 0;
    }

    void reallocate(int newLength)
    {
        erase();

        if (newLength <= 0) return;

        _data = new X[newLength];
        _length = newLength;
    }

    void insertBefore(X value, int index)
    {
        if (index < 0 || index > _length)
        {
            throw "Out of bounds of array";
        }

        X* data = new X[_length + 1];

        for (auto before = 0; before < index; ++before)
        {
            data[before] = _data[before];
        }

        data[index] = value;

        for (auto after = index; after < _length; ++after)
        {
            data[after + 1] = _data[after];
        }

        delete[] _data;
        _data = data;
        ++_length;
    }

    void remove(int index)
    {
        if (index < 0 || index >= _length)
        {
            throw "Out of bounds of array";
        }

        if (_length == 1)
        {
            erase();
            return;
        }

        X* data = new X[_length - 1];

        for (auto before = 0; before < index; ++before)
        {
            data[before] = _data[before];
        }

        for (auto after = (index + 1); after < _length; ++after)
        {
            data[after - 1] = _data[after];
        }

        delete[] _data;
        _data = data;
        --_length;
    }

    void insertAtBeginning(X value)
    {
        insertBefore(value, 0);
    }

    void insertAtEnd(X value)
    {
        insertBefore(value, _length);
    }
};