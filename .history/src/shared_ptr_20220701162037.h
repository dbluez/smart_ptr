

class ref_count
{
public:
    int use_count() { return m_count; }
    void inc_ref() { ++m_count; }
    void dec_ref() { --m_count; }

private:
    int m_count = {1};
};

template <typename T>
class shared_ptr
{
public:
    shared_ptr() = default;

    explicit shared_ptr(T *ptr)
        : m_ptr(ptr)
    {
        if (ptr)
        {
            m_count = new ref_count();
        }
    }

    shared_ptr(const shared_ptr &rhs)
        : m_ptr(rhs.m_ptr)
    {
    }
    shared_ptr(shared_ptr &&rhs);

    ~shared_ptr();

    shared_ptr &operator=(const shared_ptr &rhs);
    shared_ptr &operator=(shared_ptr &&rhs);

    operator bool()
    {
        return static_cast<bool>(m_ptr);
    }

    T &
    operator*()
    {
        return *m_ptr;
    }

    T *operator->()
    {
        return m_ptr;
    }

    bool unique()
    {
        return 1 == *use_count;
    }

    T *get()
    {
        return m_ptr;
    }

    int use_count()
    {
        return *m_count;
    }

    T *release()
    {
    }

    void reset(T *ptr);

    void swap(shared_ptr &rhs);

private:
    T *m_ptr = {nullptr};
    ref_count *m_count = {nullptr};
};