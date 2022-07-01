

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
    shared_ptr();
    shared_ptr(T *ptr);
    ~shared_ptr();

private:
    T *m_ptr;
    ref_count *m_count;
};