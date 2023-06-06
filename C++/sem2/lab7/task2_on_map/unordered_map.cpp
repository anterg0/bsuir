#include <forward_list>
#include <functional>
#include <iterator>
template<typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class HashTable
{
private:
    using Entry = std::pair<const KeyType, ValueType>;
    using Bucket = std::forward_list<Entry>;
    static const size_t DEFAULT_SIZE = 10;
    Hash hash;
    size_t size;
    std::vector<Bucket> buckets;
    size_t getBucketIndex(const KeyType& key) const
    {
        return hash(key) % buckets.size();
    }
    typename Bucket::iterator findEntry( Bucket& bucket, const KeyType& key) const
    {
        return std::find_if(bucket.begin(), bucket.end(), [&key]( Entry& entry) {return entry.first == key;});
    }
public:
    const std::vector<Bucket>& getBuckets() const
    {
        return buckets;
    }
    explicit HashTable(size_t initialSize = DEFAULT_SIZE) : size(0)
    {
        buckets.resize(initialSize);
    }
    bool contains(const KeyType& key) const
    {
        size_t index = getBucketIndex(key);
        const Bucket& bucket = buckets[index];
        for (const auto& entry : bucket)
        {
            if (entry.first == key)
            {
                return true;
            }
        }
        return false;
    }
    ValueType& operator[](const KeyType& key)
    {
        size_t index = getBucketIndex(key);
        Bucket& bucket = buckets[index];
        typename Bucket::iterator it = findEntry(bucket, key);
        if(it != bucket.end())
        {
            return it->second;
        }
        else
        {
            bucket.emplace_front(key, ValueType());
            ++size;
            if(size > buckets.size())
            {
                rehash();
                index = getBucketIndex(key);
            }
            return bucket.front().second;
        }
    }
    ValueType operator[](const KeyType& key) const
    {
        size_t index = getBucketIndex(key);
        const Bucket & bucket = buckets[index];
        typename Bucket::const_iterator it = findEntry(bucket, key);
        if(it != bucket.end())
        {
            return it->second;
        }
        else
        {
            return ValueType();
        }
    }
    void insert(const KeyType& key, const ValueType& value)
    {
        size_t index = getBucketIndex(key);
        Bucket& bucket = buckets[index];
        typename Bucket::iterator it = findEntry(bucket, key);
        if(it != bucket.end())
        {
            it->second = value;
        }
        else
        {
            bucket.emplace_front(key, value);
            ++size;
            if(size > buckets.size())
            {
                rehash();
            }
        }
    }
    void erase(const KeyType& key)
    {
        size_t index = getBucketIndex(key);
        Bucket& bucket = buckets[index];
        typename Bucket::iterator prevIt = bucket.before_begin();
        typename Bucket::iterator it = findEntry(bucket, key);
        if (it != bucket.end())
        {
            while (std::next(prevIt) != it)
            {
                ++prevIt;
            }
            bucket.erase_after(prevIt);
            --size;
        }
    }
    void clear()
    {
        for(Bucket& bucket : buckets)
        {
            bucket.clear();
        }
        size = 0;
    }
    void rehash()
    {
        size_t newSize = buckets.size() * 2;
        std::vector<Bucket> newBuckets(newSize);
        for(const Bucket& bucket : buckets)
        {
            for(const Entry& entry : bucket)
            {
                size_t index = hash(entry.first) % newSize;
                newBuckets[index].emplace_front(entry);
            }
        }
        buckets = std::move(newBuckets);
    }
};
