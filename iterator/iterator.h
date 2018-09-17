#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

template<class TItem>
class Iterator
{
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual TItem* currentItem() = 0;
        virtual bool isDone() = 0;

        virtual ~Iterator()
        {
        }
};

// pre defination
template<class TItem>
class ConcreteAggregate;

template<class TItem>
class ConcreteIterator : public Iterator<TItem>
{
    public:
        ConcreteIterator(ConcreteAggregate<TItem>* aggr) : _aggr(aggr), _cur(0)
        {
        }

        virtual void first()
        {
            this->_cur = 0;
        }

        virtual void next()
        {
            if (this->_cur < this->_aggr->getLength())
            {
                this->_cur++;
            }
        }
        virtual TItem* currentItem()
        {
            return this->_cur < this->_aggr->getLength() ? &(*this->_aggr)[this->_cur] : nullptr;
        }

        virtual bool isDone()
        {
            return this->_cur >= this->_aggr->getLength();
        }

    private:
        ConcreteAggregate<TItem>* _aggr;
        int _cur;
};

template<class TItem>
class Aggregate
{
    public:
        virtual Iterator<TItem>* createIterator() = 0;

        virtual ~Aggregate()
        {
        }
};

template<class TItem>
class ConcreteAggregate : public Aggregate<TItem>
{
    public:
        ConcreteAggregate()
        {
            // these are private data inside of Aggregate class.
            this->_data.push_back(1);
            this->_data.push_back(3);
            this->_data.push_back(7);
            this->_data.push_back(2);
            this->_data.push_back(4);
        }

        virtual Iterator<TItem>* createIterator()
        {
            return new ConcreteIterator<TItem>(this);
        }

        TItem &operator[](int index)
        {
            return this->_data[index];
        }

        int getLength()
        {
            return this->_data.size();
        }

      private:
        std::vector<TItem> _data;
};

#endif